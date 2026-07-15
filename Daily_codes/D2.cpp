//3658 GCD of Odd and Even Sums
#include <iostream>
using namespace std;

class Solution {
public:

    int gcdOfOddEvenSums(int n)
    {
        return n;
    }
};

int main()
{
    int n;

    cout << "Enter n: ";
    cin >> n;

    Solution obj;

    cout << "GCD = "
         << obj.gcdOfOddEvenSums(n);

    return 0;
}