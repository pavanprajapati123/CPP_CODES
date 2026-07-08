// Towers reaching both stations
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    int n, m;

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    void dfs(int i, int j,
             vector<vector<int>>& mat,
             vector<vector<int>>& vis)
    {
        vis[i][j] = 1;

        for(int k = 0; k < 4; k++)
        {
            int ni = i + dx[k];
            int nj = j + dy[k];

            if(ni >= 0 && nj >= 0 &&
               ni < n && nj < m &&
               !vis[ni][nj] &&
               mat[ni][nj] >= mat[i][j])
            {
                dfs(ni, nj, mat, vis);
            }
        }
    }

    int countCoordinates(vector<vector<int>>& mat)
    {
        n = mat.size();
        m = mat[0].size();

        vector<vector<int>> P(n, vector<int>(m, 0));
        vector<vector<int>> Q(n, vector<int>(m, 0));

        // Station P
        for(int i = 0; i < n; i++)
            dfs(i, 0, mat, P);

        for(int j = 0; j < m; j++)
            dfs(0, j, mat, P);

        // Station Q
        for(int i = 0; i < n; i++)
            dfs(i, m - 1, mat, Q);

        for(int j = 0; j < m; j++)
            dfs(n - 1, j, mat, Q);

        int ans = 0;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(P[i][j] && Q[i][j])
                    ans++;
            }
        }

        return ans;
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

    Solution obj;

    cout << "Count of Coordinates = "
         << obj.countCoordinates(mat);

    return 0;
}