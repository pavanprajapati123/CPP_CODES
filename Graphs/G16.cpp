#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int numberOfCells(int r, int c, int u, int d,
                      vector<vector<char>>& mat) {

        int n = mat.size();
        int m = mat[0].size();

        if (mat[r][c] == '#')
            return 0;

        const int INF = 1000000000;

        vector<vector<int>> dist(n, vector<int>(m, INF));

        deque<pair<int, int>> dq;

        dist[r][c] = 0;
        dq.push_front(make_pair(r, c));

        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        while (!dq.empty()) {

            pair<int, int> cur = dq.front();
            dq.pop_front();

            int x = cur.first;
            int y = cur.second;

            for (int k = 0; k < 4; k++) {

                int nx = x + dr[k];
                int ny = y + dc[k];

                if (nx < 0 || nx >= n ||
                    ny < 0 || ny >= m)
                    continue;

                if (mat[nx][ny] == '#')
                    continue;

                int cost;

                if (nx < x)
                    cost = 1;
                else
                    cost = 0;

                if (dist[nx][ny] >
                    dist[x][y] + cost) {

                    dist[nx][ny] =
                        dist[x][y] + cost;

                    if (cost == 0)
                        dq.push_front(make_pair(nx, ny));
                    else
                        dq.push_back(make_pair(nx, ny));
                }
            }
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {

            for (int j = 0; j < m; j++) {

                if (dist[i][j] == INF)
                    continue;

                int up = dist[i][j];

                int down = up + (i - r);

                if (up <= u &&
                    down <= d &&
                    down >= 0) {

                    ans++;
                }
            }
        }

        return ans;
    }
};

int main()
{
    int n, m;
    int r, c, u, d;

    cin >> n >> m;
    cin >> r >> c >> u >> d;

    vector<vector<char>> mat(n, vector<char>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
        }
    }

    Solution obj;

    cout << obj.numberOfCells(r, c, u, d, mat);

    return 0;
}