#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:

    bool isCycle(int V, vector<vector<int>>& adj)
    {
        vector<bool> visited(V, false);

        for(int i = 0; i < V; i++)
        {
            if(!visited[i])
            {
                queue<pair<int,int>> q;
                q.push({i, -1});
                visited[i] = true;

                while(!q.empty())
                {
                    int node = q.front().first;
                    int parent = q.front().second;
                    q.pop();

                    for(int neighbor : adj[node])
                    {
                        if(!visited[neighbor])
                        {
                            visited[neighbor] = true;
                            q.push({neighbor, node});
                        }
                        else if(neighbor != parent)
                        {
                            return true;
                        }
                    }
                }
            }
        }

        return false;
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

    Solution obj;

    if(obj.isCycle(V, adj))
        cout << "Cycle Found";
    else
        cout << "No Cycle";

    return 0;
}