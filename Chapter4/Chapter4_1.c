//exp4_1:在exp3_5的基础上对程序进行改进
#include<stdio.h>
#include<math.h>
int main()
{
    double a,b,c,disc,x1,x2,p,q;        //disc用来存放判别式(b*b-4ac)的值
    scanf("%lf%lf%lf",&a,&b,&c);        //输入双精度型变量的值要用格式声明"%lf"
    disc=b*b-4*a*c;
    if(disc<0)
    {
        printf("This equation hasn't real roots\n");
    }
    else
    {
        p=-b/2*a;
        q=sqrt(disc)/(2.0*a);
        x1=p+q;x2=p-q;
        printf("x1=%7.2f\nx2=%7.2f\n",x1,x2);
    }
    return 0;

}