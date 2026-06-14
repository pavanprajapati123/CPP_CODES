#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int total = 0;
        int left = 0;

        for (int x : nums) {
            total += x;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (left == total - left - nums[i]) {
                return i;
            }
            left += nums[i];
        }
        return -1;
    }
};

int main() {
    Solution s;

    vector<int> nums = {1, 7, 3, 6, 5, 6};

    int result = s.pivotIndex(nums);
    cout << "Pivot Index = " << result << endl;

    return 0;
}
