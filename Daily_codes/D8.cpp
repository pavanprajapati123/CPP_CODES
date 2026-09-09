#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long countCommas(long long n)
    {
        long long ans = 0;
        long long p = 1000;

        while(p <= n)
        {
            ans += n - p + 1;

            p *= 1000;
        }

        return ans;
    }
};

int main()
{
    long long n;

    cout << "Enter n: ";
    cin >> n;

    Solution obj;

    cout << "Number of Commas: "
         << obj.countCommas(n);

    return 0;
}