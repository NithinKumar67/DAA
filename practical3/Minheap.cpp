#include <iostream>
#include <vector>
using namespace std;

// Function to maintain Min Heap property
void heapify(vector<int> &heap, int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && heap[left] < heap[smallest])
        smallest = left;

    if (right < n && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != i) {
        swap(heap[i], heap[smallest]);
        heapify(heap, n, smallest);
    }
}

// Function to build Min Heap
void buildMinHeap(vector<int> &heap, int n) {
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

    buildMinHeap(heap, n);

    cout << "\n\nMin Heap: ";
    for (int i = 0; i < n; i++) {
        cout << heap[i] << " ";
    }

    cout << "\nMinimum Element: " << heap[0] << endl;

    return 0;
}
