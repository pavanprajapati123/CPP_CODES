//Pairs with Given GCD and LCM
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int pairCount(int x, int y)
    {
        // If y is not divisible by x,
        // no valid pair is possible.
        if(y % x != 0)
            return 0;

        int count = 0;

        long long product = 1LL * x * y;

        // Check divisors of product which are multiples of x
        for(long long a = x; a * a <= product; a += x)
        {
            if(product % a != 0)
                continue;

            long long b = product / a;

            // Check GCD condition
            if(__gcd(a, b) == x)
            {
                if(a == b)
                    count += 1;
                else
                    count += 2;
            }
        }

        return count;
    }
};

int main()
{
    int x, y;

    cout << "Enter x: ";
    cin >> x;

    cout << "Enter y: ";
    cin >> y;

    Solution obj;

    cout << "Pair Count: "
         << obj.pairCount(x, y);

    return 0;
}