//exp5_11:һ�����100m�߶��������£�ÿ����غ�����ԭ�߶ȵ�һ�룬�����£��ٷ���
#include<stdio.h>
int main()
{
    double sn=100,hn=sn/2;
    for(int i=2;i<=10;i++)
    {
        sn+=2*hn;
        hn/=2;
    }
    printf("��10�����ʱ������%f��\n",sn);
    printf("��10�η���%f��\n",hn);
    return 0;
}