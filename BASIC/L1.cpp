#include <iostream>
using namespace std;

// ================= NODE =================
class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

// ================= SIZE =================
int getSize(Node *head)
{
    int count = 0;
    Node *temp = head;

    while (temp != nullptr)
    {
        count++;
        temp = temp->next;
    }

    return count;
}

// ================= INSERT =================
void insertAtHead(Node *&head, int val)
{
    Node *newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

void insertAtTail(Node *&head, int val)
{
    if (head == nullptr)
    {
        insertAtHead(head, val);
        return;
    }

    Node *newNode = new Node(val);

    Node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

void insertAtPosition(Node *&head, int pos, int val)
{
    int size = getSize(head);

    if (pos < 1 || pos > size + 1)
    {
        cout << "Invalid position\n";
        return;
    }

    if (pos == 1)
    {
        insertAtHead(head, val);
        return;
    }

    if (pos == size + 1)
    {
        insertAtTail(head, val);
        return;
    }

    Node *temp = head;
    int i = 1;

    while (i < pos - 1)
    {
        temp = temp->next;
        i++;
    }

    Node *newNode = new Node(val);
    newNode->next = temp->next;
    temp->next = newNode;
}

// ================= PRINT =================
void printList(Node *head)
{
    Node *temp = head;

    while (temp != nullptr)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

// ================= MAIN =================
int main()
{
    Node *head = nullptr;

    insertAtHead(head, 10);
    insertAtTail(head, 20);
    insertAtTail(head, 30);
    insertAtPosition(head, 2, 15);
    insertAtPosition(head, 5, 40);

    cout << "Linked List: ";
    printList(head);

    cout << "Size of list: " << getSize(head) << endl;

    return 0;
}