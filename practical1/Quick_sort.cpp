#include <iostream>
using namespace std;

// Partition function
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;

            // Swap arr[i] and arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // Place pivot in correct position
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

// Quick Sort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        // Sort left part
        quickSort(arr, low, pi - 1);

        // Sort right part
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int arr[] = {18,45,93,77};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Print unsorted array
    cout << "Unsorted Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    // Quick Sort
    quickSort(arr, 0, n - 1);

    // Print sorted array
    cout << "\nSorted Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
