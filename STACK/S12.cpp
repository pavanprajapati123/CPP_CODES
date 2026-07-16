// number with given sum of digits
#include <iostream>
using namespace std;

class Solution {
public:

    int ans = 0;

    void solve(int pos, int n, int sum)
    {
        if(pos == n)
        {
            if(sum == 0)
                ans++;

            return;
        }

        int start;

        if(pos == 0)
            start = 1;
        else
            start = 0;

        for(int d = start; d <= 9; d++)
        {
            if(sum >= d)
            {
                solve(pos + 1, n, sum - d);
            }
        }
    }

    int countWays(int n, int sum)
    {
        ans = 0;

        solve(0, n, sum);

        if(ans == 0)
            return -1;

        return ans;
    }
};

int main()
{
    int n, sum;

    cout << "Enter number of digits: ";
    cin >> n;

    cout << "Enter required sum: ";
    cin >> sum;

    Solution obj;

    cout << "Number of Ways = "
         << obj.countWays(n, sum);

    return 0;
}