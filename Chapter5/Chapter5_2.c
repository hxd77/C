//exp5_2:用do...while语句求1+2+3+...+100
#include<stdio.h>
int main()
{
    int i=1,sum=0;
    do
    {
        sum+=i;
        i++;
    }while(i<=100);
    printf("sum=%d\n",sum);
    return 0;   
}