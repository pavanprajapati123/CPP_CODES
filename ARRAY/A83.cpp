//Find Duplicates In Array
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> findDuplicates(vector<int> &arr, int n)
    {
        vector<int> freq(n, 0);
        vector<int> ans;

        for(int x : arr)
        {
            freq[x]++;
        }

        for(int i = 0; i < n; i++)
        {
            if(freq[i] > 1)
            {
                ans.push_back(i);
            }
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

    vector<int> ans = obj.findDuplicates(arr, n);

    if(ans.empty())
    {
        cout << "No Duplicate Elements";
    }
    else
    {
        cout << "Duplicate Elements: ";

        for(int x : ans)
        {
            cout << x << " ";
        }
    }

    return 0;
}