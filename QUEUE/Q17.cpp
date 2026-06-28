// C++ program to implement a circular queue
#include <iostream>
using namespace std;

class CircularQueue
{
    int *arr;
    int front, rear, size, capacity;

public:
    CircularQueue(int cap)
    {
        capacity = cap;
        arr = new int[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }

    void enqueue(int data)
    {
        if (size == capacity)
        {
            cout << "Queue Overflow" << endl;
            return;
        }

        rear = (rear + 1) % capacity;
        arr[rear] = data;
        size++;
    }

    void dequeue()
    {
        if (size == 0)
        {
            cout << "Queue Underflow" << endl;
            return;
        }

        cout << "Deleted Element: " << arr[front] << endl;
        front = (front + 1) % capacity;
        size--;
    }

    void display()
    {
        if (size == 0)
        {
            cout << "Queue is Empty" << endl;
            return;
        }

        cout << "Queue: ";

        for (int i = 0; i < size; i++)
        {
            cout << arr[(front + i) % capacity] << " ";
        }

        cout << endl;
    }
};

int main()
{
    CircularQueue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    q.display();

    q.dequeue();

    q.display();

    q.enqueue(50);
    q.enqueue(60);

    q.display();

    return 0;
}