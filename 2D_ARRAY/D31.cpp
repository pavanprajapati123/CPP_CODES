#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int prefixStrings(int n)
    {
        const long long MOD = 1000000007;

        vector<long long> dp(n + 1, 0);

        dp[0] = 1;

        for(int i = 1; i <= n; i++)
        {
            for(int j = 0; j < i; j++)
            {
                dp[i] =
                    (dp[i] +
                     dp[j] * dp[i - 1 - j]) % MOD;
            }
        }

        return dp[n];
    }
};

int main()
{
    int n;

    cout << "Enter n: ";
    cin >> n;

    Solution obj;

    cout << "Number of Prefix Strings = "
         << obj.prefixStrings(n);

    return 0;
}