// level-wise sorting of an array
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> levelSort(vector<int>& arr)
    {
        vector<vector<int>> ans;

        int n = arr.size();
        int i = 0;
        int level = 1;

        while(i < n)
        {
            vector<int> temp;

            for(int j = 0; j < level && i < n; j++)
            {
                temp.push_back(arr[i]);
                i++;
            }

            sort(temp.begin(), temp.end());

            ans.push_back(temp);

            level *= 2;
        }

        return ans;
    }
};

int main()
{
    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter array elements: ";

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Solution obj;

    vector<vector<int>> ans = obj.levelSort(arr);

    cout << "\nLevel-wise Sorted Array:\n";

    for(int i = 0; i < ans.size(); i++)
    {
        cout << "Level " << i + 1 << ": ";

        for(int x : ans[i])
        {
            cout << x << " ";
        }

        cout << endl;
    }

    return 0;
}