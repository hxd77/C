//exp3_9:从键盘输入BOY三个字符，然后把它们输出到屏幕
#include<stdio.h>
int main()              //定义字符变量a,b,c
{
    char a,b,c;
    a=getchar();        //从键盘输入一个字符，送给字符变量a
    b=getchar();        //从键盘输入一个字符，送给字符变量b
    c=getchar();        //从键盘输入一个字符，送给字符变量c
    putchar(a);
    putchar(b);
    putchar(c);
    putchar('\n');
    return 0;
}