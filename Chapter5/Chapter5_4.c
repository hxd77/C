//exp5_4:在全系1000名学生中举行慈善募捐，当总数达到10万元时就结束，统计此时捐款的人数以及平均每人捐款的数目
#include<stdio.h>
#define SUM 100000     //指定符号常量SUM代表10000
int main()
{
    float amount,aver,total;
    int i;
    for(i=1;i<=1000;i++)
    {
        printf("please enter amount:");
        scanf("%f",&amount);
        total+=amount;
        if(total>=SUM) break;
    }
    aver=total/i;
    printf("num=%d\naver=%10.2f\n",i,aver);
    return 0;
}


