//Add Two Large Numbers Represented as Strings
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string stringSum(string &num1, string &num2)
    {
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        int carry = 0;

        string ans = "";

        while(i >= 0 || j >= 0 || carry)
        {
            int sum = carry;

            if(i >= 0)
            {
                sum += num1[i] - '0';
                i--;
            }

            if(j >= 0)
            {
                sum += num2[j] - '0';
                j--;
            }

            ans.push_back((sum % 10) + '0');
            carry = sum / 10;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};

int main()
{
    string num1, num2;

    cout << "Enter First Number: ";
    cin >> num1;

    cout << "Enter Second Number: ";
    cin >> num2;

    Solution obj;

    cout << "Sum = " << obj.stringSum(num1, num2);

    return 0;
}