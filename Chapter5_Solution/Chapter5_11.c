//exp5_11:一个球从100m高度自由落下，每次落地后反跳回原高度的一半，再落下，再反弹
#include<stdio.h>
int main()
{
    double sn=100,hn=sn/2;
    for(int i=2;i<=10;i++)
    {
        sn+=2*hn;
        hn/=2;
    }
    printf("第10次落地时共经过%f米\n",sn);
    printf("第10次反弹%f米\n",hn);
    return 0;
}