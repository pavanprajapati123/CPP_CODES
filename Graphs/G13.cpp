//shortest path in 1-2 graph
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    int shortestPath(int V, int src, int dest, vector<vector<int>> &edges)
    {
        int total = V;

        vector<vector<int>> adj(V + edges.size() + 5);

        for(auto &e : edges)
        {
            int u = e[0];
            int v = e[1];
            int w = e[2];

            if(w == 1)
            {
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
            else
            {
                int dummy = total++;

                adj[u].push_back(dummy);
                adj[dummy].push_back(u);

                adj[dummy].push_back(v);
                adj[v].push_back(dummy);
            }
        }

        vector<int> dist(total, -1);

        queue<int> q;

        q.push(src);
        dist[src] = 0;

        while(!q.empty())
        {
            int node = q.front();
            q.pop();

            for(int nxt : adj[node])
            {
                if(dist[nxt] == -1)
                {
                    dist[nxt] = dist[node] + 1;
                    q.push(nxt);
                }
            }
        }

        return dist[dest];
    }
};

int main()
{
    int V, E;

    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<int>> edges(E, vector<int>(3));

    cout << "Enter edges (u v w):\n";

    for(int i = 0; i < E; i++)
    {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    int src, dest;

    cout << "Enter source and destination: ";
    cin >> src >> dest;

    Solution obj;

    cout << "Shortest Path = "
         << obj.shortestPath(V, src, dest, edges);

    return 0;
}