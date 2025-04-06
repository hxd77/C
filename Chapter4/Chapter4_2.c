//exp4_2:输入两个实数，按由小到大的顺序输出这两个数
#include<stdio.h>
int main()
{
    float a,b,t;
    scanf("%f,%f",&a,&b);
    if(a>b)//将a和b的值互换
    {
        t=a;
        a=b;
        b=t;
         
    }
    printf("%5.2f,%5.2f\n",a,b);  
    return 0;
}