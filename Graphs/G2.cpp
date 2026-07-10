//3534 pathExistenceQueries in a graph ||
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

    static const int LOG = 20;

    vector<int> pathExistenceQueries(int n,
                                     vector<int>& nums,
                                     int maxDiff,
                                     vector<vector<int>>& queries)
    {
        vector<pair<int, int>> arr;

        for(int i = 0; i < n; i++)
            arr.push_back({nums[i], i});

        sort(arr.begin(), arr.end());

        vector<int> pos(n);

        for(int i = 0; i < n; i++)
            pos[arr[i].second] = i;

        vector<int> value(n);

        for(int i = 0; i < n; i++)
            value[i] = arr[i].first;

        vector<int> reach(n);

        int j = 0;

        for(int i = 0; i < n; i++)
        {
            while(j + 1 < n &&
                  value[j + 1] - value[i] <= maxDiff)
            {
                j++;
            }

            reach[i] = j;
        }

        vector<vector<int>> up(LOG, vector<int>(n));

        for(int i = 0; i < n; i++)
            up[0][i] = reach[i];

        for(int k = 1; k < LOG; k++)
        {
            for(int i = 0; i < n; i++)
            {
                up[k][i] = up[k - 1][up[k - 1][i]];
            }
        }

        vector<int> ans;

        for(auto &q : queries)
        {
            int u = pos[q[0]];
            int v = pos[q[1]];

            if(u > v)
                swap(u, v);

            if(u == v)
            {
                ans.push_back(0);
                continue;
            }

            if(reach[u] == u)
            {
                ans.push_back(-1);
                continue;
            }

            int cur = u;
            int jumps = 0;

            for(int k = LOG - 1; k >= 0; k--)
            {
                if(up[k][cur] < v)
                {
                    if(up[k][cur] == cur)
                        continue;

                    jumps += (1 << k);
                    cur = up[k][cur];
                }
            }

            if(reach[cur] >= v)
                ans.push_back(jumps + 1);
            else
                ans.push_back(-1);
        }

        return ans;
    }
};

int main()
{
    int n;

    cout << "Enter number of nodes: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter node values: ";
    for(int i = 0; i < n; i++)
        cin >> nums[i];

    int maxDiff;

    cout << "Enter maxDiff: ";
    cin >> maxDiff;

    int q;

    cout << "Enter number of queries: ";
    cin >> q;

    vector<vector<int>> queries(q, vector<int>(2));

    cout << "Enter queries (index1 index2):\n";

    for(int i = 0; i < q; i++)
    {
        cin >> queries[i][0] >> queries[i][1];
    }

    Solution obj;

    vector<int> ans = obj.pathExistenceQueries(n, nums, maxDiff, queries);

    cout << "Answers:\n";

    for(int x : ans)
        cout << x << " ";

    return 0;
}