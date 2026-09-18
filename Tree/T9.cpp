#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
public:
    int ans;
    int prev;

    void inorder(Node* root)
    {
        if (root == nullptr)
            return;

        inorder(root->left);

        if (prev != -1)
        {
            ans = min(ans, root->data - prev);
        }

        prev = root->data;

        inorder(root->right);
    }

    int absDiff(Node* root)
    {
        // Reset for every test case
        ans = INT_MAX;
        prev = -1;

        inorder(root);

        return ans;
    }
};

int main()
{
    Solution obj;

    /*
             10
            /  \
           5    15
          / \
         3   7
    */

    Node* root = new Node(10);

    root->left = new Node(5);
    root->right = new Node(15);

    root->left->left = new Node(3);
    root->left->right = new Node(7);

    cout << obj.absDiff(root);

    return 0;
}