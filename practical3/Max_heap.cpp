#include <iostream>
#include <vector>
using namespace std;

// Function to maintain Max Heap property
void heapify(vector<int> &heap, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && heap[left] > heap[largest])
        largest = left;

    if (right < n && heap[right] > heap[largest])
        largest = right;

    if (largest != i) {
        swap(heap[i], heap[largest]);
        heapify(heap, n, largest);
    }
}

// Function to build Max Heap
void buildMaxHeap(vector<int> &heap, int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(heap, n, i);
    }
}

int main() {
    int n;

    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> heap(n);

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> heap[i];
    }

    cout << "\nInput Array: ";
    for (int i = 0; i < n; i++) {
        cout << heap[i] << " ";
    }

    buildMaxHeap(heap, n);

    cout << "\n\nMax Heap: ";
    for (int i = 0; i < n; i++) {
        cout << heap[i] << " ";
    }

    cout << "\nMaximum Element: " << heap[0] << endl;

    return 0;
}
