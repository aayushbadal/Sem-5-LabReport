//1b. Modify 1a and calculate the value of PI and % error for different iterations.

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define SEED 35791246
#define PI 3.14159

int main(){
    int N[100];
    double x,y;
    int i,n=0,ch=0,r=0,p;
    double z;
    double pi, error;
    do{
    printf("Enter the number of iterations used to estimate pi:");
    scanf("%d",&N[r]);
    printf("\nEnter 0 if you want to continue with next iteration and 1 if you want to exit program:");
    scanf("%d",&ch);
    if(ch==0)
        r++;
    
    }while(ch!=1);
    printf("|No. of iteration\t|Estimate of pi\t|percent of error\t|\n");
    for(p=0;p<=r;p++){
    srand(SEED);
    n=0;
    for(i=0; i<N[p];i++){
        x=(double) rand() / RAND_MAX;
        y=(double) rand()/RAND_MAX;
        z=x*x+y*y;
        if(z<=1)
            n++;
    }
    pi=(double)n/N[p]*4;
    error= fabs((PI - pi)/ PI)*100;
    printf("| %d\t\t\t| %g\t\t| %.3f\t\t\t|\n",N[p],pi,error);

    }
    
    return 0;
}