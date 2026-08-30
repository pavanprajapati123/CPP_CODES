// 2091 Minimum Deletions to Remove Minimum and Maximum
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumDeletions(vector<int>& nums)
    {
        int n = nums.size();

        int mn = 0;
        int mx = 0;

        // Find index of minimum and maximum
        for(int i = 1; i < n; i++)
        {
            if(nums[i] < nums[mn])
                mn = i;

            if(nums[i] > nums[mx])
                mx = i;
        }

        int left = min(mn, mx);
        int right = max(mn, mx);

        // Delete both from left
        int option1 = right + 1;

        // Delete both from right
        int option2 = n - left;

        // Delete minimum from left
        // and maximum from right
        int option3 = left + 1 + n - right;

        return min({option1, option2, option3});
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

    cout << "Minimum Deletions = "
         << obj.minimumDeletions(nums);

    return 0;
}