#include <iostream>
#include <algorithm> // For std::sort
#include <conio.h>

using namespace std;

int main() {
    int n, key;

    // Input the size of the array
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];

    // Input the elements of the array
    cout << "Enter the elements:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Sort the array in ascending order using std::sort
    sort(arr, arr + n);

    // Print the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Input the element to search for
    cout << "Enter the element to search for: ";
    cin >> key;

    // Start Binary Search
    int low = 0, high = n - 1, mid;
    bool found = false;

    while (low <= high) {
        mid = (low + high) / 2;

        if (arr[mid] == key) {
            cout << "Element found at index " << mid << endl;
            found = true;
            break;
        } else if (arr[mid] < key) {
            low = mid + 1; // Search in the right half
        } else {
            high = mid - 1; // Search in the left half
        }
    }

    // If the element is not found
    if (!found) {
        cout << "Element not found in the array." << endl;
    }

    getch();
    return 0;
}
