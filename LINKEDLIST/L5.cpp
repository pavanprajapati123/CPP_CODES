//  Flatten a Linked List
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *child;

    Node(int x)
    {
        data = x;
        next = NULL;
        child = NULL;
    }
};

Node* merge(Node* a, Node* b)
{
    if(a == NULL)
        return b;

    if(b == NULL)
        return a;

    if(a->data < b->data)
    {
        a->child = merge(a->child, b);
        a->next = NULL;
        return a;
    }
    else
    {
        b->child = merge(a, b->child);
        b->next = NULL;
        return b;
    }
}

Node* flattenLinkedList(Node* head)
{
    if(head == NULL || head->next == NULL)
        return head;

    head->next = flattenLinkedList(head->next);

    return merge(head, head->next);
}

void printList(Node* head)
{
    while(head)
    {
        cout << head->data << " ";
        head = head->child;
    }
}

int main()
{
    // Level 1
    Node* head = new Node(1);
    head->next = new Node(4);
    head->next->next = new Node(7);
    head->next->next->next = new Node(9);
    head->next->next->next->next = new Node(20);

    // Child Lists
    head->child = new Node(2);
    head->child->child = new Node(3);

    head->next->child = new Node(5);
    head->next->child->child = new Node(6);

    head->next->next->child = new Node(8);

    head->next->next->next->child = new Node(12);

    Node* ans = flattenLinkedList(head);

    cout << "Flatten Linked List: ";

    printList(ans);

    return 0;
}