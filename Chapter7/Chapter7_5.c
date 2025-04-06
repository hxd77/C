//exp7_5:输出4个整数，找出其中最大的数。用函数的嵌套调用来处理
#include<stdio.h>
int max4(int a,int b,int c,int d);
int max2(int a,int b);
int main()
{
    int a,b,c,d,max;
    printf("Please enter 4 interger numbers: ");
    scanf("%d %d %d %d",&a,&b,&c,&d);
    max=max4(a,b,c,d);
    printf("max=%d\n",max);
    return 0;
}

int max4(int a,int b,int c,int d)
{
    return max2(max2(max2(a,b),c),d);
}

int max2(int a,int b)
{
    return a>b?a:b;
}