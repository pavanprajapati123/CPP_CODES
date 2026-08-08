//nimum Edges Required to Connect Graph
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> parent, sz;

    int find(int x)
    {
        if(parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    void unite(int u, int v)
    {
        u = find(u);
        v = find(v);

        if(u == v)
            return;

        if(sz[u] < sz[v])
            swap(u, v);

        parent[v] = u;
        sz[u] += sz[v];
    }

    int minEdgesReq(int n, vector<vector<int>>& edges)
    {
        // At least n-1 edges are required
        if(edges.size() < n - 1)
            return -1;

        parent.resize(n);
        sz.assign(n, 1);

        for(int i = 0; i < n; i++)
            parent[i] = i;

        for(auto &e : edges)
        {
            unite(e[0], e[1]);
        }

        int comp = 0;

        for(int i = 0; i < n; i++)
        {
            if(find(i) == i)
                comp++;
        }

        return comp - 1;
    }
};

int main()
{
    int n, m;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> m;

    vector<vector<int>> edges(m, vector<int>(2));

    cout << "Enter edges:\n";

    for(int i = 0; i < m; i++)
    {
        cin >> edges[i][0] >> edges[i][1];
    }

    Solution obj;

    cout << "Minimum Edges Required = "
         << obj.minEdgesReq(n, edges);

    return 0;
}