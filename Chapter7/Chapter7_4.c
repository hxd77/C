//exp7_4:输入两个实数，用一个函数求出它们之和
#include<stdio.h>
float add(float x,float y);
int main()
{
    float a,b,c;
    printf("Please enter a and b:");
    scanf("%f,%f",&a,&b);
    c=add(a,b);
    printf("sum is %f\n",c);
    return 0;
}   
float add(float x,float y)
{
    float z;
    z=x+y;
    return z;
}