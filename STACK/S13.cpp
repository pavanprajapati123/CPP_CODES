// Implement Queue using Stacks
#include <iostream>
#include <stack>
using namespace std;

class MyQueue
{
public:
    stack<int> s1, s2;

    MyQueue() {}

    void push(int x)
    {
        while(!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }

        s1.push(x);

        while(!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }

    int pop()
    {
        int x = s1.top();
        s1.pop();

        return x;
    }

    int peek()
    {
        return s1.top();
    }

    bool empty()
    {
        return s1.empty();
    }
};

int main()
{
    MyQueue q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front Element = " << q.peek() << endl;

    cout << "Popped Element = " << q.pop() << endl;

    cout << "Front Element = " << q.peek() << endl;

    if(q.empty())
        cout << "Queue is Empty";
    else
        cout << "Queue is Not Empty";

    return 0;
}