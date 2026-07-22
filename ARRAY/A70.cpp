//  maximum deletions to make array sorted
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minDeletions(vector<int>& arr)
    {
        int n = arr.size();

        vector<int> dp(n, 1);

        int lis = 1;

        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(arr[j] < arr[i])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }

            lis = max(lis, dp[i]);
        }

        return n - lis;
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

    cout << "Minimum Deletions = "
         << obj.minDeletions(arr);

    return 0;
}