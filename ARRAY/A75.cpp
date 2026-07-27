//1464. Maximum Product of Two Elements in an Array
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxProduct(vector<int>& nums)
    {
        int ans = 0;

        int n = nums.size();

        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                ans = max(ans, (nums[i] - 1) * (nums[j] - 1));
            }
        }

        return ans;
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

    cout << "Maximum Product = " << obj.maxProduct(nums);

    return 0;
}