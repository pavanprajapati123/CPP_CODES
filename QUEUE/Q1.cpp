//kth Smallest Element in an Array
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int kthSmallest(vector<int> &arr, int k) {

        priority_queue<int> pq;   // Max Heap

        // First k elements heap me daalo
        for (int i = 0; i < k; i++) {
            pq.push(arr[i]);
        }

        // Remaining elements process karo
        for (int i = k; i < arr.size(); i++) {

            if (arr[i] < pq.top()) {
                pq.pop();
                pq.push(arr[i]);
            }
        }

        return pq.top();
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

    int k;
    cout << "Enter value of k: ";
    cin >> k;

    Solution obj;

    cout << k << "th Smallest Element = "
         << obj.kthSmallest(arr, k)
         << endl;

    return 0;
}