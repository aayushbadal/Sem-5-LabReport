//2. Write a program to Implement Merge Sort.
#include <iostream>
using namespace std;

// Merge two subarrays of arr[]
void merge(int arr[], int left, int mid, int right) {
    // Sizes of the subarrays
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    int* LeftArray = new int[n1];
    int* RightArray = new int[n2];

    // Copy data to temporary arrays
    for (int i = 0; i < n1; i++)
        LeftArray[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        RightArray[j] = arr[mid + 1 + j];

    // Merge the temporary arrays back into arr[left..right]
    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (LeftArray[i] <= RightArray[j]) {
            arr[k] = LeftArray[i];
            i++;
        } else {
            arr[k] = RightArray[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of LeftArray
    while (i < n1) {
        arr[k] = LeftArray[i];
        i++;
        k++;
    }

    // Copy remaining elements of RightArray
    while (j < n2) {
        arr[k] = RightArray[j];
        j++;
        k++;
    }

    // Free the memory
    delete[] LeftArray;
    delete[] RightArray;
}

// Merge Sort function
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

// Test the implementation
int main() {
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;

    mergeSort(arr, 0, size - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}


