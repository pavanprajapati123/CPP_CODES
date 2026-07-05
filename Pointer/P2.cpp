//977. Squares of a Sorted Array
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums)
    {
        int n = nums.size();

        vector<int> ans(n);

        int left = 0;
        int right = n - 1;
        int pos = n - 1;

        while(left <= right)
        {
            if(abs(nums[left]) > abs(nums[right]))
            {
                ans[pos] = nums[left] * nums[left];
                left++;
            }
            else
            {
                ans[pos] = nums[right] * nums[right];
                right--;
            }

            pos--;
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
        cin >> nums[i];

    Solution obj;

    vector<int> ans = obj.sortedSquares(nums);

    cout << "Sorted Squares: ";

    for(int x : ans)
        cout << x << " ";

    return 0;
}