//exp7_11:有两个班级，分别有35名和30名学生，调用一个average函数，分别求这两个班的学生的平均成绩
#include<stdio.h>
float average(float array[],int n);
int main()
{
    float score1[5]={98.5,97,91.5,60,55};
    float score2[10]={67.5,89.5,99,69.5,77,89.5,76.5,54,60,99.5};
    printf("The average of class A is %6.2f\n",average(score1,5));
    printf("The average of class B is %6.2f\n",average(score2,10));
    return 0;
}

float average(float array[],int n)
{
    int i;
    float aver,sum=array[0];
    for(i=1;i<n;i++)
    {
        sum+=array[i];
    }
    aver=sum/n;
    return aver;
}