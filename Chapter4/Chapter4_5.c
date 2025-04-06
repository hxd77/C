//exp4_5:有一跃阶函数，编一程序，输入一个x值，要求输出相应的y值
#include<stdio.h>
int main()
{
    int x,y;
    scanf("%d",&x);
    if(x<0)
    {
        y=-1;
    }
    else
    {
        if(x==0)y=0;
        else y=1;
    }
    printf("x=%d,y=%d",x,y);
    return 0;
}