//exp6_3:求一个3*3的整型矩阵对角线元素之和
#include<stdio.h>
int main()
{
    int i,j,a[3][3],sum=0;
    printf("enter data:\n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for(i=0;i<3;i++)
    {
        sum+=a[i][i];
    }
    printf("sum=%6d",sum);
    return 0;
}