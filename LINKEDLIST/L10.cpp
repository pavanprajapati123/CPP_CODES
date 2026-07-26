// 
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Solution
{
public:
    Node* reverse(Node* head)
    {
        Node *prev = NULL;
        Node *curr = head;

        while(curr)
        {
            Node *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    Node* addOne(Node *head)
    {
        head = reverse(head);

        Node *curr = head;
        int carry = 1;

        while(curr)
        {
            int sum = curr->data + carry;

            curr->data = sum % 10;
            carry = sum / 10;

            if(carry == 0)
                break;

            if(curr->next == NULL && carry)
            {
                curr->next = new Node(carry);
                carry = 0;
                break;
            }

            curr = curr->next;
        }

        return reverse(head);
    }
};

void printList(Node *head)
{
    while(head)
    {
        cout << head->data;
        if(head->next)
            cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(9);
    head->next->next = new Node(9);

    cout << "Original Number: ";
    printList(head);

    Solution obj;

    head = obj.addOne(head);

    cout << "After Adding One: ";
    printList(head);

    return 0;
}