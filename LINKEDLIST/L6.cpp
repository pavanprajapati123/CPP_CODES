// Merge Sort on Linked List
#include <iostream>
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

Node* findMid(Node* head)
{
    Node* slow = head;
    Node* fast = head->next;

    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

Node* merge(Node* left, Node* right)
{
    Node dummy(-1);
    Node* tail = &dummy;

    while(left != NULL && right != NULL)
    {
        if(left->data <= right->data)
        {
            tail->next = left;
            left = left->next;
        }
        else
        {
            tail->next = right;
            right = right->next;
        }

        tail = tail->next;
    }

    if(left)
        tail->next = left;
    else
        tail->next = right;

    return dummy.next;
}

Node* mergeSort(Node* head)
{
    if(head == NULL || head->next == NULL)
        return head;

    Node* mid = findMid(head);

    Node* right = mid->next;
    mid->next = NULL;

    Node* left = mergeSort(head);
    right = mergeSort(right);

    return merge(left, right);
}

void printList(Node* head)
{
    while(head)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

int main()
{
    Node* head = new Node(4);
    head->next = new Node(2);
    head->next->next = new Node(1);
    head->next->next->next = new Node(3);
    head->next->next->next->next = new Node(5);

    cout << "Original List: ";
    printList(head);

    head = mergeSort(head);

    cout << "\nSorted List: ";
    printList(head);

    return 0;
}