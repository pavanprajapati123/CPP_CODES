// #include <vector>
// #include <iostream>
// using namespace std;
// int longestSubarray(std::vector<int>& nums, int k) {
//     int n = nums.size();
//     int left = 0, right = 0;
//     long long sum = 0;
//     int ans = 0;

//     while (right < n) {
//         sum += nums[right];

//         while (sum > k) {
//             sum -= nums[left];
//             left++;
//         }

//         // window is valid (sum <= k)
//         ans = max(ans, right - left + 1);

//         right++;
//     }

//     return ans;
// }
// int main(){
//     vector<int>nums={2,1,1,1,3};
//     int k=3;
//     cout<<longestSubarray(nums,k);
// }
#include <vector>
#include <iostream>
#include <vector>
#include <climits>
using namespace std;
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = 0;
        int s = 0;
        int ans = INT_MAX;

        while (r < n) {
            s += nums[r];

            while (s >= target) {
                ans = min(ans, r - l + 1);
                s -= nums[l];
                l++;
            }
            r++;
        }

        return ans == INT_MAX ? 0 : ans;
    }
};
int main() {
    Solution sol;
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    int target = 7;
    cout << sol.minSubArrayLen(target, nums) << endl; // Output: 2
    return 0;
}
