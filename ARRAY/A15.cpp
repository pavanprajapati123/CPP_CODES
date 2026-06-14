#include <iostream>
using namespace std;

int main() {
    int arr[] = {4, 5, 6, 7, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    int low = 0;
    int high = n - 1;

    while (low < high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] > arr[high]) {
            low = mid + 1;
        }
        else if (arr[mid] < arr[high]) {
            high = mid;
        }
        else {
            high--;
        }
    }

    cout << "Minimum element is: " << arr[low] << endl;
    cout << "Index of minimum element: " << low << endl;

    return 0;
}
