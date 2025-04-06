//exp5_7:求\sum_{k=1}^100 k+\sum_{k=1}^50 k^2 +\sum_{k=1}^{10}1/k
#include<stdio.h>
int main()
{
    int n1=100,n2=50,n3=10;
    double k,s1=0,s2=3,s3=0;
    for(k=1;k<=n1;k++)
    {
        s1+=k;
    }
    for(k=1;k<=n2;k++)
    {
        s2+=k*k;
    }
    for(k=1;k<=n3;k++)
    {
        s3+=1/k;
    }
    printf("sum=%15.6f\n",s1+s2+s3);
    return 0;
}