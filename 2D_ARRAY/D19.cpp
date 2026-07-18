// Cut Matrix
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    static const int MOD = 1000000007;

    int n, m;

    vector<vector<int>> pre;
    vector<vector<vector<int>>> dp;

    bool hasOne(int r, int c)
    {
        return pre[r][c] > 0;
    }

    int solve(int r, int c, int cuts)
    {
        if(!hasOne(r, c))
            return 0;

        if(cuts == 0)
            return 1;

        if(dp[r][c][cuts] != -1)
            return dp[r][c][cuts];

        long long ans = 0;

        // Horizontal Cuts
        for(int nr = r + 1; nr < n; nr++)
        {
            if(pre[r][c] - pre[nr][c] > 0)
            {
                ans = (ans + solve(nr, c, cuts - 1)) % MOD;
            }
        }

        // Vertical Cuts
        for(int nc = c + 1; nc < m; nc++)
        {
            if(pre[r][c] - pre[r][nc] > 0)
            {
                ans = (ans + solve(r, nc, cuts - 1)) % MOD;
            }
        }

        return dp[r][c][cuts] = ans;
    }

    int findWays(vector<vector<int>>& matrix, int k)
    {
        n = matrix.size();
        m = matrix[0].size();

        pre.assign(n + 1, vector<int>(m + 1, 0));

        // Suffix Prefix Sum
        for(int i = n - 1; i >= 0; i--)
        {
            for(int j = m - 1; j >= 0; j--)
            {
                pre[i][j] = matrix[i][j]
                          + pre[i + 1][j]
                          + pre[i][j + 1]
                          - pre[i + 1][j + 1];
            }
        }

        dp.assign(n,
                  vector<vector<int>>(m,
                  vector<int>(k, -1)));

        return solve(0, 0, k - 1);
    }
};

int main()
{
    int n, m;

    cout << "Enter rows and columns: ";
    cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(m));

    cout << "Enter matrix (0 or 1):\n";

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
    }

    int k;

    cout << "Enter number of pieces: ";
    cin >> k;

    Solution obj;

    cout << "Total Ways = "
         << obj.findWays(matrix, k);

    return 0;
}