// Rotate an array by d elements
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void rotateArr(vector<int>& arr, int d) {

        int n = arr.size();

        d = d % n;

        reverse(arr.begin(), arr.begin() + d);

        reverse(arr.begin() + d, arr.end());

        reverse(arr.begin(), arr.end());
    }
};

int main() {

    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int d;
    cout << "Enter number of rotations: ";
    cin >> d;

    Solution obj;
    obj.rotateArr(arr, d);

    cout << "Array after rotation: ";

    for (int num : arr) {
        cout << num << " ";
    }

    cout << endl;

    return 0;
}