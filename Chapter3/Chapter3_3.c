//exp3_3:给定一个大写字母，用小写字母输出
#include<stdio.h>
int main()
{
    char c1,c2;          
    c1='A';             //将字母'A'的ASCII代码放到变量c1变量中
    c2=c1+32;           //得到字符'a'的ASCII代码，放到c2中
    printf("%c\n",c2);  //输出c2的值，是一个字符
    printf("%d\n",c2);  //输出c2的值，是字符'a'的ASCII代码
    return 0;
}