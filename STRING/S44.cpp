//Minimum Parentheses
#include <bits/stdc++.h>
using namespace std;

int minimumParentheses(string pattern)
{
    int balance = 0;
    int ans = 0;

    for(char ch : pattern)
    {
        if(ch == '(')
        {
            balance++;
        }
        else
        {
            if(balance > 0)
                balance--;
            else
                ans++;
        }
    }

    // Remaining opening brackets also need
    // one closing bracket each
    return ans + balance;
}

int main()
{
    string pattern;

    cout << "Enter parentheses string: ";
    cin >> pattern;

    cout << "Minimum Parentheses to Add = "
         << minimumParentheses(pattern);

    return 0;
}