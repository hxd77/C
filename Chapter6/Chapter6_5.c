//exp6_5:有一个3*4的矩阵，要求编写程序求出其中值最大的那个元素的值，以及其所在的行号和列号
#include<stdio.h>
int main()
{
    int i,j,row=0,column=0,max;
    int a[3][4]={{1,2,3,4},{9,8,7,6},{-10,10,-5,2}};
    max=a[0][0];
    for(i=0;i<3;i++)
    {
        for(j=0;j<4;j++)
        {
            if(a[i][j]>max) 
            {
                max=a[i][j];
                row=i;
                column=j;
            }
        }
    }
    printf("max=%d\nrow=%d\ncolumn=%d",max,i,j);
    return 0;
}