// reverse a doubly linked list
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int x)
    {
        data = x;
        prev = NULL;
        next = NULL;
    }
};

class Solution
{
public:
    Node* reverseDLL(Node* head)
    {
        if(head == NULL || head->next == NULL)
            return head;

        Node* curr = head;
        Node* temp = NULL;

        while(curr != NULL)
        {
            temp = curr->prev;
            curr->prev = curr->next;
            curr->next = temp;

            curr = curr->prev;
        }

        return temp->prev;
    }
};

void printList(Node* head)
{
    while(head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;

    head->next->next = new Node(3);
    head->next->next->prev = head->next;

    head->next->next->next = new Node(4);
    head->next->next->next->prev = head->next->next;

    cout << "Original Doubly Linked List: ";
    printList(head);

    Solution obj;

    head = obj.reverseDLL(head);

    cout << "Reversed Doubly Linked List: ";
    printList(head);

    return 0;
}