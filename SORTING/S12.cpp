//Maximum Number of Leaf Nodes with Given Cost
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
    int getCount(Node* root, int level, vector<int>& cost)
    {
        if (root == NULL)
            return 0;

        // Leaf node
        if (root->left == NULL && root->right == NULL)
        {
            cost.push_back(level);
            return 1;
        }

        getCount(root->left, level + 1, cost);
        getCount(root->right, level + 1, cost);

        return 0;
    }

    int getCount(Node* root, int k)
    {
        vector<int> cost;

        // Find cost of every leaf
        getCount(root, 1, cost);

        // Visit cheapest leaves first
        sort(cost.begin(), cost.end());

        int ans = 0;

        for (int c : cost)
        {
            if (k < c)
                break;

            k -= c;
            ans++;
        }

        return ans;
    }
};

int main()
{
    Solution obj;

    /*
             1
            / \
           2   3
          / \
         4   5

        Leaf nodes: 4, 5, 3
        Costs:      3, 3, 2
    */

    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    int k = 5;

    cout << obj.getCount(root, k);

    return 0;
}