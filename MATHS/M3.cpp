//3622 Check Divisibility
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkDivisibility(int n)
    {
        int temp = n;
        int sum = 0;
        int product = 1;

        while(temp > 0)
        {
            int digit = temp % 10;

            sum += digit;
            product *= digit;

            temp /= 10;
        }

        int total = sum + product;

        return n % total == 0;
    }
};

int main()
{
    int n;

    cout << "Enter number: ";
    cin >> n;

    Solution obj;

    if(obj.checkDivisibility(n))
        cout << "true";
    else
        cout << "false";

    return 0;
}