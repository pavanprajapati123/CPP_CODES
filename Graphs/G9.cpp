// BFS Traversal of a graph
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:

    vector<int> bfsTraversal(int n, vector<vector<int>> &adj)
    {
        vector<int> ans;
        vector<int> vis(n, 0);

        queue<int> q;

        q.push(0);
        vis[0] = 1;

        while(!q.empty())
        {
            int node = q.front();
            q.pop();

            ans.push_back(node);

            for(int it : adj[node])
            {
                if(!vis[it])
                {
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }

        return ans;
    }
};

int main()
{
    int n, e;

    cout << "Enter number of vertices and edges: ";
    cin >> n >> e;

    vector<vector<int>> adj(n);

    cout << "Enter edges:\n";

    for(int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    Solution obj;

    vector<int> ans = obj.bfsTraversal(n, adj);

    cout << "BFS Traversal: ";

    for(int x : ans)
        cout << x << " ";

    return 0;
}