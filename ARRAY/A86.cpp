//ind the Single Element in Sorted Array
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int getSingleElement(vector<int>& arr)
    {
        int n = arr.size();

        if(n == 1)
            return arr[0];

        int low = 0;
        int high = n - 1;

        while(low <= high)
        {
            int mid = low + (high - low) / 2;

            // Make mid even
            if(mid % 2 == 1)
                mid--;

            // Pair is correct: (mid, mid+1)
            if(mid + 1 < n && arr[mid] == arr[mid + 1])
            {
                low = mid + 2;
            }
            else
            {
                high = mid - 1;
            }
        }

        return arr[low];
    }
};

int main()
{
    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter sorted array elements: ";

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Solution obj;

    cout << "Single Element = "
         << obj.getSingleElement(arr);

    return 0;
}