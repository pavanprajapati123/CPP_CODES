//Longest Subarray with Sum K
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& arr, int k) {

        unordered_map<long long, int> mp;

        long long sum = 0;
        int maxi = 0;

        for (int i = 0; i < arr.size(); i++) {

            sum += arr[i];

            if (sum == k) {
                maxi = i + 1;
            }

            long long rem = sum - k;

            if (mp.find(rem) != mp.end()) {
                maxi = max(maxi, i - mp[rem]);
            }

            if (mp.find(sum) == mp.end()) {
                mp[sum] = i;
            }
        }

        return maxi;
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

    cout << "Longest Subarray Length = "
         << obj.longestSubarray(arr, k)
         << endl;

    return 0;
}