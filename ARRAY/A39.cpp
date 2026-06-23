// 1365. How Many Numbers Are Smaller Than the Current Number
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {

        int n = nums.size();
        vector<int> ans(n, 0);

        for (int i = 0; i < n; i++) {

            int count = 0;

            for (int j = 0; j < n; j++) {

                if (nums[j] < nums[i])
                    count++;
            }

            ans[i] = count;
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

    vector<int> ans = obj.smallerNumbersThanCurrent(nums);

    cout << "Result: ";

    for (int x : ans) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}