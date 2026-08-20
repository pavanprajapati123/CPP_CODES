//Maximum Difference Between Node and Ancestor
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
    int ans = INT_MIN;

    void solve(Node* root, int mx)
    {
        if(root == NULL)
            return;

        // Difference between ancestor and current node
        ans = max(ans, mx - root->data);

        // Current node becomes ancestor
        mx = max(mx, root->data);

        solve(root->left, mx);
        solve(root->right, mx);
    }

    int maxDiff(Node* root)
    {
        if(root == NULL)
            return 0;

        ans = INT_MIN;

        // Start comparison from children
        solve(root->left, root->data);
        solve(root->right, root->data);

        return ans;
    }
};

int main()
{
    /*
             8
            / \
           3   10
          / \
         1   6
    */

    Node* root = new Node(8);

    root->left = new Node(3);
    root->right = new Node(10);

    root->left->left = new Node(1);
    root->left->right = new Node(6);

    Solution obj;

    cout << "Maximum Difference = "
         << obj.maxDiff(root);

    return 0;
}