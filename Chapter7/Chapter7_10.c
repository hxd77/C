//exp7_10:有一个一维数组score，内放10个学生成绩，求平均成绩
#include<stdio.h>
float average(float array[]);
int main()
{
    float score[10],aver;
    int i;
    printf("input 10 scores:\n");
    for(i=1;i<10;i++)
    {
        scanf("%f",&score[i]);
    }
    printf("\n");
    aver=average(score);
    printf("average score is %5.2f\n",aver);
    return 0;
}

float average(float array[])//形参数组名可以不指定大小
{
    int i;
    float aver,sum=array[0];
    for(i=1;i<10;i++)
    {
        sum=sum+array[i];
    }
    aver=sum/10;
    return aver;
}