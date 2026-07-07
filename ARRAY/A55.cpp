//35 search insert position
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    int searchInsert(vector<int>& nums, int target)
    {
        int start = 0;
        int end = nums.size() - 1;
        int ans = nums.size();

        while(start <= end)
        {
            int mid = start + (end - start) / 2;

            if(nums[mid] == target)
            {
                return mid;
            }
            else if(nums[mid] < target)
            {
                start = mid + 1;
            }
            else
            {
                ans = mid;
                end = mid - 1;
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

    vector<int> nums(n);

    cout << "Enter sorted array elements: ";
    for(int i = 0; i < n; i++)
        cin >> nums[i];

    int target;

    cout << "Enter target: ";
    cin >> target;

    Solution obj;

    cout << "Insert Position = "
         << obj.searchInsert(nums, target);

    return 0;
}