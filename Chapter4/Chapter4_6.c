//exp4_6:要求按照考试成绩的等级输出百分制分数段，A等为85分以上，B等为70~84分，C等为60~69分，D等为60分以下
#include<stdio.h>
int main()
{
    char grade;
    scanf("%c",&grade);
    printf("Your score:");
    switch(grade)
    {
        case 'A':printf("85~100\n");break;
        case 'B':printf("70~84\n");break;
        case 'C':printf("60~74\n");break;
        case 'D':printf("<60\n");break;
        default:printf("enter data erroe!\n");
    }
    return 0;
}