// rearrange the array
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:

    const int MOD = 1000000007;

    long long power(long long a, long long b)
    {
        long long ans = 1;

        while(b)
        {
            if(b & 1)
                ans = (ans * a) % MOD;

            a = (a * a) % MOD;
            b >>= 1;
        }

        return ans;
    }

    int minOperations(vector<int>& b)
    {
        int n = b.size();

        vector<int> vis(n, 0);

        unordered_map<int, int> primePower;

        for(int i = 0; i < n; i++)
        {
            if(vis[i])
                continue;

            int len = 0;
            int curr = i;

            while(!vis[curr])
            {
                vis[curr] = 1;
                curr = b[curr] - 1;
                len++;
            }

            int x = len;

            for(int p = 2; p * p <= x; p++)
            {
                int cnt = 0;

                while(x % p == 0)
                {
                    cnt++;
                    x /= p;
                }

                primePower[p] = max(primePower[p], cnt);
            }

            if(x > 1)
                primePower[x] = max(primePower[x], 1);
        }

        long long ans = 1;

        for(auto &it : primePower)
        {
            ans = (ans * power(it.first, it.second)) % MOD;
        }

        return ans;
    }
};

int main()
{
    int n;

    cout << "Enter size of permutation: ";
    cin >> n;

    vector<int> b(n);

    cout << "Enter permutation: ";
    for(int i = 0; i < n; i++)
        cin >> b[i];

    Solution obj;

    cout << "Minimum Operations = "
         << obj.minOperations(b);

    return 0;
}