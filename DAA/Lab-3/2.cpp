//2. Write a program to implement Selection Sort.
#include<iostream>
using namespace std;

void selectionsort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int minindex=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[minindex])
                minindex=j;
        }
        int temp=arr[i];
        arr[i]=arr[minindex];
        arr[minindex]=temp;
    }
    cout<<"The sorted array is:\n";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int arr[10],n;
    cout<<"Enter number of elements:";
    cin>>n;
    cout<<"Enter array to be sorted:";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    selectionsort(arr,n);
    return 0;
}