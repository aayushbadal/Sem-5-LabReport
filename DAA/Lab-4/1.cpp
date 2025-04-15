//LAB-4: Implementation of Divide and Conquer Algorithms (part 1)
//1. Write a program to implement Binary Search.

#include<iostream>
using namespace std;

int binarysearch(int arr[], int low, int high, int target){
    if(low > high)
        return -1;
    int mid = (low+high)/2;
    if(arr[mid] = target)
        return mid;
    else if(arr[mid] > target)
        return binarysearch(arr, low, mid-1, target);
    else
        return binarysearch(arr, mid+1, high, target);
}

int main(){
    int arr[10], n, target;
    cout << "Enter the number of items in array:";
    cin >> n;
    cout << "Enter the sorted array:";
    for(int i=0; i<n; i++)
        cin >> arr[i];
    cout << "Enter the target to be found:";
    cin >> target;
    int low = 0, high = n;
    cout << "The target " << target << " is at index " << binarysearch(arr, low, high, target) << ".";
    return 0;
}