//1406. Stone Game III
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution
{
public:
    string stoneGameIII(vector<int>& stoneValue)
    {
        int n = stoneValue.size();

        vector<int> dp(n + 1, 0);

        for(int i = n - 1; i >= 0; i--)
        {
            int sum = 0;
            dp[i] = INT_MIN;

            for(int k = 0; k < 3 && i + k < n; k++)
            {
                sum += stoneValue[i + k];

                dp[i] = max(dp[i], sum - dp[i + k + 1]);
            }
        }

        if(dp[0] > 0)
            return "Alice";

        if(dp[0] < 0)
            return "Bob";

        return "Tie";
    }
};

int main()
{
    int n;

    cout << "Enter number of stones: ";
    cin >> n;

    vector<int> stoneValue(n);

    cout << "Enter stone values: ";

    for(int i = 0; i < n; i++)
    {
        cin >> stoneValue[i];
    }

    Solution obj;

    cout << "Winner: "
         << obj.stoneGameIII(stoneValue);

    return 0;
}