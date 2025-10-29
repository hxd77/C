#include<stdio.h>
#include"conventional.h"

AES aes;  

void init_AES() { //AES初始化
    aes.Nk = 4;
    init_Rcon();  
}
void setPlainText(byte plain[])
{
    int i;
    for(i=0;i<16;i++)
    {
        aes.plainText[i/4].wordKey[i%4]=plain[i];
        //plainText[0] plainText[1] plainText[2] plainText[3]
        /*a0 a4 a8 a12
        a1 a5 a9 a13
        a2 a6 a10 a14
        a3 a7 a11 a15
        */
    }
}

void setCipherKey(byte key[])//设置初始密钥
{
    int i;
    for(i=0;i<16;i++)
    {
        aes.cipherKey[i]=key[i];
    }
}

void init_Rcon()
{
    int i,j;
    for(i=0;i<11;i++)
    {
        for(j=0;j<4;j++)
        {
            aes.Rcon[i].wordKey[j]=0x00;
        }
    }
    aes.Rcon[1].wordKey[0]=0x01;
    aes.Rcon[2].wordKey[0]=0x02;
    aes.Rcon[3].wordKey[0]=0x04;
    aes.Rcon[4].wordKey[0]=0x08;
    aes.Rcon[5].wordKey[0]=0x10;
    aes.Rcon[6].wordKey[0]=0x20;
    aes.Rcon[7].wordKey[0]=0x40;
    aes.Rcon[8].wordKey[0]=0x80;
    aes.Rcon[9].wordKey[0]=0x1b;
    aes.Rcon[10].wordKey[0]=0x36;
}


void keyExpansion(byte key[],word w[])
{

    int i,j;
    word temp;
    for(i=0;i<4;i++)//w[0]-w[4]
    {
        for(j=0;j<aes.Nk;j++)
        {
            w[i].wordKey[j]=key[j+4*i];
        }
    }
    i=aes.Nk;
    while(i<(11*aes.Nk))//w[1]-w[43]
    {
        temp=w[i-1];
        if(i%aes.Nk==0)//如果是4的倍数
        {   
            temp=RotWord(temp);
            temp=SubWord(temp);
            temp=WordXor(temp,aes.Rcon[i/aes.Nk]);
        }
        //不是4的倍数
        w[i]=WordXor(temp,w[i-4]);
        i++;
    }
}

word RotWord(word w)//循环左移一个字节
{
    int j;
    word temp;
    for(j=0;j<4;j++)
    {
        temp.wordKey[j]=w.wordKey[(j+1)%4];
    }
    return temp;
}

word SubWord(word w)
{
    int i;
    word temp;
    byte L,R;
    for(i=0;i<4;i++)
    {
    L=w.wordKey[i]>>4;
    R=w.wordKey[i]&0x0f;
    temp.wordKey[i]=SBox[L][R];
    }
    return temp;
}


word WordXor(word w1,word w2)
{
    int i;
    word temp;
    for(i=0;i<4;i++)
    {
        temp.wordKey[i]=w1.wordKey[i]^w2.wordKey[i];
    }
    return temp;
}



void SubByte(word plain[])//经过S盒
{
    int i,j;
    byte L,R;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            L=plain[i].wordKey[j]>>4;
            R=plain[i].wordKey[j]&0x0f;
            plain[i].wordKey[j]=SBox[L][R];
        }
    }
}



void ShiftRows(word plain[])//行移位
{
    int i,j;
    word temp[4];
    for(j=0;j<4;j++)//固定列
    {
        for(i=0;i<4;i++)
        {
            temp[i].wordKey[j]=plain[(i+j)%4].wordKey[j];
        }        
    }
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            plain[i].wordKey[j]=temp[i].wordKey[j];
        }
    }
}

