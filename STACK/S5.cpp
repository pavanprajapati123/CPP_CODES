// Check for balanced parentheses using Stack
#include <iostream>
#include <stack>
using namespace std;

bool isBalanced(string s) {
    stack<char> st;

    for(char ch : s) {
        if(ch == '(')
            st.push(ch);
        else if(ch == ')') {
            if(st.empty()) return false;
            st.pop();
        }
    }

    return st.empty();
}

int main() {
    string s = "(())()";
    cout << isBalanced(s);
}