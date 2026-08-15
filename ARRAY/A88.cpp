//Longest Subsequence With Non-Zero XOR
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestSubsequence(vector<int>& nums)
    {
        int xr = 0;
        bool hasNonZero = false;

        for(int x : nums)
        {
            xr ^= x;

            if(x != 0)
            {
                hasNonZero = true;
            }
        }

        // If total XOR is non-zero,
        // take the complete array
        if(xr != 0)
        {
            return nums.size();
        }

        // XOR is zero, remove one non-zero element
        if(hasNonZero)
        {
            return nums.size() - 1;
        }

        // All elements are zero
        return 0;
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

    cout << "Longest Subsequence Length = "
         << obj.longestSubsequence(nums);

    return 0;
}