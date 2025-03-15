//2.Write an iterative function to generate fibonacci sequence upto nth term.
#include<iostream>
using namespace std;
void fibonacci(int n){
    int first=0;
    int second =1;
    cout << first <<" " <<second <<" ";
    int i=3;
    while(i<=n){
        int temp=first+second;
        first=second;
        second=temp;
        cout<<temp <<" ";
        i+=1;
    }
}
int main(){
    int n;
    cout<<"Enter the nth term of fibonacci series:";
    cin>>n;
    cout<<"The fibonacci sequence is \n";
    fibonacci(n);
    return 0;
}