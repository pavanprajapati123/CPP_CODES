// 20. Valid Parenthesis
#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isValidParenthesis(string s)
{
    stack<char> st;

    for (char ch : s)
    {
        if (ch == '(' || ch == '{' || ch == '[')
        {
            st.push(ch);
        }
        else
        {
            if (st.empty())
                return false;

            if ((ch == ')' && st.top() != '(') ||
                (ch == '}' && st.top() != '{') ||
                (ch == ']' && st.top() != '['))
            {
                return false;
            }

            st.pop();
        }
    }

    return st.empty();
}

int main()
{
    string s;

    cout << "Enter Parenthesis String: ";
    cin >> s;

    if (isValidParenthesis(s))
        cout << "Valid Parenthesis" << endl;
    else
        cout << "Invalid Parenthesis" ;

    return 0;
}