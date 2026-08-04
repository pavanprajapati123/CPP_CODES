//3731. Find Missing Elements
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> findMissingElements(vector<int>& nums)
    {
        unordered_set<int> st(nums.begin(), nums.end());

        int mn = *min_element(nums.begin(), nums.end());
        int mx = *max_element(nums.begin(), nums.end());

        vector<int> ans;

        for(int x = mn; x <= mx; x++)
        {
            if(st.find(x) == st.end())
            {
                ans.push_back(x);
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

    vector<int> ans = obj.findMissingElements(nums);

    if(ans.empty())
    {
        cout << "No Missing Elements";
    }
    else
    {
        cout << "Missing Elements: ";

        for(int x : ans)
        {
            cout << x << " ";
        }
    }

    return 0;
}