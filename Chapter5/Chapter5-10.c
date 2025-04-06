//exp5_10:求100~200的全部素数
#include<stdio.h>
#include<math.h>
int main()
{
    int n,k,i,m=0;
    for(n=101;n<=200;n+=2)
    {
        k=sqrt(n);
        for(i=2;i<=k;i++)
        {
            if(n%i==0)break;
        }
        if(i>=k+1)      //若i>=k+1,表示n未曾被整除
        {
            printf("%d ",n); //n是素数
            m+=1;       //m用来换行，1行输出10个素数
        }
        if(m%10==0)printf("\n");
    }
    printf("\n");
    return 0;
}