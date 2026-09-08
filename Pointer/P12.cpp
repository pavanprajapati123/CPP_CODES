//Palindrome Linked List
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class Solution
{
public:
    bool isPalindrome(Node* head)
    {
        if(head == NULL || head->next == NULL)
            return true;

        Node* slow = head;
        Node* fast = head;

        // Find the middle of linked list
        while(fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse second half
        Node* prev = NULL;
        Node* curr = slow;

        while(curr != NULL)
        {
            Node* nextNode = curr->next;

            curr->next = prev;

            prev = curr;
            curr = nextNode;
        }

        // Compare first half and reversed second half
        Node* left = head;
        Node* right = prev;

        while(right != NULL)
        {
            if(left->data != right->data)
                return false;

            left = left->next;
            right = right->next;
        }

        return true;
    }
};

void printList(Node* head)
{
    while(head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

int main()
{
    int n;

    cout << "Enter size of linked list: ";
    cin >> n;

    Node* head = NULL;
    Node* tail = NULL;

    cout << "Enter linked list elements: ";

    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        Node* newNode = new Node(x);

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

    if(obj.isPalindrome(head))
        cout << "true";
    else
        cout << "false";

    return 0;
}