// 3867 sum of gcd of formed  pairs
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

    // Custom GCD Function
    int gcd(int a, int b)
    {
        while(b != 0)
        {
            int temp = b;
            b = a % b;
            a = temp;
        }

        return a;
    }

    long long gcdSum(vector<int>& nums)
    {
        int n = nums.size();

        vector<int> pre(n);

        int mx = nums[0];

        for(int i = 0; i < n; i++)
        {
            mx = max(mx, nums[i]);

            pre[i] = gcd(nums[i], mx);
        }

        sort(pre.begin(), pre.end());

        long long ans = 0;

        int i = 0;
        int j = n - 1;

        while(i < j)
        {
            ans += gcd(pre[i], pre[j]);
            i++;
            j--;
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

    cout << "GCD Sum = " << obj.gcdSum(nums);

    return 0;
}