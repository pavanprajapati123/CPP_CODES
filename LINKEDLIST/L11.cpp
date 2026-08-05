//Search in a Linked List
#include <iostream>
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node<T>* next;

    Node(T data)
    {
        this->data = data;
        next = NULL;
    }
};

class Solution
{
public:
    int searchInLinkedList(Node<int> *head, int k)
    {
        while(head != NULL)
        {
            if(head->data == k)
            {
                return 1;
            }

            head = head->next;
        }

        return 0;
    }
};

int main()
{
    int n;

    cout << "Enter number of nodes: ";
    cin >> n;

    Node<int>* head = NULL;
    Node<int>* tail = NULL;

    cout << "Enter node values: ";

    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        Node<int>* newNode = new Node<int>(x);

        if(head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    int k;

    cout << "Enter element to search: ";
    cin >> k;

    Solution obj;

    if(obj.searchInLinkedList(head, k))
        cout << "Element Found";
    else
        cout << "Element Not Found";

    return 0;
}