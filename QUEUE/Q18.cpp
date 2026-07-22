//  Reverse first k elements of queue
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class Solution
{
public:
    queue<int> reverseElements(queue<int> q, int k)
    {
        stack<int> st;

        // Push first k elements into stack
        for(int i = 0; i < k; i++)
        {
            st.push(q.front());
            q.pop();
        }

        // Push stack elements back into queue
        while(!st.empty())
        {
            q.push(st.top());
            st.pop();
        }

        // Move remaining elements to the back
        int t = q.size() - k;

        while(t--)
        {
            q.push(q.front());
            q.pop();
        }

        return q;
    }
};

int main()
{
    int n;

    cout << "Enter size of queue: ";
    cin >> n;

    queue<int> q;

    cout << "Enter queue elements: ";

    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        q.push(x);
    }

    int k;

    cout << "Enter value of k: ";
    cin >> k;

    Solution obj;

    queue<int> ans = obj.reverseElements(q, k);

    cout << "Queue after reversing first " << k << " elements: ";

    while(!ans.empty())
    {
        cout << ans.front() << " ";
        ans.pop();
    }

    return 0;
}