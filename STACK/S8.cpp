// Sort a stack using recursion
#include <iostream>
#include <stack>
using namespace std;

void sortedInsert(stack<int>& st, int x) {
    if(st.empty() || x > st.top()) {
        st.push(x);
        return;
    }

    int temp = st.top();
    st.pop();

    sortedInsert(st, x);

    st.push(temp);
}

void sortStack(stack<int>& st) {
    if(st.empty()) return;

    int temp = st.top();
    st.pop();

    sortStack(st);

    sortedInsert(st, temp);
}

int main() {
    stack<int> st;

    st.push(30);
    st.push(10);
    st.push(50);
    st.push(20);

    sortStack(st);

    while(!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
}