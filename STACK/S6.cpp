// Reverse a stack using another stack
#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> s1, s2;

    s1.push(10);
    s1.push(20);
    s1.push(30);

    while(!s1.empty()) {
        s2.push(s1.top());
        s1.pop();
    }

    while(!s2.empty()) {
        cout << s2.top() << " ";
        s2.pop();
    }
}