#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {

        int totalSum = 0;
        for (int num : nums)
            totalSum += num;

        int leftSum = 0;
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {
            int rightSum = totalSum - leftSum - nums[i];

            ans.push_back(abs(leftSum - rightSum));

            leftSum += nums[i];
        }

        return ans;
    }
};

int main() {
    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution obj;
    vector<int> result = obj.leftRightDifference(nums);

    cout << "Output: ";
    for (int x : result) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}