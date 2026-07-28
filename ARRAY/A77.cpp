//Split Array into Minimum Subsets
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minSubsets(vector<int>& arr)
    {
        sort(arr.begin(), arr.end());

        int cnt = 1;

        for(int i = 1; i < arr.size(); i++)
        {
            if(arr[i] != arr[i - 1] + 1)
            {
                cnt++;
            }
        }

        return cnt;
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

    cout << "Minimum Number of Subsets = "
         << obj.minSubsets(arr);

    return 0;
}