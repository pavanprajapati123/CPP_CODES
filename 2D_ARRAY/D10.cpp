#include <iostream>
#include <vector>
using namespace std;

bool isPossible(vector<int>& arr, int k, int maxPages) {
    int students = 1;
    int pages = 0;

    for (int i = 0; i < arr.size(); i++) {

        if (arr[i] > maxPages)
            return false;

        if (pages + arr[i] <= maxPages) {
            pages += arr[i];
        }
        else {
            students++;
            pages = arr[i];

            if (students > k)
                return false;
        }
    }
    return true;
}

int allocateBooks(vector<int>& arr, int k) {

    if (k > arr.size())
        return -1;

    int start = arr[0];
    int end = 0;
    int result = -1;

    for (int i = 0; i < arr.size(); i++) {
        end += arr[i];
        start = max(start, arr[i]);
    }

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (isPossible(arr, k, mid)) {
            result = mid;
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }

    return result;
}

int main() {

    vector<int> arr = {10, 20, 30, 40};
    int k = 2;

    cout << allocateBooks(arr, k);

    return 0;
}