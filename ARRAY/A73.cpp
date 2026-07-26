//628. Maximum Product of Three Numbers
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maximumProduct(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());

        int n = nums.size();

        int option1 = nums[n - 1] * nums[n - 2] * nums[n - 3];

        int option2 = nums[0] * nums[1] * nums[n - 1];

        return max(option1, option2);
    }
};

int main()
{
    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter array elements: ";

    for(int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    Solution obj;

    cout << "Maximum Product = " << obj.maximumProduct(nums);

    return 0;
}