//21 marge two sorted linked lists
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode* next;

    ListNode(int x)
    {
        val = x;
        next = NULL;
    }
};

class Solution {
public:

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        vector<int> arr;

        while(list1 != NULL)
        {
            arr.push_back(list1->val);
            list1 = list1->next;
        }

        while(list2 != NULL)
        {
            arr.push_back(list2->val);
            list2 = list2->next;
        }

        sort(arr.begin(), arr.end());

        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        for(int x : arr)
        {
            temp->next = new ListNode(x);
            temp = temp->next;
        }

        return dummy->next;
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
    int n1, n2;

    cout << "Enter size of first linked list: ";
    cin >> n1;

    ListNode* list1 = NULL;
    ListNode* tail1 = NULL;

    cout << "Enter first linked list elements: ";

    for(int i = 0; i < n1; i++)
    {
        int x;
        cin >> x;

        if(list1 == NULL)
        {
            list1 = new ListNode(x);
            tail1 = list1;
        }
        else
        {
            tail1->next = new ListNode(x);
            tail1 = tail1->next;
        }
    }

    cout << "Enter size of second linked list: ";
    cin >> n2;

    ListNode* list2 = NULL;
    ListNode* tail2 = NULL;

    cout << "Enter second linked list elements: ";

    for(int i = 0; i < n2; i++)
    {
        int x;
        cin >> x;

        if(list2 == NULL)
        {
            list2 = new ListNode(x);
            tail2 = list2;
        }
        else
        {
            tail2->next = new ListNode(x);
            tail2 = tail2->next;
        }
    }

    Solution obj;

    ListNode* ans = obj.mergeTwoLists(list1, list2);

    cout << "Merged Linked List: ";

    printList(ans);

    return 0;
}