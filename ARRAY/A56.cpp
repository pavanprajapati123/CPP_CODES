//smallest subarray with k distinct elements
#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
using namespace std;

class Solution {
public:

    vector<int> smallestSubarrayWithKDistinct(vector<int> &arr, int k)
    {
        unordered_map<int, int> mp;

        int left = 0;
        int start = -1;
        int minLen = INT_MAX;

        for(int right = 0; right < arr.size(); right++)
        {
            mp[arr[right]]++;

            while(mp.size() > k)
            {
                mp[arr[left]]--;

                if(mp[arr[left]] == 0)
                    mp.erase(arr[left]);

                left++;
            }

            while(mp.size() == k && mp[arr[left]] > 1)
            {
                mp[arr[left]]--;
                left++;
            }

            if(mp.size() == k)
            {
                if(right - left + 1 < minLen)
                {
                    minLen = right - left + 1;
                    start = left;
                }
            }
        }

        if(start == -1)
            return {-1};

        return {start, start + minLen - 1};
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

    int k;

    cout << "Enter value of k: ";
    cin >> k;

    Solution obj;

    vector<int> ans = obj.smallestSubarrayWithKDistinct(arr, k);

    if(ans.size() == 1 && ans[0] == -1)
    {
        cout << "No valid subarray found.";
    }
    else
    {
        cout << "Start Index = " << ans[0] << endl;
        cout << "End Index = " << ans[1] << endl;
    }

    return 0;
}