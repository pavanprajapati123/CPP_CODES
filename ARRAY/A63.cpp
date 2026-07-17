//Max absolute difference of two subarrays
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution {
public:

    int maxDiffSubArrays(vector<int>& arr)
    {
        int n = arr.size();

        vector<int> pre(n + 1, 0);

        for(int i = 0; i < n; i++)
            pre[i + 1] = pre[i] + arr[i];

        int ans = 0;

        for(int l1 = 0; l1 < n; l1++)
        {
            for(int r1 = l1; r1 < n; r1++)
            {
                int sum1 = pre[r1 + 1] - pre[l1];

                for(int l2 = 0; l2 < n; l2++)
                {
                    for(int r2 = l2; r2 < n; r2++)
                    {
                        if(r1 < l2 || r2 < l1)
                        {
                            int sum2 = pre[r2 + 1] - pre[l2];

                            ans = max(ans, abs(sum1 - sum2));
                        }
                    }
                }
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
        cin >> arr[i];

    Solution obj;

    cout << "Maximum Difference = "
         << obj.maxDiffSubArrays(arr);

    return 0;
}