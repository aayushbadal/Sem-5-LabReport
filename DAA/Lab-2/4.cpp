//4.Write a program to implement sequential search.
#include<iostream>
using namespace std;
int sequentialsearch(int arr[],int n,int target){
    for(int i=1;i<n;i++){
        if(arr[i]==target)
            return i;
    }
    return -1;
}

int main(){
    int arr[10],n,target,result;
    cout<<"Enter number of elements in array:";
    cin>>n;
    cout<<"Enter array:\n";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<"Enter the target  to be found:";
    cin>>target;
    result=sequentialsearch(arr,n,target);
    if(result==-1)
        cout<<"The target is not in the array:";
    else
        cout<<"The target "<<target<<" found at index "<<result<<".";
    return 0;
}