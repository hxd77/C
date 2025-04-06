//exp7_8:Hanoi塔问题
#include<stdio.h>
void hanoi(int n,char one,char two,char three);
void move(char x,char y);

int main()
{
    int m;
    printf("input the number of disks:");
    scanf("%d",&m);
    printf("The step to move %d disks:\n",m);
    hanoi(m,'A','B','C');
}

void hanoi(int n,char one,char two,char three)
{
    if(n==1)move(one,three);
    else
    {
        hanoi(n-1,one,three,two);
        move(one,three);
        hanoi(n-1,two,three,one);
    }
}
void move(char x,char y)
{
    printf("%c->%c\n",x,y);
}


