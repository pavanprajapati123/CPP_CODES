//1872 Stone Game VIII
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int stoneGameVIII(vector<int>& stones)
    {
        int n = stones.size();

        vector<int> prefix(n);

        prefix[0] = stones[0];

        for(int i = 1; i < n; i++)
        {
            prefix[i] = prefix[i - 1] + stones[i];
        }

        int dp = prefix[n - 1];

        for(int i = n - 2; i >= 1; i--)
        {
            dp = max(dp, prefix[i] - dp);
        }

        return dp;
    }
};

int main()
{
    int n;

    cout << "Enter number of stones: ";
    cin >> n;

    vector<int> stones(n);

    cout << "Enter stones: ";

    for(int i = 0; i < n; i++)
    {
        cin >> stones[i];
    }

    Solution obj;

    cout << "Maximum Score Difference = "
         << obj.stoneGameVIII(stones);

    return 0;
}