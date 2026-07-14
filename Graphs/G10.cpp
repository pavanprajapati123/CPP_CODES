// creating and printing adjacency list of a graph
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:

    vector<vector<int>> printAdjacency(int n, int m, vector<vector<int>> &edges)
    {
        vector<vector<int>> ans(n);

        for(int node = 0; node < n; node++)
        {
            ans[node].push_back(node);

            for(int i = 0; i < m; i++)
            {
                if(edges[i][0] == node)
                    ans[node].push_back(edges[i][1]);

                else if(edges[i][1] == node)
                    ans[node].push_back(edges[i][0]);
            }
        }

        return ans;
    }
};

int main()
{
    int n, m;

    cout << "Enter number of vertices and edges: ";
    cin >> n >> m;

    vector<vector<int>> edges(m, vector<int>(2));

    cout << "Enter edges:\n";

    for(int i = 0; i < m; i++)
    {
        cin >> edges[i][0] >> edges[i][1];
    }

    Solution obj;

    vector<vector<int>> ans = obj.printAdjacency(n, m, edges);

    cout << "\nAdjacency List:\n";

    for(int i = 0; i < ans.size(); i++)
    {
        for(int x : ans[i])
            cout << x << " ";

        cout << endl;
    }

    return 0;
}