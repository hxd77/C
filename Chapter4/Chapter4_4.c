//exp4_4:����һ���ַ����ж����Ƿ�Ϊ��д��ĸ������ǣ�����ת����Сд��ĸ��������ǣ���ת����Ȼ��������õ����ַ�
#include<stdio.h>
int main()
{
    char ch;
    scanf("%c",&ch);
    ch=(ch>='A'||ch<='Z')?ch+32:ch;
    printf("%c",ch);
    return 0;
}