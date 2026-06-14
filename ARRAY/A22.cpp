#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {

        if (nums.size() < 3)
            return -1;

        vector<int> temp = {nums[0], nums[1], nums[2]};

        sort(temp.begin(), temp.end());

        return temp[1];
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

    int result = obj.findNonMinOrMax(nums);

    cout << "Result = " << result << endl;

    return 0;
}