// Reverse a String using Stack
#include <iostream>
#include <stack>
using namespace std;

int main() {
    string str = "PAVAN";

    stack<char> st;

    for(char ch : str)
        st.push(ch);

    while(!st.empty()) {
        cout << st.top();
        st.pop();
    }
}