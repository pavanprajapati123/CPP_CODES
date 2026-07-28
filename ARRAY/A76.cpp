//347 top K Frequent Elements
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution
{
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        unordered_map<int, int> freq;

        for(int num : nums)
        {
            freq[num]++;
        }

        priority_queue<pair<int, int>,
                       vector<pair<int, int>>,
                       greater<pair<int, int>>> pq;

        for(auto it : freq)
        {
            pq.push({it.second, it.first});

            if(pq.size() > k)
            {
                pq.pop();
            }
        }

        vector<int> ans;

        while(!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};

int main()
{
    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter array elements: ";

    for(int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    int k;

    cout << "Enter value of k: ";
    cin >> k;

    Solution obj;

    vector<int> ans = obj.topKFrequent(nums, k);

    cout << "Top " << k << " Frequent Elements: ";

    for(int x : ans)
    {
        cout << x << " ";
    }

    return 0;
}