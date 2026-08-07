//3345. Smallest Divisible Digit Product I
#include <iostream>
using namespace std;

class Solution
{
public:
    int digitProduct(int x)
    {
        int prod = 1;

        while(x)
        {
            prod *= (x % 10);
            x /= 10;
        }

        return prod;
    }

    int smallestNumber(int n, int t)
    {
        while(true)
        {
            if(digitProduct(n) % t == 0)
            {
                return n;
            }

            n++;
        }
    }
};

int main()
{
    int n, t;

    cout << "Enter n and t: ";
    cin >> n >> t;

    Solution obj;

    cout << "Smallest Number = "
         << obj.smallestNumber(n, t);

    return 0;
}