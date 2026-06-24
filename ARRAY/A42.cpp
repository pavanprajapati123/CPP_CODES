#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isSorted(vector<int>& arr) {

        for(int i = 0; i < arr.size() - 1; i++) {

            if(arr[i] > arr[i + 1]) {
                return false;
            }
        }

        return true;
    }
};

int main() {

    vector<int> arr = {10, 20, 30, 40, 50};

    Solution obj;

    if(obj.isSorted(arr))
        cout << "Array is Sorted";
    else
        cout << "Array is Not Sorted";

    return 0;
}