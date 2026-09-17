//Min Edge Reversals for Path

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumEdgeReversal(
        vector<vector<int>>& edges,
        int n,
        int src,
        int dst)
    {
        vector<vector<pair<int, int>>> adj(n + 1);

        // Original direction = cost 0
        // Reverse direction = cost 1
        for (auto& e : edges)
        {
            int u = e[0];
            int v = e[1];

            adj[u].push_back({v, 0});
            adj[v].push_back({u, 1});
        }

        const int INF = 1e9;
        vector<int> dist(n + 1, INF);

        deque<int> dq;

        dist[src] = 0;
        dq.push_front(src);

        while (!dq.empty())
        {
            int u = dq.front();
            dq.pop_front();

            for (auto& edge : adj[u])
            {
                int v = edge.first;
                int cost = edge.second;

                if (dist[u] + cost < dist[v])
                {
                    dist[v] = dist[u] + cost;

                    if (cost == 0)
                        dq.push_front(v);
                    else
                        dq.push_back(v);
                }
            }
        }

        return dist[dst] == INF ? -1 : dist[dst];
    }
};

int main()
{
    Solution obj;

    vector<vector<int>> edges = {
        {1, 2},
        {2, 3},
        {4, 3}
    };

    int n = 4;
    int src = 1;
    int dst = 4;

    cout << obj.minimumEdgeReversal(edges, n, src, dst);

    return 0;
}