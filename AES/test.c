#include"conventional.h"
#include"t_tables.h"
#include<stdio.h>

/* C 风格替换：声明在 C++ 源中可能为方法的函数原型，
    这里只给出最小的 C 风格原型以便编译（实现应在其它文件中提供或另行实现） */
int main()
{
    extern AES aes; // use the global AES instance defined in convention.c
    
    // 设置密钥
    byte key[16]={0x2b,0x7e,0x15,0x16,0x28,0xae,0xd2,0xa6,0xab,0xf7,0x15,0x88,0x09,0xcf,0x4f,0x3c};
    setCipherKey(key);
    // 初始化 AES（设置 Nk, Rcon 等）并生成轮密钥
    init_AES();
    keyExpansion(aes.cipherKey, aes.wordKeys);
    
    // 设置明文
    byte plaintext[16]={0x32,0x43,0xf6,0xa8,0x88,0x5a,0x30,0x8d,0x31,0x31,0x98,0xa2,0xe0,0x37,0x07,0x34};
    setPlainText(plaintext);
    
    // 输出轮密钥

    printf("Round Key:\n");
    for(int j=0;j<4;j++) {
        for(int i=0;i<11;i++) {//遍历行plain0 plain1 plain2 plain3 输出
            /* C 版本输出：0x + 两位十六进制，前导 0 */
            printf("0x%02x ", (unsigned)aes.wordKeys[i].wordKey[j]);
        }
        printf("\n");
    }

    
    // 输出明文矩阵（C 风格）
    printf("\nPlaintext Matrix:\n");
    for(int j=0;j<4;j++) {
        for(int i=0;i<4;i++) {
            /* 0x + 两位十六进制（小写），不足位补 0 */
            printf("0x%02x ", (unsigned)aes.plainText[i].wordKey[j]);
        }
        printf("\n");
    }

    // 执行加密（假定存在 C 风格函数实现）
    AES_Encryption(aes.plainText,aes.cipherText,aes.wordKeys);
    //AES_Encryption_Ttable(aes.plainText,aes.cipherText,aes.wordKeys);
    // 获取并输出密文

    printf("\nCiphertext Matrix:\n");
    for(int j=0;j<4;j++) {
        for(int i=0;i<4;i++) {
            printf("0x%02x ", (unsigned)aes.cipherText[i].wordKey[j]);
        }
        printf("\n");
    }
    
    return 0;
}