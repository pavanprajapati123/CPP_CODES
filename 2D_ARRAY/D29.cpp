//Count Numbers Without a Given Digit
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countWithout(int n, int d)
    {
        string s = to_string(n);
        int len = s.size();

        long long dp[11][2][2];

        memset(dp, -1, sizeof(dp));

        function<long long(int, int, int)> solve =
        [&](int pos, int tight, int started) -> long long
        {
            if(pos == len)
                return 1;

            if(dp[pos][tight][started] != -1)
                return dp[pos][tight][started];

            int limit = tight ? s[pos] - '0' : 9;

            long long ans = 0;

            for(int digit = 0; digit <= limit; digit++)
            {
                int ntight = tight && (digit == s[pos] - '0');

                // Leading zero
                if(started == 0 && digit == 0)
                {
                    ans += solve(pos + 1, ntight, 0);
                }
                else
                {
                    // Do not allow digit d
                    if(digit == d)
                        continue;

                    ans += solve(pos + 1, ntight, 1);
                }
            }

            return dp[pos][tight][started] = ans;
        };

        // -1 because 0 is also counted
        return solve(0, 1, 0) - 1;
    }
};

int main()
{
    int n, d;

    cout << "Enter n: ";
    cin >> n;

    cout << "Enter digit to exclude: ";
    cin >> d;

    Solution obj;

    cout << "Count = "
         << obj.countWithout(n, d);

    return 0;
}