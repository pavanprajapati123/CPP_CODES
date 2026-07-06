//704. Binary Search
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    int binarySearch(vector<int>& nums, int low, int high, int target)
    {
        if(low > high)
            return -1;

        int mid = low + (high - low) / 2;

        if(nums[mid] == target)
            return mid;

        if(nums[mid] > target)
            return binarySearch(nums, low, mid - 1, target);

        return binarySearch(nums, mid + 1, high, target);
    }

    int search(vector<int>& nums, int target)
    {
        return binarySearch(nums, 0, nums.size() - 1, target);
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

    int index = obj.search(nums, target);

    cout << "Index = " << index;

    return 0;
}