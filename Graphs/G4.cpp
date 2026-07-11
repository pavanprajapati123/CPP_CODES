#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    int dfs(vector<vector<int>>& mat, int x, int y,
            int xd, int yd, vector<vector<int>>& vis)
    {
        int n = mat.size();
        int m = mat[0].size();

        if(x == xd && y == yd)
            return 0;

        vis[x][y] = 1;

        int ans = -1;

        for(int k = 0; k < 4; k++)
        {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if(nx >= 0 && nx < n &&
               ny >= 0 && ny < m &&
               mat[nx][ny] == 1 &&
               !vis[nx][ny])
            {
                int temp = dfs(mat, nx, ny, xd, yd, vis);

                if(temp != -1)
                    ans = max(ans, temp + 1);
            }
        }

        vis[x][y] = 0;

        return ans;
    }

    int longestPath(vector<vector<int>>& mat,
                    int xs, int ys,
                    int xd, int yd)
    {
        if(mat[xs][ys] == 0 || mat[xd][yd] == 0)
            return -1;

        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        return dfs(mat, xs, ys, xd, yd, vis);
    }
};

int main()
{
    int n, m;

    cout << "Enter rows and columns: ";
    cin >> n >> m;

    vector<vector<int>> mat(n, vector<int>(m));

    cout << "Enter matrix:\n";
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
            cin >> mat[i][j];
    }

    int xs, ys, xd, yd;

    cout << "Enter Source (x y): ";
    cin >> xs >> ys;

    cout << "Enter Destination (x y): ";
    cin >> xd >> yd;

    Solution obj;

    cout << "Longest Path = "
         << obj.longestPath(mat, xs, ys, xd, yd);

    return 0;
}