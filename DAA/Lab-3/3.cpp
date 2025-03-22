//3. Write a program to implement Insertion Sort.
#include<iostream>
using namespace std;

void insertionsort(int arr[],int n){
    for(int i=1;i<n;i++){
        int key=arr[i];
        int j=i-1;
        while((j>=0) && (arr[j]>key)){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
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
    insertionsort(arr,n);
    return 0;
}