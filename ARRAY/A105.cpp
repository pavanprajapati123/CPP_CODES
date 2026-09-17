//1477 – Find Two Non-overlapping Sub-arrays Each With Target Sum 
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool uniformArray(vector<int>& nums1)
    {
        int mn = INT_MAX;

        // Find minimum odd element
        for (int x : nums1)
        {
            if (x % 2 == 1)
            {
                mn = min(mn, x);
            }
        }

        // Check every even element
        for (int x : nums1)
        {
            if (x % 2 == 0 && mn != INT_MAX && x < mn)
            {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    Solution obj;

    vector<int> nums1 = {3, 6, 8, 5};

    if (obj.uniformArray(nums1))
        cout << "true";
    else
        cout << "false";

    return 0;
}