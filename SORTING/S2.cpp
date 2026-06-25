// This program sorts a stack of integers in ascending order using an auxiliary vector.
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

void sortStack(stack<int> &st)
{
    vector<int> temp;

    // Stack -> Vector
    while (!st.empty())
    {
        temp.push_back(st.top());
        st.pop();
    }

    // Sort Vector
    sort(temp.begin(), temp.end());

    // Vector -> Stack
    for (int x : temp)
    {
        st.push(x);
    }
}

int main()
{
    stack<int> st;

    st.push(30);
    st.push(10);
    st.push(50);
    st.push(20);

    sortStack(st);

    cout << "Sorted Stack (Top to Bottom): ";

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}