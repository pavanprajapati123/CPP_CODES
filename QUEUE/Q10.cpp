// Interleave the first half of the queue with the second half
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main() {

    queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    int n = q.size();
    stack<int> st;

    for (int i = 0; i < n / 2; i++) {
        st.push(q.front());
        q.pop();
    }

    while (!st.empty()) {
        q.push(st.top());
        st.pop();
    }

    for (int i = 0; i < n / 2; i++) {
        q.push(q.front());
        q.pop();
    }

    for (int i = 0; i < n / 2; i++) {
        st.push(q.front());
        q.pop();
    }

    while (!st.empty()) {
        q.push(st.top());
        q.pop();

        q.push(q.front());
        q.pop();

        st.pop();
    }

    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}