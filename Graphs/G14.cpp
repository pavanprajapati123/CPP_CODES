//3310. Remove Methods From Project
#include <iostream>
#include <vector>
#include <functional>
using namespace std;

class Solution
{
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations)
    {
        vector<vector<int>> adj(n);

        for(auto &e : invocations)
        {
            adj[e[0]].push_back(e[1]);
        }

        vector<int> vis(n, 0);

        function<void(int)> dfs = [&](int node)
        {
            vis[node] = 1;

            for(int nxt : adj[node])
            {
                if(!vis[nxt])
                {
                    dfs(nxt);
                }
            }
        };

        // Mark all suspicious methods
        dfs(k);

        // Check if any safe method calls a suspicious method
        for(auto &e : invocations)
        {
            if(!vis[e[0]] && vis[e[1]])
            {
                vector<int> ans;

                for(int i = 0; i < n; i++)
                {
                    ans.push_back(i);
                }

                return ans;
            }
        }

        vector<int> ans;

        for(int i = 0; i < n; i++)
        {
            if(!vis[i])
            {
                ans.push_back(i);
            }
        }

        return ans;
    }
};

int main()
{
    int n, m, k;

    cout << "Enter number of methods: ";
    cin >> n;

    cout << "Enter number of invocations: ";
    cin >> m;

    vector<vector<int>> invocations(m, vector<int>(2));

    cout << "Enter method calls (u v):\n";

    for(int i = 0; i < m; i++)
    {
        cin >> invocations[i][0] >> invocations[i][1];
    }

    cout << "Enter suspicious method: ";
    cin >> k;

    Solution obj;

    vector<int> ans = obj.remainingMethods(n, k, invocations);

    cout << "Remaining Methods: ";

    for(int x : ans)
    {
        cout << x << " ";
    }

    return 0;
}