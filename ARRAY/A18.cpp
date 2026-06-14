//3691. Maximum Total Subarray Value II....
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {

        int mx = *max_element(nums.begin(), nums.end());
        int mn = *min_element(nums.begin(), nums.end());

        return 1LL * k * (mx - mn);
    }
};

int main() {
    vector<int> nums = {1, 3, 2};
    int k = 2;

    Solution obj;
    cout << obj.maxTotalValue(nums, k) << endl;

    return 0;
}