//Find Maximum Digit Sum
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMax(int n)
    {
        int ans = n;
        int maxSum = 0;

        // Find digit sum of n
        int x = n;

        while(x > 0)
        {
            maxSum += x % 10;
            x /= 10;
        }

        // Check numbers just below n
        int p = 1;

        while(p <= n)
        {
            int candidate = n - (n % p) - 1;

            if(candidate >= 1)
            {
                int sum = 0;
                int x = candidate;

                while(x > 0)
                {
                    sum += x % 10;
                    x /= 10;
                }

                if(sum >= maxSum)
                {
                    if(sum > maxSum || candidate > ans)
                    {
                        maxSum = sum;
                        ans = candidate;
                    }
                }
            }

            p *= 10;
        }

        return ans;
    }
};

int main()
{
    int n;

    cout << "Enter n: ";
    cin >> n;

    Solution obj;

    cout << "Maximum Number: "
         << obj.findMax(n);

    return 0;
}