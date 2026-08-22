//Question: Number of Turns Between Two Nodes
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

    bool findPath(Node* root, int x, string& path)
    {
        if(root == NULL)
            return false;

        if(root->data == x)
            return true;

        path.push_back('L');

        if(findPath(root->left, x, path))
            return true;

        path.pop_back();

        path.push_back('R');

        if(findPath(root->right, x, path))
            return true;

        path.pop_back();

        return false;
    }

    int numberOfTurns(Node* root, int p, int q)
    {
        string pathP, pathQ;

        if(!findPath(root, p, pathP) ||
           !findPath(root, q, pathQ))
        {
            return -1;
        }

        // Find LCA position
        int i = 0;

        while(i < pathP.size() &&
              i < pathQ.size() &&
              pathP[i] == pathQ[i])
        {
            i++;
        }

        string path = "";

        // p -> LCA
        for(int j = pathP.size() - 1; j >= i; j--)
        {
            path += pathP[j];
        }

        // LCA -> q
        for(int j = i; j < pathQ.size(); j++)
        {
            path += pathQ[j];
        }

        // Count direction changes
        int turns = 0;

        for(int j = 1; j < path.size(); j++)
        {
            if(path[j] != path[j - 1])
                turns++;
        }

        // No direction change
        if(turns == 0)
            return -1;

        return turns;
    }
};

int main()
{
    /*
              1
             / \
            2   3
           / \   \
          4   5   6
             / \
            7   8
    */

    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->right = new Node(6);

    root->left->right->left = new Node(7);
    root->left->right->right = new Node(8);

    Solution obj;

    cout << "Number of Turns = "
         << obj.numberOfTurns(root, 4, 8);

    return 0;
}