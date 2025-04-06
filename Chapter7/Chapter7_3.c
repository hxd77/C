//exp7_3:将exp7_2稍作改动，将在max函数中定义的变量z改为float型
#include<stdio.h>
int max(float x,float y);
int main()
{
    float a,b;
    int c;
    scanf("%f,%f",&a,&b);
    c=max(a,b);
    printf("max is %d\n",c);
    return 0;
}
int max(float x,float y)
{
    float z;
    z=x>y?x:y;
    return z;
}