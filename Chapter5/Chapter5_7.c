//exp5_7:用公式求pi的值
#include<stdio.h>
#include<math.h>
int main()
{
    int sign=1;         //sign是用来表示数值的符号
    int count=0;
    double pi=0.0,n=1.0,term=1.0;   //pi开始代表当前多项式的值，最后代表pi的值，n代表分母，term代表当前项的值
    while(fabs(term)>=1e-6)
    {
        pi+=term;       //把当前项term累加到pi中
        n+=2;           //n+2是下一项的坟墓
        sign=-sign;     //sign代表符号
        term=sign/n;    //求出下一项的值term
        count++;
    }
    pi=pi*4;            //多项式的和pi乘以4，才是pi的值
    printf("pi=%10.8f\n",pi);
    printf("count=%d\n",count);
    return 0;
}