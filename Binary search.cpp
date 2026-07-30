#include <iostream>
using namespace std;

int main() {
    int n, key;

    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];

    cout << "Enter elements in sorted order: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter the element to search: ";
    cin >> key;

    int low = 0;
    int high = n - 1;
    int position = -1;

    // Binary Search
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key) {
            position = mid;
            break;
        }
        else if (arr[mid] < key) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    if (position != -1)
        cout << "Element found at index " << position << endl;
    else
        cout << "Element not found." << endl;

    return 0;
}
