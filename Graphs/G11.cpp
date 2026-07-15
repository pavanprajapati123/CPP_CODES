//Dijikstra's Algorithm
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Solution {
public:

    vector<int> dijkstra(vector<vector<int>> &edge,
                         int vertices,
                         int edges,
                         int source)
    {
        vector<vector<pair<int,int>>> adj(vertices);

        for(auto &e : edge)
        {
            int u = e[0];
            int v = e[1];
            int wt = e[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        priority_queue<pair<int,int>,
                       vector<pair<int,int>>,
                       greater<pair<int,int>>> pq;

        vector<int> dist(vertices, INT_MAX);

        dist[source] = 0;

        pq.push({0, source});

        while(!pq.empty())
        {
            int dis = pq.top().first;
            int node = pq.top().second;

            pq.pop();

            for(auto it : adj[node])
            {
                int adjNode = it.first;
                int wt = it.second;

                if(dis + wt < dist[adjNode])
                {
                    dist[adjNode] = dis + wt;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        return dist;
    }
};

int main()
{
    int vertices, edges;

    cout << "Enter number of vertices and edges: ";
    cin >> vertices >> edges;

    vector<vector<int>> edge(edges, vector<int>(3));

    cout << "Enter edges (u v weight):\n";

    for(int i = 0; i < edges; i++)
    {
        cin >> edge[i][0] >> edge[i][1] >> edge[i][2];
    }

    int source;

    cout << "Enter source vertex: ";
    cin >> source;

    Solution obj;

    vector<int> dist = obj.dijkstra(edge, vertices, edges, source);

    cout << "Shortest Distance from Source:\n";

    for(int i = 0; i < vertices; i++)
    {
        cout << "Node " << i << " = " << dist[i] << endl;
    }

    return 0;
}