//
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> arrangeGame(vector<int>& arr)
    {
        int n = arr.size();

        // Count number of 1s
        int cnt = 0;

        for(int x : arr)
        {
            if(x == 1)
                cnt++;
        }

        vector<int> ans;

        // Put all 1s first
        for(int i = 0; i < cnt; i++)
        {
            ans.push_back(1);
        }

        // Store remaining elements
        vector<int> v;

        for(int x : arr)
        {
            if(x != 1)
            {
                v.push_back(x);
            }
        }

        // Sort remaining elements in descending order
        sort(v.begin(), v.end(), greater<int>());

        // Special case
        if(v.size() == 2 && v[0] == 3 && v[1] == 2)
        {
            swap(v[0], v[1]);
        }

        // Add remaining elements
        for(int x : v)
        {
            ans.push_back(x);
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

    vector<int> ans = obj.arrangeGame(arr);

    cout << "Arranged Array: ";

    for(int x : ans)
    {
        cout << x << " ";
    }

    return 0;
}