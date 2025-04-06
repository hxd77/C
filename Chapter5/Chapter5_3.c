//exp5_3:while和do...while循环的比较
//(1)用while循环
// #include<stdio.h>
// int main()
// {
//     int i,sum=0;
//     printf("please enter i,i=?");
//     scanf("%d",&i);
//     while (i<=10)
//     {
//         sum+=i;
//         i++;
//     }
//     printf("sum=%d\n",sum);
//     return 0;
    
// }
//(2)用do-while循环
#include<stdio.h>
int main()
{
    int i,sum=0;
    printf("please enter i,i=?");
    scanf("%d",&i);
    do
    {
        sum+=i;
        i++;
    }while(i<=10);
    printf("sum=%d\n",sum);
    return 0;
}