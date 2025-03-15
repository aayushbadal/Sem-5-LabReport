//1.Implement euclidean algorithm to find gcd of two numbers iteratively.
#include<iostream>
using namespace std;
int gcd(int a, int b){
    if(a==0)
        return b;
    if(b==0)
        return a;
    while(b!=0){
        int temp=b;
        b=a%b;
        a=temp;
    }
    return a;
}
int main(){
    int a,b;
    cout<<"Enter two numbers to find GCD of:",
    cin >> a >> b;
    cout<<"The gcd of " <<a <<" and " <<b  <<" is :" <<gcd(a,b);
    return 0;
}