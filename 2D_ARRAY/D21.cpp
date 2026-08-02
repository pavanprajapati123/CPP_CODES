//sequences where Adjecent elements are divisible by each other
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int count(int n, int m)
    {
        const int MOD = 1000000007;

        vector<vector<int>> adj(m + 1);

        // Build Graph
        for(int i = 1; i <= m; i++)
        {
            for(int j = i; j <= m; j += i)
            {
                adj[i].push_back(j);

                if(j != i)
                {
                    adj[j].push_back(i);
                }
            }
        }

        vector<long long> dp(m + 1, 1);
        vector<long long> ndp(m + 1);

        for(int len = 2; len <= n; len++)
        {
            fill(ndp.begin(), ndp.end(), 0);

            for(int x = 1; x <= m; x++)
            {
                for(int y : adj[x])
                {
                    ndp[x] = (ndp[x] + dp[y]) % MOD;
                }
            }

            dp = ndp;
        }

        long long ans = 0;

        for(int i = 1; i <= m; i++)
        {
            ans = (ans + dp[i]) % MOD;
        }

        return ans;
    }
};

int main()
{
    int n, m;

    cout << "Enter n and m: ";
    cin >> n >> m;

    Solution obj;

    cout << "Count = " << obj.count(n, m);

    return 0;
}