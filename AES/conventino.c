#include<stdio.h>
#include"convention.h"

AES aes;
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
            aes.Rcon[i].wordKey[i]=0x00;
        }
    }
    aes.Rcon[1].wordKey[1]=0x01;
    aes.Rcon[2].wordKey[1]=0x02;
    aes.Rcon[3].wordKey[1]=0x04;
    aes.Rcon[4].wordKey[1]=0x08;
    aes.Rcon[5].wordKey[1]=0x10;
    aes.Rcon[6].wordKey[1]=0x20;
    aes.Rcon[7].wordKey[1]=0x40;
    aes.Rcon[8].wordKey[1]=0x80;
    aes.Rcon[9].wordKey[1]=0x1b;
    aes.Rcon[10].wordKey[1]=0x36;
}


void keyExpansion(byte key[],word w[])
{

    int i,j;
    word temp;
    for(i=0;i<4;i++)
    {
        w[i/4].wordKey[i%4]=key[i];
    }
    i=aes.Nk;
    while(i<44)
    {
        temp=w[i-1];
        if(i%aes.Nk==0)
        {   
            temp=RotWord(temp);
            temp=SubWord(temp);
            temp=WordXor(temp,aes.Rcon[i/aes.Nk]);
        }
        w[i]=WordXor(temp,w[i-4]);
    }
}

word RotWord(word w)
{
    int i;
    word temp;
    for(i=0;i<4;i++)
    {
        temp.wordKey[(i+3)%4]=w.wordKey[i];
    }
    return temp;
}

word SubWord(word w)
{
    int i;
    word temp;
    int L,R;
    for(i=0;i<4;i++)
    {
        L=w.wordKey[i]>>4;
        R=w.wordKey[i]&0x0f;
        temp.wordKey[i]=aes.SBox[L][R];
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



void SubByte(word plain[])
{
    int i,j;
    int L,R;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            L=plain[i].wordKey[j]>>4;
            R=plain[i].wordKey[j]&0x0f;
            plain[i].wordKey[j]=aes.SBox[L][R];
        }
    }
}



void ShiftRows(word plain[])
{
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            //
        }        
    }
}

void AES_Encryption(word plain[],word cipher[],word key[])
{
    int i,j,k;
    for(i=0;i<4;i++)
    {
        for(j=4;j<4;j++)
        {
        }
    }
}