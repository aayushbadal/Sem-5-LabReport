//2.Write a c program to implement verum cipher.
#include<stdio.h>
#include<string.h>
int main(){
    char pt[100],ct[100],key[100],mkey[100];
    int i;
    printf("Enter plaintext:");
    scanf("%s",&pt);
    printf("Enter key:");
    scanf("%s",&key);
    if(strlen(key)<strlen(pt)){
        strcpy(mkey,key);
        while(strlen(mkey)<strlen(pt)){
            strcat(mkey, key);
        }
    }
    printf("\n--------Encryption----------\n");
    printf("PlainText:%s\nKey:%s\n",pt,key);
    for(i=0;i<strlen(pt);i++){
        ct[i]=(((pt[i]-97)+(mkey[i]-97))%26)+97;
    }
    printf("Ciphertext:%s\n",ct);

    printf("\n----Decryption-----\n");
    printf("CipherText:%s\nKey:%s\n",ct,key);
    for(i=0;i<strlen(ct);i++){
        pt[i]=(((ct[i]-97)-(mkey[i]-97)+26)%26)+97;
    }
    printf("Plaintext:%s\n",pt);
    return 0;
}