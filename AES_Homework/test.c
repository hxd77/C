#include"conventional.h"
#include"t_tables.h"
#include<stdio.h>

int main()
{
    extern AES aes; 
    
    // 设置密钥
    byte key[16]={0x2b,0x7e,0x15,0x16,0x28,0xae,0xd2,0xa6,0xab,0xf7,0x15,0x88,0x09,0xcf,0x4f,0x3c};
    setCipherKey(key);
    // 初始化 AES
    init_AES();
    keyExpansion(aes.cipherKey, aes.wordKeys);
    
    // 设置明文
    byte plaintext[16]={0x32,0x43,0xf6,0xa8,0x88,0x5a,0x30,0x8d,0x31,0x31,0x98,0xa2,0xe0,0x37,0x07,0x34};
    setPlainText(plaintext);
    
    //AES常规实现
    printf("AES-128加密常规实现\n");
    printf("明文:\t");
    for(int j=0;j<4;j++) {
        for(int i=0;i<4;i++) {
            printf("%02x ", (unsigned)aes.plainText[i].wordKey[j]);
        }
    }
    printf("\n");
    printf("密钥:\t");
      for(int j=0;j<4;j++) {
        for(int i=0;i<4;i++) {
            printf("%02x ", (unsigned)aes.wordKeys[i].wordKey[j]);
        }
    }
    printf("\n");
    printf("-------- 执行AES实现 --------\n");
    AES_Encryption(aes.plainText,aes.cipherText,aes.wordKeys);
    printf("\n");
    printf("密文:\t");
      for(int j=0;j<4;j++) {
        for(int i=0;i<4;i++) {
            printf("%02x ", (unsigned)aes.cipherText[i].wordKey[j]);
        }
    }
    

    printf("\n\n\n");
    //T-table实现
    printf("AES-128加密查表实现\n");
    printf("明文:\t");
    for(int j=0;j<4;j++) {
        for(int i=0;i<4;i++) {
            printf("%02x ", (unsigned)aes.plainText[i].wordKey[j]);
        }
    }
    printf("\n");
    printf("密钥:\t");
      for(int j=0;j<4;j++) {
        for(int i=0;i<4;i++) {
            printf("%02x ", (unsigned)aes.wordKeys[i].wordKey[j]);
        }
    }
    printf("\n");
    printf("-------- 执行AES实现 --------\n");
    AES_Encryption_Ttable(aes.plainText,aes.cipherText,aes.wordKeys);
    printf("\n");
    printf("密文:\t");
      for(int j=0;j<4;j++) {
        for(int i=0;i<4;i++) {
            printf("%02x ", (unsigned)aes.cipherText[i].wordKey[j]);
        }
    }
    return 0;
}