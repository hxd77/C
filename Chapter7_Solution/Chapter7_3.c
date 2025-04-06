//exp7_3:写一个判素数的函数，在主函数输入一个整数，输出是否为素数的信息
#include<stdio.h>
#include<math.h>
int prime(int n);
int main()
{
    int n;
    printf("input an integer:");
    scanf("%d",&n);
    if(prime(n))
    {
        printf("%d is a prime number.\n",n);
    }
    else
    {
        printf("%d is not a prime number.\n",n);
    }
    return 0;
}
int prime(int n)
{
    int i,k,flag=1;
    k=sqrt(n);
    for(i=2;i<=k;i++)
    {
        if(n%i==0)
        {
            flag=0;
            break;
        }
    }
    return flag;
}