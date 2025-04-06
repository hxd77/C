//exp5_6:求\sum_{n=1}^{20}n!
#include<stdio.h>
int main()
{
    double s=0,t=1;
    for(int i=1;i<=20;i++)
    {
        t*=i;
        s+=t;
    }
    printf("1!+2!+...+20! = %22.15e\n",s);
    return 0;
}