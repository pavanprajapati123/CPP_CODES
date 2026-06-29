//  Painter Partition Problem
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:

    bool isPossible(vector<int>& arr, int k, int maxTime)
    {
        int painters = 1;
        int currSum = 0;

        for(int board : arr)
        {
            if(board > maxTime)
                return false;

            if(currSum + board <= maxTime)
            {
                currSum += board;
            }
            else
            {
                painters++;
                currSum = board;

                if(painters > k)
                    return false;
            }
        }

        return true;
    }

    int minTime(vector<int>& arr, int k)
    {
        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);

        int ans = high;

        while(low <= high)
        {
            int mid = low + (high - low) / 2;

            if(isPossible(arr, k, mid))
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return ans;
    }
};

int main()
{
    int n;

    cout << "Enter number of boards: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter board lengths: ";
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    int k;

    cout << "Enter number of painters: ";
    cin >> k;

    Solution obj;

    cout << "Minimum Time = "
         << obj.minTime(arr, k);

    return 0;
}