//DFS Traversal of Graph
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited)
    {
        visited[node] = true;

        cout << node << " ";

        for(int neighbor : adj[node])
        {
            if(!visited[neighbor])
            {
                dfs(neighbor, adj, visited);
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

    cout << "DFS Traversal: ";

    obj.dfs(0, adj, visited);

    return 0;
}