//2265. Count Nodes Equal to Average of Subtree
#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

class Solution
{
public:
    unordered_map<TreeNode*, pair<int, int>> info;

    pair<int, int> dfs(TreeNode* root)
    {
        if(root == nullptr)
            return {0, 0};

        auto left = dfs(root->left);
        auto right = dfs(root->right);

        int sum = root->val + left.first + right.first;
        int count = 1 + left.second + right.second;

        info[root] = {sum, count};

        return {sum, count};
    }

    int countAnswer(TreeNode* root)
    {
        if(root == nullptr)
            return 0;

        int ans = 0;

        int sum = info[root].first;
        int count = info[root].second;

        if(root->val == sum / count)
            ans++;

        ans += countAnswer(root->left);
        ans += countAnswer(root->right);

        return ans;
    }

    int averageOfSubtree(TreeNode* root)
    {
        dfs(root);

        return countAnswer(root);
    }
};

int main()
{
    /*
        Example Tree:

              4
             / \
            8   5
           / \   \
          0   1   6
    */

    TreeNode* root = new TreeNode(4);

    root->left = new TreeNode(8);
    root->right = new TreeNode(5);

    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(1);

    root->right->right = new TreeNode(6);

    Solution obj;

    cout << "Number of Nodes: "
         << obj.averageOfSubtree(root);

    return 0;
}