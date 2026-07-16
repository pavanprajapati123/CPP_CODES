// count ways to reach all vertices from source in a directed graph
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:

    const int MOD = 1000000007;

    long long countWays(int V, int E, int S, vector<vector<int>> &edges)
    {
        vector<vector<int>> adj(V + 1);
        vector<int> indegree(V + 1, 0);

        for(auto &e : edges)
        {
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            indegree[v]++;
        }

        // Topological Sort
        queue<int> q;

        for(int i = 1; i <= V; i++)
        {
            if(indegree[i] == 0)
                q.push(i);
        }

        vector<int> topo;

        while(!q.empty())
        {
            int node = q.front();
            q.pop();

            topo.push_back(node);

            for(int nxt : adj[node])
            {
                indegree[nxt]--;

                if(indegree[nxt] == 0)
                    q.push(nxt);
            }
        }

        vector<long long> dp(V + 1, 0);

        dp[S] = 1;

        for(int node : topo)
        {
            for(int nxt : adj[node])
            {
                dp[nxt] = (dp[nxt] + dp[node]) % MOD;
            }
        }

        long long ans = 0;

        for(int i = 1; i <= V; i++)
        {
            ans = (ans + dp[i]) % MOD;
        }

        return ans;
    }
};

int main()
{
    int V, E, S;

    cout << "Enter vertices, edges and source: ";
    cin >> V >> E >> S;

    vector<vector<int>> edges(E, vector<int>(2));

    cout << "Enter directed edges:\n";

    for(int i = 0; i < E; i++)
    {
        cin >> edges[i][0] >> edges[i][1];
    }

    Solution obj;

    cout << "Total Ways = "
         << obj.countWays(V, E, S, edges);

    return 0;
}