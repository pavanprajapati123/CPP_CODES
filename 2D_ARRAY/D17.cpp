// C++ program to find the length of longest common subsequence
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:

    int solve(string &a, string &b, int i, int j,
              vector<vector<int>> &dp)
    {
        if(i == a.size() || j == b.size())
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        if(a[i] == b[j])
            return dp[i][j] = 1 + solve(a, b, i + 1, j + 1, dp);

        return dp[i][j] = max(solve(a, b, i + 1, j, dp),
                              solve(a, b, i, j + 1, dp));
    }

    int longestCommonSubsequence(string text1, string text2)
    {
        vector<vector<int>> dp(text1.size(),
                               vector<int>(text2.size(), -1));

        return solve(text1, text2, 0, 0, dp);
    }
};

int main()
{
    string text1, text2;

    cout << "Enter First String: ";
    cin >> text1;

    cout << "Enter Second String: ";
    cin >> text2;

    Solution obj;

    cout << "Length of LCS = "
         << obj.longestCommonSubsequence(text1, text2);

    return 0;
}