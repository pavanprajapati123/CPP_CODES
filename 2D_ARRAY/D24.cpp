//1140 — Stone Game II
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int n;

    vector<int> suffix;
    vector<vector<int>> dp;

    int solve(int i, int M)
    {
        if(i >= n)
            return 0;

        // Alice can take all remaining piles
        if(i + 2 * M >= n)
            return suffix[i];

        if(dp[i][M] != -1)
            return dp[i][M];

        int ans = 0;

        for(int X = 1; X <= 2 * M; X++)
        {
            int opponent = solve(i + X, max(M, X));

            ans = max(ans, suffix[i] - opponent);
        }

        return dp[i][M] = ans;
    }

    int stoneGameII(vector<int>& piles)
    {
        n = piles.size();

        suffix.assign(n + 1, 0);

        for(int i = n - 1; i >= 0; i--)
        {
            suffix[i] = piles[i] + suffix[i + 1];
        }

        dp.assign(n, vector<int>(n + 1, -1));

        return solve(0, 1);
    }
};

int main()
{
    int n;

    cout << "Enter number of piles: ";
    cin >> n;

    vector<int> piles(n);

    cout << "Enter pile values: ";

    for(int i = 0; i < n; i++)
    {
        cin >> piles[i];
    }

    Solution obj;

    cout << "Maximum Stones Alice Can Get = "
         << obj.stoneGameII(piles);

    return 0;
}