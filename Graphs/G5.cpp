//BFS Traversal of Graph
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:

    void bfs(int start, vector<vector<int>>& adj, vector<bool>& visited)
    {
        queue<int> q;
        q.push(start);
        visited[start] = true;

        while(!q.empty())
        {
            int node = q.front();
            q.pop();

            cout << node << " ";

            for(int neighbor : adj[node])
            {
                if(!visited[neighbor])
                {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
    }
};

int main()
{
    int V, E;

    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<int>> adj(V);

    cout << "Enter edges:\n";

    for(int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visited(V, false);

    Solution obj;

    cout << "BFS Traversal: ";

    obj.bfs(0, adj, visited);

    return 0;
}