//exp5_12:猴子吃桃问题
#include<stdio.h>
int main()
{
    int day,x1,x2;
    day=9;
    x2=1;
    while(day>0)
    {
        x1=(x2+1)*2;        //第一天的桃子是第二天的桃子+1的2倍
        x2=x1;
        day--;
    }
    printf("total=%d\n",x1);
    return 0;
}