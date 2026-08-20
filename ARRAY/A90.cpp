//Result Array by Comparing Last Elements
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> resultArray(vector<int>& nums)
    {
        vector<int> arr1, arr2;

        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);

        for(int i = 2; i < nums.size(); i++)
        {
            if(arr1.back() > arr2.back())
            {
                arr1.push_back(nums[i]);
            }
            else
            {
                arr2.push_back(nums[i]);
            }
        }

        for(int x : arr2)
        {
            arr1.push_back(x);
        }

        return arr1;
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

    vector<int> ans = obj.resultArray(nums);

    cout << "Result Array: ";

    for(int x : ans)
    {
        cout << x << " ";
    }

    return 0;
}