void MixColumns(word plain[])//列混淆
{
    int i,j,k;
    word temp[4];
    for(j=0;j<4;j++)
    {
        for(i=0;i<4;i++)
        {
            temp[i].wordKey[j]=GFMultiplyByte(plain[i].wordKey[0],mixColumnMatrix[j][0]);
            for(k=1;k<4;k++)
            {
                temp[i].wordKey[j]^=GFMultiplyByte(plain[i].wordKey[k],mixColumnMatrix[j][k]);
            }
        }
    }
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            plain[i].wordKey[j]=temp[i].wordKey[j];
        }
    }
}

byte GFMultiplyByte(byte plain, byte times)
{
    byte temp[8];
    byte result=0x00;
    temp[0]=plain;
    int i;
    for(i=1;i<8;i++)
    {
        //乘x
        if(temp[i-1]>=0x80)//如果b7=1
        {
            temp[i]=(temp[i-1]<<1)^0x1b; //左移再与0x1b异或
        }
        else
        {
            temp[i]=temp[i-1]<<1;//如果b7=0
        }
    }
    for(i=0;i<8;i++)
    {
        int pos=(times>>i)&0x01;
        if(pos==1)
        {
            result^=temp[i];
        }
    }
    return result;
}

void AddRoundKey(word plain[],int round)//轮密钥加
{
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            plain[i].wordKey[j]^=aes.wordKeys[i+4*round].wordKey[j];
        }
    }
}

// 打印状态矩阵（4x4），格式与原 C++ 版本相似
void printState(word state[])
{
    int i, j;
    for(j = 0; j < 4; j++) {
        for(i = 0; i < 4; i++) {
            printf("0x%02x ", (unsigned)state[i].wordKey[j]);
        }
        printf("\n");
    }
}

// C 版本的加密流程（带中间状态打印，替代原 C++ 方法）
void AES_encryption_debug(word in[], word out[], word key[])
{
    int i, j, round;
    printf("\n=== Start Encryption Process ===\n\n");

    // 复制输入并打印初始状态
    printf("Initial state:\n");
    for(j = 0; j < 4; j++) {
        for(i = 0; i < 4; i++) {
            out[i].wordKey[j] = in[i].wordKey[j];
            printf("0x%02x ", (unsigned)out[i].wordKey[j]);
        }
        printf("\n");
    }

    // 初始轮密钥加
    printf("\nAfter initial AddRoundKey:\n");
    AddRoundKey(out, 0);
    printState(out);

    // 主要轮函数
    for(round = 1; round < 10; round++) {
        printf("\n==== Round %d ====\n", round);

        printf("\nAfter SubBytes:\n");
        SubByte(out);
        printState(out);

        printf("\nAfter ShiftRows:\n");
        ShiftRows(out);
        printState(out);

        printf("\nAfter MixColumns:\n");
        MixColumns(out);
        printState(out);

        printf("\nAfter AddRoundKey:\n");
        AddRoundKey(out, round);
        printState(out);
    }

    // 最后一轮（无 MixColumn）
    printf("\n==== Final ====\n");

    printf("\nSubBytes:\n");
    SubByte(out);
    printState(out);

    printf("\nShiftRows:\n");
    ShiftRows(out);
    printState(out);

    printf("\nFinal AddRoundKey:\n");
    AddRoundKey(out, 10);
    printState(out);

    printf("\n=== Encryption Finished ===\n\n");
}

void AES_Encryption(word plain[],word cipher[],word key[])
{
    int i,j,k;
    for(i=0;i<4;i++)
    {
        for(j=4;j<4;j++)
        {
            cipher[i].wordKey[j]=plain[i].wordKey[j];
        }
    }
    AddRoundKey(cipher,0);
    for(i=1;i<10;i++)
    {
        SubByte(cipher);
        ShiftRows(cipher);
        MixColumns(cipher);
        AddRoundKey(cipher,i);
    }
    //最后一轮
    SubByte(cipher);
    ShiftRows(cipher);
    AddRoundKey(cipher,10);
}