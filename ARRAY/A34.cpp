// 1089. Duplicate Zeros
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size();
        vector<int> temp;

        for (int i = 0; i < n; i++) {
            if (arr[i] == 0) {
                temp.push_back(0);
                temp.push_back(0);
            } else {
                temp.push_back(arr[i]);
            }
        }

        for (int i = 0; i < n; i++) {
            arr[i] = temp[i];
        }
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

    obj.duplicateZeros(arr);

    cout << "Array after duplicate zeros: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}