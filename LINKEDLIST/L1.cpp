#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

class Solution {
public:
    bool hasCycle(ListNode *head) {

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
                return true;
        }

        return false;
    }
};

int main() {

    // Creating nodes
    ListNode* head = new ListNode(3);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(0);
    ListNode* fourth = new ListNode(-4);

    // Linking nodes
    head->next = second;
    second->next = third;
    third->next = fourth;

    // Creating cycle
    fourth->next = second;

    Solution obj;

    if (obj.hasCycle(head))
        cout << "Cycle Detected" << endl;
    else
        cout << "No Cycle" << endl;

    return 0;
}