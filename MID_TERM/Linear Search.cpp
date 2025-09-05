#include <iostream>
#include <conio.h>

using namespace std;

int main() {
    int n, key, found;

    // Input the size of the array
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];

    // Input the elements of the array
    cout << "Enter the elements:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Input the key to search for
    cout << "Enter the element to search for: ";
    cin >> key;

    // Perform linear search
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            cout << "Element found at index " << i << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Element not found in the array." << endl;
    }

    getch();

    return 0;
}
