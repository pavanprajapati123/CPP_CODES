//
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dominantPairs(vector<int>& arr)
    {
        int n = arr.size();
        int half = n / 2;

        vector<int> left(arr.begin(), arr.begin() + half);
        vector<int> right(arr.begin() + half, arr.end());

        sort(left.begin(), left.end());
        sort(right.begin(), right.end());

        int count = 0;

        for (int x : right)
        {
            long long val = 5LL * x;

            // First element >= 5*x
            auto it = lower_bound(left.begin(), left.end(), val);

            count += left.end() - it;
        }

        return count;
    }
};

int main()
{
    Solution obj;

    vector<int> arr = {10, 20, 30, 2, 3, 4};

    cout << obj.dominantPairs(arr);

    return 0;
}