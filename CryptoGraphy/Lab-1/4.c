//3.Write a c program to implement hill cipher with key is 3*3.
#include<stdio.h>
#include<string.h>
#include<math.h>
int inverse(int a){
    a=a%26;
    for(int x=1;x<26;x++){
        if((a*x)%26 ==1)
            return x;
    }
    return -1;
}
int keymod(int a){
    if(a<0)
        return (26+a);
}
int main(){
    char pt[20],ct[20];
    int k[3][3],i,j,len;
    int p1,p2,p3,c1,c2,c3;
    int det, detinv,adj[3][3],keyinvs[3][3];
    printf("Enter plaintext:");
    scanf("%s",&pt);
    printf("Enter key:");
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            scanf("%d",&k[i][j]);
        }
    }
    //Encryption:
    printf("Encrypted:");
    len=strlen(pt);
    if(len%3 !=0){
        strcat(pt,"x");
        len++;
    }
    for(i=0;i<len;i+=3){
        p1=pt[i]-97;
        p2=pt[i+1]-97;
        p3=pt[i+2]-97;

        c1=(k[0][0]*p1 + k[0][1]*p2 + k[0][2]*p3)%26;
        c2=(k[1][0]*p1 + k[1][1]*p2 + k[1][2]*p3)%26;
        c3=(k[2][0]*p1 + k[2][1]*p2 + k[2][2]*p3)%26;
        printf("%c%c%c",c1+65, c2+65, c3+65);
        ct[i]=c1+65;
        ct[i+1]=c2+65;
        ct[i+2]=c3+65;
    }
    ct[i]='\0';

    //decryption:
    printf("\nDecrypted:");
    det=((k[0][0]*((k[1][1]*k[2][2])-(k[2][1]*k[1][2])))-(k[0][1]*((k[1][0]*k[2][2])-(k[2][0]*k[1][2])))+(k[0][2]*((k[1][0]*k[2][1])-(k[2][0]*k[1][1]))))%26;
    detinv=inverse(det);

    //adjoint of key:
    adj[0][0]=((k[1][1]*k[2][2])-(k[2][1]*k[1][2]))%26;
    adj[0][1]=(((k[1][0]*k[2][2])-(k[2][0]*k[1][2]))*(-1))%26;
    adj[0][2]=((k[1][0]*k[2][1])-(k[2][0]*k[1][1]))%26;
    adj[1][0]=(((k[0][1]*k[2][2])-(k[2][1]*k[0][2]))*(-1))%26;
    adj[1][1]=((k[0][0]*k[2][2])-(k[0][2]*k[2][0]))%26;
    adj[1][2]=(((k[0][0]*k[2][1])-(k[2][0]*k[0][1]))*(-1))%26;
    adj[2][0]=((k[0][1]*k[1][2])-(k[1][1]*k[0][2]))%26;
    adj[2][1]=(((k[0][0]*k[1][2])-(k[1][0]*k[0][2]))*(-1))%26;
    adj[2][2]=((k[0][0]*k[1][1])-(k[1][0]*k[0][1]))%26;

    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            adj[i][j]=keymod(adj[i][j]);
        }
    }

    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            keyinvs[j][i]=keymod((detinv * adj[i][j])%26);
        }
    }


    for(i=0;i<len;i+=3){
        c1=ct[i]-65;
        c2=ct[i+1]-65;
        c3=ct[i+2]-65;

        p1=(keyinvs[0][0]*c1 + keyinvs[0][1]*c2 + keyinvs[0][2]*c3)%26;
        p2=(keyinvs[1][0]*c1 + keyinvs[1][1]*c2 + keyinvs[1][2]*c3)%26;
        p3=(keyinvs[2][0]*c1 + keyinvs[2][1]*c2 + keyinvs[2][2]*c3)%26;
        printf("%c%c%c",p1+97, p2+97, p3+97);
    }
   return 0;
}
