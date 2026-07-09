//33 search in Rotated Sorted Array
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    int search(vector<int>& nums, int target)
    {
        int low = 0;
        int high = nums.size() - 1;

        while(low <= high)
        {
            int mid = low + (high - low) / 2;

            if(nums[mid] == target)
                return mid;

            // Left Half Sorted
            if(nums[low] <= nums[mid])
            {
                if(target >= nums[low] && target < nums[mid])
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            // Right Half Sorted
            else
            {
                if(target > nums[mid] && target <= nums[high])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }

        return -1;
    }
};

int main()
{
    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter rotated sorted array: ";
    for(int i = 0; i < n; i++)
        cin >> nums[i];

    int target;

    cout << "Enter target: ";
    cin >> target;

    Solution obj;

    cout << "Target Index = "
         << obj.search(nums, target);

    return 0;
}