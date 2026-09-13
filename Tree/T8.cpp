// Problem: Party town
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    pair<int, int> bfs(int start, vector<vector<int>>& adj)
    {
        int n = adj.size();

        vector<int> dist(n + 1, -1);
        queue<int> q;

        q.push(start);
        dist[start] = 0;

        int farNode = start;

        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            if (dist[u] > dist[farNode])
            {
                farNode = u;
            }

            // House u is stored at adj[u - 1]
            for (int v : adj[u - 1])
            {
                if (dist[v] == -1)
                {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }

        return {farNode, dist[farNode]};
    }

    int partyHouse(vector<vector<int>>& adj)
    {
        // First BFS: find one end of diameter
        pair<int, int> p1 = bfs(1, adj);

        // Second BFS: find diameter length
        pair<int, int> p2 = bfs(p1.first, adj);

        int diameter = p2.second;

        // Radius = ceil(diameter / 2)
        return (diameter + 1) / 2;
    }
};

int main()
{
    Solution obj;

    // Example:
    // 1 -- 2 -- 3 -- 4
    //          |
    //          5

    vector<vector<int>> adj = {
        {2},       // House 1
        {1, 3},    // House 2
        {2, 4, 5}, // House 3
        {3},       // House 4
        {3}        // House 5
    };

    cout << obj.partyHouse(adj);

    return 0;
}