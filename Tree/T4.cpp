// Longest Consecutive Path in Binary Tree
#include <iostream>
#include <algorithm>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
public:

    int dfs(Node* root, int prev)
    {
        if(root == NULL)
            return 0;

        if(root->data != prev + 1)
            return 0;

        return 1 + max(dfs(root->left, root->data),
                       dfs(root->right, root->data));
    }

    int solve(Node* root)
    {
        if(root == NULL)
            return 0;

        int ans = max(dfs(root->left, root->data),
                      dfs(root->right, root->data));

        ans = max(ans + 1,
                  max(solve(root->left),
                      solve(root->right)));

        return ans;
    }

    int longestConsecutive(Node* root)
    {
        if(root == NULL)
            return -1;

        return solve(root);
    }
};

int main()
{
    /*
            1
           / \
          2   3
         /
        3
       /
      4

    Longest Consecutive Path = 4
    */

    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(3);
    root->left->left->left = new Node(4);

    Solution obj;

    cout << "Longest Consecutive Path = "
         << obj.longestConsecutive(root);

    return 0;
}