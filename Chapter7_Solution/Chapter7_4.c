//exp7_4:写一个函数，使给定的一个3*3的二维整型数组转置，即行列互换
#include<stdio.h>
#define N 3
int array[N][N];
void convert(int a[][N]);
int main()
{
    int i,j;
    printf("input array:\n");
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            scanf("%d",&array[i][j]);
        }
    }
    printf("\noriginal array:\n");
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            printf("%5d ",array[i][j]);   
        }
        printf("\n");
    }
    convert(array);
    printf("\nconvert array:\n");
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            printf("%5d ",array[i][j]);   
        }
        printf("\n");
    }
    return 0;
}

void convert(int a[][N])
{
    int i,j,t;
    for(i=0;i<N;i++)
    {
        for(j=i+1;j<N;j++)
        {
            t=a[i][j];
            a[i][j]=a[j][i];
            a[j][i]=t;
        }
    }
}