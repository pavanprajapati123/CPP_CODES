// excel sheet column number
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:

    long long titleToNumber(string str)
    {
        long long ans = 0;
        long long power = 1;

        for(int i = str.size() - 1; i >= 0; i--)
        {
            int value = str[i] - 'A' + 1;
            ans += value * power;
            power *= 26;
        }

        return ans;
    }
};

int main()
{
    string str;

    cout << "Enter Excel Column Title: ";
    cin >> str;

    Solution obj;

    cout << "Column Number = "
         << obj.titleToNumber(str);

    return 0;
}