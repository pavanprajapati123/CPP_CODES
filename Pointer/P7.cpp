//2958 — Length of Longest Subarray With at Most K Frequency
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxSubarrayLength(vector<int>& nums, int k)
    {
        int n = nums.size();

        unordered_map<int, int> freq;

        int left = 0;
        int ans = 0;

        for(int right = 0; right < n; right++)
        {
            freq[nums[right]]++;

            while(freq[nums[right]] > k)
            {
                freq[nums[left]]--;
                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};

int main()
{
    int n, k;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter array elements: ";

    for(int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    cout << "Enter k: ";
    cin >> k;

    Solution obj;

    cout << "Maximum Subarray Length = "
         << obj.maxSubarrayLength(nums, k);

    return 0;
}