//生成t_tables表
#include"conventional.h"
//byte 
byte t_table0[16][16];
byte t_table1[16][16];
byte t_table2[16][16];
byte t_table3[16][16];
void Make_Ttable(word plain[])
{
    /*
    int i,j,k;
    word temp[4];
    byte L,R;
    for(j=0;j<4;j++)
    {
        for(i=0;i<4;i++)
        {
            //先行移位
            ShiftRows(plain);
            L=plain[i].wordKey[0]>>4;
            R=plain[i].wordKey[0]&0x0F;
            plain[i].wordKey[0]=SBox[L][R];
            temp[i].wordKey[j]=GFMultiplyByte(plain[i].wordKey[j],2);
            for(k=1;k<4;k++)
            {
                
            }
        }
    }
    */
    int i,j;
    byte index=0x00;
    byte temp;
    byte result[4];
    for(i=0;i<16;i++)
    {
        for(j=0;j<16;j++)
        {
            temp=SBox[i][j];
            result[0]=GFMultiplyByte(temp,2);
            result[1]=GFMultiplyByte(temp,1);
            result[2]=GFMultiplyByte(temp,1);
            result[3]=GFMultiplyByte(temp,3);
            t_table0[i][j]=result[0];
            t_table1[i][j]=result[1];
            t_table2[i][j]=result[2];
            t_table3[i][j]=result[3];
        }
    }
}