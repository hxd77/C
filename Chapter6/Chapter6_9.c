//exp6_9:有3个字符串，要求找出其中“最大”者
#include<stdio.h>
#include<string.h>
int main()
{
    char str[3][20];    //定义二维字符数组
    char string[20];    //定义一维字符数组，作为交换字符串时的临时字符数组
    int i;
    for(i=0;i<3;i++)
    {
        gets(str[i]);       //读入3个字符串，分别给str[0],str[1],str[2]
    }
    if(strcmp(str[0],str[1])>0)     //若str[0]大于str[1]
    {
        strcpy(string,str[0]);      //把str[0]的字符串赋值给字符数组string
    }
    else
        strcpy(string,str[1]);      //把str[1]的字符擦混赋值给字符数组string
    if(strcmp(str[2],string)>0)
    {
        strcpy(string,str[2]);
    }
    printf("\nthe largest string is:\n%s\n",string);
    return 0;
}
