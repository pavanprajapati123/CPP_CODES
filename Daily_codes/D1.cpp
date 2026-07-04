//2492 minimum score of a path between two cities
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {

        vector<vector<pair<int, int>>> adj(n + 1);

        for(auto &e : roads)
        {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

        queue<int> q;
        vector<int> vis(n + 1, 0);

        q.push(1);
        vis[1] = 1;

        int ans = INT_MAX;

        while(!q.empty())
        {
            int node = q.front();
            q.pop();

            for(auto &it : adj[node])
            {
                ans = min(ans, it.second);

                if(!vis[it.first])
                {
                    vis[it.first] = 1;
                    q.push(it.first);
                }
            }
        }

        return ans;
    }
};

int main()
{
    int n, m;

    cout << "Enter number of cities and roads: ";
    cin >> n >> m;

    vector<vector<int>> roads(m, vector<int>(3));

    cout << "Enter roads (u v distance):\n";

    for(int i = 0; i < m; i++)
    {
        cin >> roads[i][0]
            >> roads[i][1]
            >> roads[i][2];
    }

    Solution obj;

    cout << "Minimum Score = "
         << obj.minScore(n, roads);

    return 0;
}