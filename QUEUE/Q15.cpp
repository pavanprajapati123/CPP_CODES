#include <iostream>
#include <stack>
using namespace std;

class Queue
{
    stack<int> s1, s2;

public:
    void enqueue(int x)
    {
        s1.push(x);
    }

    void dequeue()
    {
        if (s1.empty() && s2.empty())
        {
            cout << "Queue Underflow\n";
            return;
        }

        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }

        cout << "Deleted Element: " << s2.top() << endl;
        s2.pop();
    }

    void front()
    {
        if (s1.empty() && s2.empty())
        {
            cout << "Queue is Empty\n";
            return;
        }

        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }

        cout << "Front Element: " << s2.top() << endl;
    }
};

int main()
{
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    q.front();
    q.dequeue();
    q.front();

    return 0;
}
