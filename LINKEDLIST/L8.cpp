// 19 remove Nth Node From End of List
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

    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        int len = 0;
        ListNode* temp = head;

        while(temp != NULL)
        {
            len++;
            temp = temp->next;
        }

        // Remove Head
        if(len == n)
            return head->next;

        int pos = len - n;

        temp = head;

        for(int i = 1; i < pos; i++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;

        return head;
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

    int k;

    cout << "Enter n (from end): ";
    cin >> k;

    Solution obj;

    head = obj.removeNthFromEnd(head, k);

    cout << "Updated Linked List: ";

    printList(head);

    return 0;
}