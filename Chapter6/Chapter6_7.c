//exp6_7:输出一个菱形图
#include<stdio.h>
int main()
{
    char diamond[5][5]={{' ',' ','*'},{' ','*',' ','*'},{'*',' ',' ',' ','*'},{' ','*',' ','*'},{' ',' ','*'}};
    int i,j;
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            printf("%c",diamond[i][j]);
        }
        printf("\n");
    }
    return 0;
}