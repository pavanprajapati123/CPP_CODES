//Check Whether Preorder Can Represent BST
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution
{
public:
    bool check(vector<int>& arr, int l, int r, int mn, int mx)
    {
        if(l > r)
            return true;

        int root = arr[l];

        if(root < mn || root > mx)
            return false;

        int i = l + 1;

        while(i <= r && arr[i] < root)
            i++;

        for(int j = i; j <= r; j++)
        {
            if(arr[j] < root)
                return false;
        }

        return check(arr, l + 1, i - 1, mn, root - 1) &&
               check(arr, i, r, root + 1, mx);
    }

    bool canRepresentBST(vector<int>& arr)
    {
        return check(arr, 0, arr.size() - 1, INT_MIN, INT_MAX);
    }
};

int main()
{
    int n;

    cout << "Enter size of preorder array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter preorder elements: ";

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Solution obj;

    if(obj.canRepresentBST(arr))
        cout << "Yes, it can represent a BST.";
    else
        cout << "No, it cannot represent a BST.";

    return 0;
}