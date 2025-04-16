//LAB-6: Implementation of Order Statistics
//1. Write a program to implement Order Statistics ( use quick sort )
#include <iostream>
using namespace std;

// Partition function (similar to QuickSort)
int Partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Choose last element as pivot
    int i = low;            // Pointer for the smaller element

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[high]);  // Move pivot to its correct position
    return i;                // Return pivot index
}

// QuickSelect function to find the k-th smallest element
int QuickSelect(int arr[], int low, int high, int k) {
    if (low <= high) {
        int pivotIndex = Partition(arr, low, high);

        // Pivot is the k-th smallest
        if (pivotIndex == k - 1)
            return arr[pivotIndex];

        // If k-th is on the left
        if (pivotIndex > k - 1)
            return QuickSelect(arr, low, pivotIndex - 1, k);

        // If k-th is on the right
        return QuickSelect(arr, pivotIndex + 1, high, k);
    }
    return -1; // Error case
}

int main() {
    int arr[] = {12, 3, 5, 7, 4, 19, 26};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k;
    cout << "Enter the value of k (1 to " << n << "): ";
    cin >> k;

    if (k < 1 || k > n) {
        cout << "Invalid input! k must be between 1 and " << n << "." << endl;
        return 1;
    }

    int result = QuickSelect(arr, 0, n - 1, k);

    if (result != -1)
        cout << "The " << k << "-th smallest element is: " << result << endl;
    else
        cout << "Invalid input!" << endl;

    return 0;
}
