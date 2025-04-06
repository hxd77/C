//exp5_11:译密码
// #include<stdio.h>
// int main()
// {
//     char c;
//     c=getchar();        //输入一个字符给字符变量
//     while (c!='\n')     //检查c的值是否为换行符\n
//     {
//         if(c>='a'&&c<='z'||c>='A'&&c<='Z')
//         {
//             if(c>='w'&&c<='z'||c>='W'&&c<='Z') c-=22;   //如果是26个字母后的最后四个字母就使c-22
//             else c+=4;
//         }
//         printf("%c",c);
//         c=getchar();
//     }
//     printf("\n");
//     return 0;
// }
#include<stdio.h>
int main()
{
    char c;
    while ((c=getchar())!='\n')       //输入一个字符变量c并检查其值是否是换行符
    {
        if((c>='A'&&c<='Z')||(c>='a'&&c<='z'))
        {
            c+=4;
            if((c>'Z'&&c<='Z'+4)||(c>'z'))
            {
                c-=26;
            }
        }
        printf("%c",c);
    }
    printf("\n");
    return 0;
}