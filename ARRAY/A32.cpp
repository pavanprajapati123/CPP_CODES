// 941. Valid Mountain Array
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {

        int n = arr.size();
        int i = 0;

        // Increasing part
        while (i + 1 < n && arr[i] < arr[i + 1]) {
            i++;
        }

        // Peak cannot be first or last
        if (i == 0 || i == n - 1) {
            return false;
        }

        // Decreasing part
        while (i + 1 < n && arr[i] > arr[i + 1]) {
            i++;
        }

        return i == n - 1;
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

    Solution obj;

    if (obj.validMountainArray(arr))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}