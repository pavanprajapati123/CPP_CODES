//410 split array largest sum
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canSplit(vector<int>& nums, int k, int limit)
{
    int sum = 0;
    int parts = 1;

    for(int i = 0; i < nums.size(); i++)
    {
        if(sum + nums[i] <= limit)
        {
            sum += nums[i];
        }
        else
        {
            parts++;
            sum = nums[i];
        }
    }

    return parts <= k;
}

int splitArray(vector<int>& nums, int k)
{
    int low = *max_element(nums.begin(), nums.end());

    int high = 0;
    for(int x : nums)
        high += x;

    for(int limit = low; limit <= high; limit++)
    {
        if(canSplit(nums, k, limit))
            return limit;
    }

    return low;
}

int main()
{
    int n;

    cout << "Enter Size : ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter Elements : ";
    for(int i=0;i<n;i++)
        cin>>nums[i];

    int k;

    cout<<"Enter K : ";
    cin>>k;

    cout<<"Answer = "<<splitArray(nums,k);

    return 0;
}