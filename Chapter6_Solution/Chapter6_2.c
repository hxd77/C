//exp6_2:用选择法对10个整数排序
#include<stdio.h>
int main()
{
    int i,j,min,temp,a[10];
    printf("enter data:\n");
    for(i=1;i<=10;i++)
    {
        printf("a[%d]=",i);
        scanf("%d",&a[i]);
    }
    printf("\n");
    printf("The original numbers:\n");
    for(i=1;i<=10;i++)
    {
        printf("%5d",a[i]);
    }
    printf("\n");
    for(i=1;i<=9;i++)    //一共需要n-1趟
    {
        min=i;
        for(j=i+1;j<10;j++)
        {
            if(a[j]<a[min])
            {
                min=j;
            }
        }
        temp=a[i];a[i]=a[min];a[min]=temp;
    }
    printf("\nThe sorted numbers:\n");
    for(i=1;i<10;i++)
    {
        printf("%5d",a[i]);
    }
    printf("\n");
    return 0;
}