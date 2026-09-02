//3875. Construct Uniform Parity Array I
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool uniformArray(vector<int>& nums1)
    {
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