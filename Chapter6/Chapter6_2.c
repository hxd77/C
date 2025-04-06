//exp6_2:用数组来处理求Fibonacci数列问题
#include<stdio.h>
int main()
{
    int i;
    int f[20]={1,1};        //对前面两个元素f[0]和f[1]赋初值1
    for ( i = 2; i <20; i++)
    {
        f[i]=f[i-2]+f[i-1];
    }
    for(i=0;i<20;i++)
    {
        if(i%5==0)printf("\n");
        printf("%12d ",f[i]);
    }
    return 0;
}