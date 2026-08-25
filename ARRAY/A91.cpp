#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minMoves(vector<int>& arr)
    {
        int n = arr.size();

        int longest = 1;

        unordered_map<int, int> dp;

        for(int x : arr)
        {
            dp[x] = dp[x - 1] + 1;

            longest = max(longest, dp[x]);
        }

        return n - longest;
    }
};

int main()
{
    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter array elements: ";

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Solution obj;

    cout << "Minimum Moves = "
         << obj.minMoves(arr);

    return 0;
}