//3876 – Construct Uniform Parity Array II
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool uniformArray(vector<int>& nums1)
    {
        int mn = INT_MAX;

        // Find the minimum odd number
        for(int x : nums1)
        {
            if(x % 2 == 1)
            {
                mn = min(mn, x);
            }
        }

        // Check every even number
        for(int x : nums1)
        {
            if(x % 2 == 0 && mn != INT_MAX && x < mn)
            {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums1(n);

    cout << "Enter array elements: ";

    for(int i = 0; i < n; i++)
    {
        cin >> nums1[i];
    }

    Solution obj;

    if(obj.uniformArray(nums1))
        cout << "true";
    else
        cout << "false";

    return 0;
}