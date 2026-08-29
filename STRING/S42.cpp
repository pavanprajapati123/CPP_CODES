//Count Subsequences Divisible by n
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countSubsequences(string s, int n)
    {
        const int MOD = 1000000007;

        // dp[rem] = number of subsequences
        // having remainder rem when divided by n
        vector<int> dp(n, 0);

        for(char ch : s)
        {
            int digit = ch - '0';

            vector<int> curr = dp;

            // Start a new subsequence with current digit
            curr[digit % n] =
                (curr[digit % n] + 1) % MOD;

            // Add current digit to every
            // previously formed subsequence
            for(int rem = 0; rem < n; rem++)
            {
                int newRem =
                    (rem * 10 + digit) % n;

                curr[newRem] =
                    (curr[newRem] + dp[rem]) % MOD;
            }

            dp = curr;
        }

        return dp[0];
    }
};

int main()
{
    string s;
    int n;

    cout << "Enter string: ";
    cin >> s;

    cout << "Enter n: ";
    cin >> n;

    Solution obj;

    cout << "Number of Subsequences = "
         << obj.countSubsequences(s, n);

    return 0;
}