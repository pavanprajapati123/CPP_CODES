#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {

        int count = 0;
        int maxi = 0;

        for (int num : nums) {
            if (num == 1) {
                count++;
                maxi = max(maxi, count);
            }
            else {
                count = 0;
            }
        }

        return maxi;
    }
};

int main() {

    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter array elements (0 or 1): ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution obj;

    cout << "Maximum Consecutive Ones = "
         << obj.findMaxConsecutiveOnes(nums)
         << endl;

    return 0;
}