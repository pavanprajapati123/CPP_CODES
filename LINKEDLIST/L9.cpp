// Delete a node in a linked list, given only access to that node
#include <iostream>
using namespace std;

template <typename T>
class LinkedListNode
{
public:
    T data;
    LinkedListNode<T> *next;

    LinkedListNode(T data)
    {
        this->data = data;
        next = NULL;
    }
};

class Solution
{
public:
    void deleteNode(LinkedListNode<int> *node)
    {
        LinkedListNode<int> *temp = node->next;

        node->data = temp->data;
        node->next = temp->next;

        delete temp;
    }
};

void printList(LinkedListNode<int> *head)
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
    LinkedListNode<int> *head = new LinkedListNode<int>(1);
    head->next = new LinkedListNode<int>(2);
    head->next->next = new LinkedListNode<int>(3);
    head->next->next->next = new LinkedListNode<int>(4);
    head->next->next->next->next = new LinkedListNode<int>(5);

    cout << "Original Linked List: ";
    printList(head);

    Solution obj;

    // Delete node having value 3
    obj.deleteNode(head->next->next);

    cout << "Linked List After Deletion: ";
    printList(head);

    return 0;
}