#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void reverseFirstK(queue<int> &q, int k)
{
    if (k <= 0 || k > q.size())
        return;

    stack<int> st;

    for (int i = 0; i < k; i++)
    {
        st.push(q.front());
        q.pop();
    }

    while (!st.empty())
    {
        q.push(st.top());
        st.pop();
    }

    int t = q.size() - k;

    while (t--)
    {
        q.push(q.front());
        q.pop();
    }
}

int main()
{
    queue<int> q;

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    int k = 3;

    reverseFirstK(q, k);

    cout << "Queue after reversing first " << k << " elements: ";

    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}
