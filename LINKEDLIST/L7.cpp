// reverse a linked list
#include <iostream>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode* next;

    ListNode(int data)
    {
        val = data;
        next = NULL;
    }
};

class Solution {
public:

    ListNode* reverseList(ListNode* head)
    {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;

        while(curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
};

void printList(ListNode* head)
{
    while(head != NULL)
    {
        cout << head->val << " ";
        head = head->next;
    }
}

int main()
{
    int n;

    cout << "Enter number of nodes: ";
    cin >> n;

    if(n == 0)
        return 0;

    int x;
    cin >> x;

    ListNode* head = new ListNode(x);
    ListNode* tail = head;

    for(int i = 1; i < n; i++)
    {
        cin >> x;
        tail->next = new ListNode(x);
        tail = tail->next;
    }

    Solution obj;

    head = obj.reverseList(head);

    cout << "Reversed Linked List: ";

    printList(head);

    return 0;
}