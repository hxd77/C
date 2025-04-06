//exp5_8:输出所有的水仙花数
#include<stdio.h>
int main()
{
    int i,j,k,n;
    printf("parcissus number are ");
    for(n=100;n<1000;n++)
    {
        i=n/100;
        j=n/10%10;//或者j=n/10-i*10;
        k=n%10;
        if(i*i*i+j*j*j+k*k*k==n)
        {
            printf("%d ",n);
        }
    }
    printf("\n");
    return 0;
}