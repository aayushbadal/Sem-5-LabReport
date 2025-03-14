//1.Write a c program to implement ceaser and shift cipher.
#include<stdio.h>
#include<string.h>
char pt[100],ct[100];
int k,i;
int main(){
    printf("Enter the plaintext:");
    scanf("%s",pt);
    printf("Enter key:");
    scanf("%d",&k);

    printf("---Encryption---\n");
    printf("Plain Text : %s\nKey:%d",pt,k);
    for(i=0; i<strlen(pt); i++){
        ct[i]=(((pt[i]-97)+k)%26)+65;
    }
    printf("\nCipher Text is :%s",ct);

    printf("\n-------Decryption-------\n");
    printf("Cipher text :%s\nKey:%d",ct,k);
    for(i=0;i<strlen(pt);i++){
        pt[i]=(((ct[i]-65)-k)%26)+97;
    }
    printf("\nPlain Text is :%s",pt);
    return 0;
}