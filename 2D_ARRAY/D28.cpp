//Question: Adventure in a Maze
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findWays(vector<vector<int>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        const int MOD = 1000000007;

        vector<vector<long long>> ways(
            n, vector<long long>(m, 0)
        );

        vector<vector<int>> mx(
            n, vector<int>(m, -1)
        );

        // Destination cell
        ways[n - 1][m - 1] = 1;
        mx[n - 1][m - 1] = grid[n - 1][m - 1];

        for(int i = n - 1; i >= 0; i--)
        {
            for(int j = m - 1; j >= 0; j--)
            {
                if(i == n - 1 && j == m - 1)
                    continue;

                long long cnt = 0;
                int best = -1;

                // Move Right
                if(grid[i][j] == 1 || grid[i][j] == 3)
                {
                    if(j + 1 < m && ways[i][j + 1] > 0)
                    {
                        cnt = (cnt + ways[i][j + 1]) % MOD;
                        best = max(best, mx[i][j + 1]);
                    }
                }

                // Move Down
                if(grid[i][j] == 2 || grid[i][j] == 3)
                {
                    if(i + 1 < n && ways[i + 1][j] > 0)
                    {
                        cnt = (cnt + ways[i + 1][j]) % MOD;
                        best = max(best, mx[i + 1][j]);
                    }
                }

                if(best != -1)
                {
                    ways[i][j] = cnt;
                    mx[i][j] = grid[i][j] + best;
                }
            }
        }

        // No path
        if(ways[0][0] == 0)
            return {0, 0};

        return {
            (int)ways[0][0],
            mx[0][0]
        };
    }
};

int main()
{
    int n, m;

    cout << "Enter rows and columns: ";
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));

    cout << "Enter grid elements:\n";

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }

    Solution obj;

    vector<int> ans = obj.findWays(grid);

    cout << "Number of Ways = " << ans[0] << endl;
    cout << "Maximum Score = " << ans[1] << endl;

    return 0;
}