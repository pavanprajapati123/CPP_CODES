// Evaluate Postfix Expression using Stack
#include <iostream>
#include <stack>
using namespace std;

int main() {
    string exp = "23+";

    stack<int> st;

    for(char ch : exp) {

        if(isdigit(ch))
            st.push(ch - '0');

        else {
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();

            st.push(a + b);
        }
    }

    cout << st.top();
}
