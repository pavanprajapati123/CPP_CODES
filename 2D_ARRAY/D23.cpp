//Max Sum Subarray of Size at least K
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxSumWithK(vector<int>& arr, int k)
    {
        int n = arr.size();

        vector<int> maxEnd(n);

        maxEnd[0] = arr[0];

        // Kadane DP
        for(int i = 1; i < n; i++)
        {
            maxEnd[i] = max(arr[i], maxEnd[i - 1] + arr[i]);
        }

        int sum = 0;

        // First window of size k
        for(int i = 0; i < k; i++)
        {
            sum += arr[i];
        }

        int ans = sum;

        // Sliding Window
        for(int i = k; i < n; i++)
        {
            sum += arr[i];
            sum -= arr[i - k];

            // Subarray of exactly k elements
            ans = max(ans, sum);

            // Extend with previous maximum subarray
            ans = max(ans, sum + maxEnd[i - k]);
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

    int k;

    cout << "Enter value of k: ";
    cin >> k;

    Solution obj;

    cout << "Maximum Sum = "
         << obj.maxSumWithK(arr, k);

    return 0;
}