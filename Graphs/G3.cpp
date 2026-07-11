//2685 count the number of complete components in a graph`
#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:

    vector<vector<int>> graph;
    vector<int> vis;

    void dfs(int node, vector<int>& comp)
    {
        vis[node] = 1;
        comp.push_back(node);

        for(int nxt : graph[node])
        {
            if(!vis[nxt])
                dfs(nxt, comp);
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges)
    {
        graph.assign(n, {});
        vis.assign(n, 0);

        set<pair<int,int>> st;

        for(auto &e : edges)
        {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);

            st.insert({e[0], e[1]});
            st.insert({e[1], e[0]});
        }

        int ans = 0;

        for(int i = 0; i < n; i++)
        {
            if(vis[i])
                continue;

            vector<int> comp;

            dfs(i, comp);

            bool ok = true;

            for(int x : comp)
            {
                for(int y : comp)
                {
                    if(x == y)
                        continue;

                    if(st.count({x, y}) == 0)
                    {
                        ok = false;
                        break;
                    }
                }

                if(!ok)
                    break;
            }

            if(ok)
                ans++;
        }

        return ans;
    }
};

int main()
{
    int n, m;

    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    vector<vector<int>> edges(m, vector<int>(2));

    cout << "Enter edges:\n";

    for(int i = 0; i < m; i++)
    {
        cin >> edges[i][0] >> edges[i][1];
    }

    Solution obj;

    cout << "Complete Components = "
         << obj.countCompleteComponents(n, edges);

    return 0;
}