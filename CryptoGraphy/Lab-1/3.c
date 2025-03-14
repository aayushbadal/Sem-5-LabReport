//3.Write a c program to implement hill cipher with key is 2*2.
#include<stdio.h>
#include<string.h>
#include<math.h>
int keymod(int a){
    if(a<0)
        return (26+a);
}
int inverse(int a){
    a=a%26;
    for(int x=1;x<26;x++){
        if((a*x)%26 ==1)
            return x;
    }
    return -1;
}
int main(){
    char pt[10],ct[10];
    int k[2][2],i,j,len,p1,p2,c1,c2;
    int det,detinv,adj[2][2],keyinvs[2][2];
    //2X2 matrix:
    printf("Enter Plaintext:");
    scanf("%s",&pt);
    printf("Enter Key:");
    for(i=0;i<2;i++){
        for(j=0;j<2;j++){
            scanf("%d",&k[i][j]);
        }
    }
    //Encryption:
    printf("Encrypted:");
    len=strlen(pt);
    if(len%2 !=0){
        strcat(pt,"x");
        len++;
    }

    for(i=0;i<len;i+=2){
        p1=pt[i]-97;
        p2=pt[i+1]-97;

        c1=(k[0][0]*p1 + k[0][1]*p2)%26;
        c2=(k[1][0]*p1 + k[1][1]*p2)%26;
        printf("%c%c",c1+65, c2+65);
        ct[i]=c1+65;
        ct[i+1]=c2+65;
    }
    ct[i]='\0';
    printf("\n");
    //decryption:
    printf("Decrypted:");
    det=(k[0][0] * k[1][1])-(k[1][0]*k[0][1])%26;
    detinv=inverse(det);

    adj[0][0]=k[1][1];
    adj[1][1]=k[0][0];
    adj[0][1]=k[0][1]* (-1);
    adj[1][0]=k[1][0]* (-1);

    for(i=0;i<2;i++){
        for(j=0;j<2;j++){
            keyinvs[i][j]=keymod((detinv * adj[i][j])%26);
        }
    }
    for(i=0;i<len;i+=2){
        c1=ct[i]-65;
        c2=ct[i+1]-65;

        p1=(keyinvs[0][0]*c1 + keyinvs[0][1]*c2)%26;
        p2=(keyinvs[1][0]*c1 + keyinvs[1][1]*c2)%26;
        printf("%c%c",p1+97, p2+97);
    }
    return 0;
}