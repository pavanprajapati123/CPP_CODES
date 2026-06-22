// Find the middle element of a stack
#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> st;

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

    int n = st.size();
    int mid = n / 2;

    while(mid--) st.pop();

    cout << st.top();
}