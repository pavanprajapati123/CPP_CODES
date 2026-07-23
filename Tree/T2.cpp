//3513  number of unique xor triplets
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int uniqueXorTriplets(vector<int>& nums)
    {
        int n = nums.size();

        if(n == 1)
            return 1;

        if(n == 2)
            return 2;

        int ans = 1;

        while(ans <= n)
        {
            ans <<= 1;
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

    Solution obj;

    cout << "Unique XOR Triplets = "
         << obj.uniqueXorTriplets(nums);

    return 0;
}