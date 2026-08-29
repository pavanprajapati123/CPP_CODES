//2948 Lexicographically Smallest Array by Swapping
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> lexicographicallySmallestArray(
        vector<int>& nums, int limit)
    {
        int n = nums.size();

        vector<pair<int, int>> a;

        // Store value and original index
        for(int i = 0; i < n; i++)
        {
            a.push_back({nums[i], i});
        }

        // Sort by value
        sort(a.begin(), a.end());

        int start = 0;

        while(start < n)
        {
            int end = start;

            // Create a group of values
            // whose consecutive difference <= limit
            while(end + 1 < n &&
                  a[end + 1].first - a[end].first <= limit)
            {
                end++;
            }

            vector<int> values;
            vector<int> indices;

            for(int i = start; i <= end; i++)
            {
                values.push_back(a[i].first);
                indices.push_back(a[i].second);
            }

            // Put smaller values at smaller indices
            sort(indices.begin(), indices.end());

            for(int i = 0; i < values.size(); i++)
            {
                nums[indices[i]] = values[i];
            }

            start = end + 1;
        }

        return nums;
    }
};

int main()
{
    int n, limit;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter array elements: ";

    for(int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    cout << "Enter limit: ";
    cin >> limit;

    Solution obj;

    vector<int> ans =
        obj.lexicographicallySmallestArray(nums, limit);

    cout << "Lexicographically Smallest Array: ";

    for(int x : ans)
    {
        cout << x << " ";
    }

    return 0;
}