// longest bitonic subarray
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

    int bitonic(vector<int>& arr)
    {
        int n = arr.size();

        vector<int> inc(n, 1), dec(n, 1);

        // Increasing Part
        for(int i = 1; i < n; i++)
        {
            if(arr[i] >= arr[i - 1])
                inc[i] = inc[i - 1] + 1;
        }

        // Decreasing Part
        for(int i = n - 2; i >= 0; i--)
        {
            if(arr[i] >= arr[i + 1])
                dec[i] = dec[i + 1] + 1;
        }

        int ans = 1;

        for(int i = 0; i < n; i++)
        {
            ans = max(ans, inc[i] + dec[i] - 1);
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
        cin >> arr[i];

    Solution obj;

    cout << "Longest Bitonic Subarray Length = "
         << obj.bitonic(arr);

    return 0;
}