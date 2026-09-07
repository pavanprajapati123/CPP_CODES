///Delete Node from Linked List
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
    Node* deleteNode(Node* head, int pos)
    {
        if(head == NULL)
            return head;

        // Delete first node
        if(pos == 0)
        {
            Node* temp = head;
            head = head->next;

            delete temp;

            return head;
        }

        Node* curr = head;

        // Reach the node before the node to delete
        for(int i = 0; i < pos - 1 && curr->next != NULL; i++)
        {
            curr = curr->next;
        }

        // Position is out of range
        if(curr->next == NULL)
            return head;

        // Delete the required node
        Node* temp = curr->next;

        curr->next = curr->next->next;

        delete temp;

        return head;
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

    int pos;

    cout << "Enter position to delete: ";
    cin >> pos;

    Solution obj;

    head = obj.deleteNode(head, pos);

    cout << "Linked List after deletion: ";
    printList(head);

    return 0;
}