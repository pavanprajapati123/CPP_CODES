//2058 — Find the Minimum and Maximum Number of Nodes Between Critical Points
#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;

    ListNode(int x)
    {
        val = x;
        next = NULL;
    }
};

class Solution
{
public:

    vector<int> nodesBetweenCriticalPoints(ListNode* head)
    {
        vector<int> ans = {-1, -1};

        if(head == NULL || head->next == NULL ||
           head->next->next == NULL)
            return ans;

        ListNode* prev = head;
        ListNode* curr = head->next;

        int pos = 1;

        int first = -1;
        int last = -1;

        int minDist = INT_MAX;

        while(curr->next != NULL)
        {
            // Check whether current node is a critical point
            bool critical =
                (curr->val > prev->val &&
                 curr->val > curr->next->val) ||
                (curr->val < prev->val &&
                 curr->val < curr->next->val);

            if(critical)
            {
                if(first == -1)
                {
                    // First critical point
                    first = pos;
                }
                else
                {
                    // Distance from previous critical point
                    minDist = min(minDist, pos - last);
                }

                last = pos;
            }

            prev = curr;
            curr = curr->next;
            pos++;
        }

        // Less than two critical points
        if(first == -1 || first == last)
            return ans;

        // Minimum distance
        ans[0] = minDist;

        // Maximum distance
        ans[1] = last - first;

        return ans;
    }
};

int main()
{
    int n;

    cout << "Enter number of nodes: ";
    cin >> n;

    if(n == 0)
    {
        cout << "-1 -1";
        return 0;
    }

    ListNode* head = NULL;
    ListNode* tail = NULL;

    cout << "Enter linked list elements: ";

    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        ListNode* newNode = new ListNode(x);

        if(head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    Solution obj;

    vector<int> ans =
        obj.nodesBetweenCriticalPoints(head);

    cout << "Minimum Distance = " << ans[0] << endl;
    cout << "Maximum Distance = " << ans[1] << endl;

    return 0;
}