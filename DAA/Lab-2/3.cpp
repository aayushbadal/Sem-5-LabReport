//3.Write an iterative function to calculate factorial of given number.
#include<iostream>
using namespace std;
int fact(int n){
    int result=1;
    for(int i=2;i<=n;i++){
        result*=i;
    }
    return result;
}

int main(){
    int n,result;
    cout << "Enter the number to find factorial : ";
    cin>>n;
    result=fact(n);
    cout<<"Factorial of "<<n<< " is: " <<result;
    return 0;

}