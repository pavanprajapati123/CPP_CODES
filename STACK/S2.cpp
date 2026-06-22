// Stack implementation using array
#include <iostream>
using namespace std;

class Stack {
    int arr[100];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(int x) {
        if(top == 99) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = x;
    }

    void pop() {
        if(top == -1) {
            cout << "Stack Underflow\n";
            return;
        }
        top--;
    }

    int peek() {
        if(top == -1) return -1;
        return arr[top];
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    cout << s.peek();
}