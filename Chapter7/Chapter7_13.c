//exp7_13:有一个3*4的矩阵，求所有元素中的最大值
#include<stdio.h>
int max_value(int array[][4]);
int main()
{
    int a[3][4]={{1,3,5,7},{2,4,6,8},{15,17,34,12}};
    printf("Max value is %d\n",max_value(a));
    return 0;
}

int max_value(int array[][4])
{
    int i,j,max;
    for(i=0,max=array[0][0];i<3;i++)
    {
        for(j=0;j<4;j++)
        {
            if(array[i][j]>max)
                max=array[i][j];
        }
    }
    return max;
}
