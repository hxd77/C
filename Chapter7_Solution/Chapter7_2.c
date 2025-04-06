//exp7_2:求方程ax^2+bx+c=0的根
#include<stdio.h>
#include<math.h>
float x1,x2,disc,p,q;
void greater_than_zero(float a,float b);
void equal_than_zero(float a,float b);
void smaller_than_zero(float a,float b);
int main()
{
    float a,b,c;
    printf("input a,b,c:");
    scanf("%f,%f,%f",&a,&b,&c);
    printf("equation: %5.3f*x*x+%5.2f*x+%5.2f=0\n",a,b,c);
    disc=b*b-4*a*c;
    printf("root:\n");
    if(disc>0)
    {
        greater_than_zero(a,b);
        printf("x1=%f\tx2=%f\n",x1,x2);
    }
    if(disc==0)
    {
        equal_than_zero(a,b);
        printf("x1=%f\tx2=%f\n",x1,x2);

    }
    if(disc<0)
    {
        smaller_than_zero(a,b);
        printf("x1=%f\tx2=%f\n",x1,x2);
    }
    return 0;
}

void greater_than_zero(float a,float b)
{
    x1=(-b+sqrt(disc))/(2*a);
    x2=(-b-sqrt(disc))/(2*a);
}
void equal_than_zero(float a,float b)
{
    x1=x2=-b/2*a;
}
void smaller_than_zero(float a,float b)
{
    p=-b/(2*a);
    q=sqrt(-disc)/(2*a);
}