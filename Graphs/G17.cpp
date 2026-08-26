//Detect Negative Weight Cycle
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isNegativeWeightCycle(int V,
                               vector<vector<int>>& edges)
    {
        // Initialize all distances as 0
        // so every component can be checked
        vector<int> dist(V, 0);

        // Relax all edges V - 1 times
        for(int i = 0; i < V - 1; i++)
        {
            bool changed = false;

            for(auto &e : edges)
            {
                int u = e[0];
                int v = e[1];
                int w = e[2];

                if(dist[u] + w < dist[v])
                {
                    dist[v] = dist[u] + w;
                    changed = true;
                }
            }

            if(!changed)
                break;
        }

        // One extra relaxation
        // If distance still improves,
        // negative weight cycle exists
        for(auto &e : edges)
        {
            int u = e[0];
            int v = e[1];
            int w = e[2];

            if(dist[u] + w < dist[v])
                return true;
        }

        return false;
    }
};

int main()
{
    int V, E;

    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    vector<vector<int>> edges(E,
                              vector<int>(3));

    cout << "Enter edges (u v weight):\n";

    for(int i = 0; i < E; i++)
    {
        cin >> edges[i][0]
            >> edges[i][1]
            >> edges[i][2];
    }

    Solution obj;

    if(obj.isNegativeWeightCycle(V, edges))
        cout << "Negative Weight Cycle Exists";
    else
        cout << "No Negative Weight Cycle";

    return 0;
}