//2. Write a program to Implement Heap Sort.
#include <iostream>
using namespace std;

// Function to heapify a subtree rooted at index i in array of size n
void Heapify(int arr[], int i, int n) {
    int largest = i;
    int left = 2 * i + 1;   // left child
    int right = 2 * i + 2;  // right child

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        Heapify(arr, largest, n);
    }
}

// Function to build a Max Heap
void BuildMaxHeap(int arr[], int n) {
    // Index of last non-leaf node
    for (int i = n / 2 - 1; i >= 0; i--) {
        Heapify(arr, i, n);
    }
}

// Main function to perform Heap Sort
void HeapSort(int arr[], int n) {
    BuildMaxHeap(arr, n);

    // One by one extract elements from heap
    for (int i = n - 1; i >= 1; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        Heapify(arr, 0, i);
    }
}

// Function to print the array
void PrintArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

// Main driver code
int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array:\n";
    PrintArray(arr, n);

    HeapSort(arr, n);

    cout << "Sorted array:\n";
    PrintArray(arr, n);

    return 0;
}
