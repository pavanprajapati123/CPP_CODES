//Subarrays with Sum in Range
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    long long atMost(vector<int>& arr, long long x)
    {
        if(x < 0)
            return 0;

        long long ans = 0;
        long long sum = 0;

        int left = 0;

        for(int right = 0; right < arr.size(); right++)
        {
            sum += arr[right];

            while(sum > x)
            {
                sum -= arr[left];
                left++;
            }

            ans += (right - left + 1);
        }

        return ans;
    }

    int countSubarray(vector<int>& arr, int l, int r)
    {
        return atMost(arr, r) - atMost(arr, l - 1);
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
    {
        cin >> arr[i];
    }

    int l, r;

    cout << "Enter range (l r): ";
    cin >> l >> r;

    Solution obj;

    cout << "Count of Subarrays = "
         << obj.countSubarray(arr, l, r);

    return 0;
}