//exp5_9:输入一个大于3的整数n，判定它是否是素数
#include<stdio.h>
int main()
{
    int n,i;
    printf("please enter a integer number,n=?");
    scanf("%d",&n);
    for(i=2;i<n;i++)//改进：k=sqrt(n);for(i=2;i<=k;i++)
    {
        if(n%i==0)
        {
            break;
        }
    }
    if (i<n)
    {
        printf("%d is not a prime number. \n",n);
    }
    else
    {
        printf("%d is a prime number. \n",n);
    }
    return 0;
}