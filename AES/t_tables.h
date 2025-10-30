//生成t_tables表
#include"conventional.h"
//byte 
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
