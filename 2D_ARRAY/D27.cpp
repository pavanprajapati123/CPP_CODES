//High Effort vs Low Effort
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxTask(vector<int>& h, vector<int>& l)
    {
        int n = h.size();

        if(n == 1)
            return max(h[0], l[0]);

        vector<int> dp(n, 0);

        dp[0] = max(h[0], l[0]);

        dp[1] = max({
            dp[0],
            dp[0] + l[1],
            h[1]
        });

        for(int i = 2; i < n; i++)
        {
            dp[i] = max({
                dp[i - 1],
                dp[i - 1] + l[i],
                dp[i - 2] + h[i]
            });
        }

        return dp[n - 1];
    }
};

int main()
{
    int n;

    cout << "Enter number of tasks: ";
    cin >> n;

    vector<int> h(n), l(n);

    cout << "Enter h values: ";
    for(int i = 0; i < n; i++)
    {
        cin >> h[i];
    }

    cout << "Enter l values: ";
    for(int i = 0; i < n; i++)
    {
        cin >> l[i];
    }

    Solution obj;

    cout << "Maximum Task Score = "
         << obj.maxTask(h, l);

    return 0;
}