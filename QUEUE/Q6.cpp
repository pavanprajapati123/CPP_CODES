// First Negative Integer in Every Window of Size K
#include <iostream>
#include <queue>
using namespace std;

int main() {

    int arr[] = {-8, 2, 3, -6, 10};
    int n = 5;
    int k = 2;

    queue<int> q;

    for (int i = 0; i < k; i++)
        if (arr[i] < 0)
            q.push(i);

    for (int i = k; i <= n; i++) {

        if (!q.empty())
            cout << arr[q.front()] << " ";
        else
            cout << "0 ";

        while (!q.empty() && q.front() <= i - k)
            q.pop();

        if (i < n && arr[i] < 0)
            q.push(i);
    }

    return 0;
}