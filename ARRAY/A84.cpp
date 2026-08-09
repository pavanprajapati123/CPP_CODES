//Find The Single Element
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int getSingleElement(vector<int>& arr)
    {
        int ans = 0;

        for(int x : arr)
        {
            ans ^= x;
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

    cout << "Single Element = "
         << obj.getSingleElement(arr);

    return 0;
}