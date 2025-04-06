//exp5_10:有一个分数序列，求出这个数列的前20项之和
#include<stdio.h>
int main()
{
    int i;
    double a=2,b=1,s=0,t;
    for(i=1;i<=20;i++)
    {
        s+=a/b;
        t=a;
        a+=b;
        b=t;
    }
    printf("sum=%16.10f\n",s);
    return 0;
}