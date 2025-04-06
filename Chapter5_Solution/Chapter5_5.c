//exp5_5:求S_n=a+aa+aaa+...+aa...a之值
#include<stdio.h>
int main()
{
    int a,n,i=1,sn=0,tn=0;
    printf("a,n=");
    scanf("%d,%d",&a,&n);
    while (i<=n)
    {
        tn+=a;  //赋值后的tn为i个a组成数的值
        sn+=tn; //赋值后的sn为多项式前i项之和
        a*=10;
        i++;
    }
    printf("a+aa+aaa+...=%d\n",sn);
    return 0;
    
}