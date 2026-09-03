//Maximum Difference Sum
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxDiffSum(vector<int>& arr)
    {
        int n = arr.size();

        if(n <= 1)
            return 0;

        long long dp0 = 0;
        long long dp1 = 0;

        for(int i = 1; i < n; i++)
        {
            long long new0 = max(
                dp0 + abs(arr[i] - arr[i - 1]),
                dp1 + abs(arr[i] - 1)
            );

            long long new1 = max(
                dp0 + abs(1 - arr[i - 1]),
                dp1
            );

            dp0 = new0;
            dp1 = new1;
        }

        return (int)max(dp0, dp1);
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

    cout << "Maximum Difference Sum: "
         << obj.maxDiffSum(arr);

    return 0;
}