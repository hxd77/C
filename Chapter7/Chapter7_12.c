//exp7_12:用选择法对数组中10个整数按由小到大排序
#include<stdio.h>
void sort(int array[],int n);
int main()
{
    int a[10],i;
    printf("enter array:\n");
    for(i=0;i<10;i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a,10);
    printf("The sorted array:\n");
    for(i=0;i<10;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
    return 0;
}
void sort(int array[],int n)
{
    int i,j,k,t;
    for(i=0;i<n;i++)
    {
        k=i;
        for(j=i+1;j<n;j++)
        {
            if(array[j]<array[k])
            {
                k=j;
            }
        }
        t=array[k];array[k]=array[i];array[i]=t;
    }
}