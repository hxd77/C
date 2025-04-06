//exp5_8:求Fibonacci数列的前40个数
/*#include<stdio.h>
int main()
{
    int f1=1,f2=1,f3;
    int i;
    printf("%12d\n%12d\n",f1,f2);
    for(i=1;i<=38;i++)
    {
        f3=f1+f2;
        printf("%12d\n",f3);
        f1=f2;
        f2=f3;
    }
    return 0;
}*/
#include<stdio.h>
int main(){
    int f1=1,f2=1;
    int i;
    for(i=1;i<=20;i++)
    {
        printf("%12d %12d",f1,f2);      //输出前两个月的兔子
        if(i%2==0)printf("\n");     
        f1=f1+f2;               //计算出下一个月的兔子数，并放在f1中
        f2=f1+f2;               //计算出下两个月的兔子书，并放在f2中
    }
    return 0;
}
