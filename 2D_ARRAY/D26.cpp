// Problem: 1510. Stone Game IV
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool winnerSquareGame(int n)
    {
        vector<bool> dp(n + 1, false);

        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j * j <= i; j++)
            {
                if(!dp[i - j * j])
                {
                    dp[i] = true;
                    break;
                }
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

    if(obj.winnerSquareGame(n))
        cout << "Alice Wins";
    else
        cout << "Bob Wins";

    return 0;
}