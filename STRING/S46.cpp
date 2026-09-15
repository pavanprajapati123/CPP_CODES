// 2475 Maximum Number of Palindromes
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxPalindromes(string s, int k)
    {
        int n = s.size();

        // pal[i][j] = whether s[i...j] is a palindrome
        vector<vector<bool>> pal(n, vector<bool>(n, false));

        // Build palindrome table
        for (int len = 1; len <= n; len++)
        {
            for (int i = 0; i + len - 1 < n; i++)
            {
                int j = i + len - 1;

                if (s[i] == s[j] &&
                    (len <= 2 || pal[i + 1][j - 1]))
                {
                    pal[i][j] = true;
                }
            }
        }

        // dp[i] = maximum number of valid palindromes
        // using first i characters
        vector<int> dp(n + 1, 0);

        for (int i = 1; i <= n; i++)
        {
            // Don't take a palindrome ending at i-1
            dp[i] = dp[i - 1];

            for (int j = 0; j < i; j++)
            {
                int len = i - j;

                if (len >= k && pal[j][i - 1])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        return dp[n];
    }
};

int main()
{
    Solution obj;

    string s = "abaccdbbd";
    int k = 3;

    cout << obj.maxPalindromes(s, k);

    return 0;
}