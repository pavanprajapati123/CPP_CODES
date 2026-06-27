#include <iostream>
#include <queue>
using namespace std;

void interleaveQueue(queue<int> &q)
{
    int n = q.size();

    if (n % 2 != 0)
    {
        cout << "Queue should contain even number of elements.";
        return;
    }

    queue<int> firstHalf;

    for (int i = 0; i < n / 2; i++)
    {
        firstHalf.push(q.front());
        q.pop();
    }

    while (!firstHalf.empty())
    {
        q.push(firstHalf.front());
        firstHalf.pop();

        q.push(q.front());
        q.pop();
    }
}

int main()
{
    queue<int> q;

    q.push(11);
    q.push(12);
    q.push(13);
    q.push(14);
    q.push(15);
    q.push(16);

    interleaveQueue(q);

    cout << "Interleaved Queue: ";

    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}
