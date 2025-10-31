#include<stdio.h>
#include"t_tables.h"
#include"conventional.h"

AES aes;  
word T_table0[256],T_table1[256],T_table2[256],T_table3[256];

void Make_Ttable()
{
    int i;
    byte L,R;
    byte s,s2,s3;
    for(i=0;i<256;i++)
    {
        L=i>>4;
        R=i&0x0f;
        s=SBox[L][R];
        s2=GFMultiplyByte(s,2);
        s3=GFMultiplyByte(s,3);
        
        T_table0[i].wordKey[0]=s2;
        T_table0[i].wordKey[1]=s;
        T_table0[i].wordKey[2]=s;
        T_table0[i].wordKey[3]=s3;
        
        T_table1[i].wordKey[0]=s3;
        T_table1[i].wordKey[1]=s2;
        T_table1[i].wordKey[2]=s;
        T_table1[i].wordKey[3]=s;
        
        T_table2[i].wordKey[0]=s;
        T_table2[i].wordKey[1]=s3;
        T_table2[i].wordKey[2]=s2;
        T_table2[i].wordKey[3]=s;
        
        T_table3[i].wordKey[0]=s;
        T_table3[i].wordKey[1]=s;
        T_table3[i].wordKey[2]=s3;
        T_table3[i].wordKey[3]=s2; 
    }
}

void AES_Encryption_Ttable(word plain[],word cipher[],word key[])
{
    Make_Ttable();//生成T_tables
    int i,j,k;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            cipher[i].wordKey[j]=plain[i].wordKey[j];
        }
    }
    //第0轮，轮密钥加
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            cipher[i].wordKey[j]^=aes.wordKeys[i].wordKey[j];
        }
    }
    word temp[4];
    for(i=1;i<10;i++)
    {
        for(j=0;j<4;j++)
        {
            for(k=0;k<4;k++)
            {
                temp[j].wordKey[k]=
                T_table0[(unsigned)(cipher[j].wordKey[0])].wordKey[k]
                ^T_table1[(unsigned)(cipher[(j+1)%4].wordKey[1])].wordKey[k]
                ^T_table2[(unsigned)(cipher[(j+2)%4].wordKey[2])].wordKey[k]
                ^T_table3[(unsigned)(cipher[(j+3)%4].wordKey[3])].wordKey[k]
                ^aes.wordKeys[j+4*i].wordKey[k];
            }
        }
        for(j=0;j<4;j++)
        {
            for(k=0;k<4;k++)
            {
                cipher[j].wordKey[k]=temp[j].wordKey[k];
            }
        }
    }
    //最后一轮
    byte L,R;
    i=10;
    for(j=0;j<4;j++)
    {
        for(k=0;k<4;k++)
        {
            L=cipher[(j+k)%4].wordKey[k]>>4;
            R=cipher[(j+k)%4].wordKey[k]&0x0f;
            temp[j].wordKey[k]=SBox[L][R]^aes.wordKeys[j+i*4].wordKey[k];
        }
    }
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            cipher[i].wordKey[j]=temp[i].wordKey[j];
        }
    }
}

