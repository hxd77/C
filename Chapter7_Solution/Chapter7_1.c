//exp7_1:写两个函数，分别求两个整数的最大公约数和最小公倍数
#include<stdio.h>
int hcd(int u,int v);
int lcd(int u,int v,int h);
int main()
{
    int u,v,h,l;
    scanf("%d,%d",&u,&v);
    h=hcd(u,v);
    l=lcd(u,v,h);
    printf("H.C.D=%d\n",h);
    printf("L.C.D=%d\n",l);
    return 0;
}
int hcd(int u,int v)
{
    int temp;
    if(u<v)
    {
        temp=u;
        u=v;
        v=temp;
    }
    while (v!=0)
    {
        temp=u%v;
        u=v;
        v=temp;
    }
    /*
    while((temp=u%v)!=0)
    {
        temp=u;
        u=v;
        v=temp;
    }
    return v;*/
    return u;
}

int lcd(int u,int v,int h)
{
    return u*v/h;
}