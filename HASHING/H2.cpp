// count pairs in an array whose sum is divisible by k
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    int countKdivPairs(vector<int>& arr, int k)
    {
        vector<int> freq(k, 0);

        for(int x : arr)
            freq[x % k]++;

        int ans = 0;

        // Pairs with remainder 0
        ans += freq[0] * (freq[0] - 1) / 2;

        // Pairs with remainder i and k-i
        for(int i = 1; i < (k + 1) / 2; i++)
            ans += freq[i] * freq[k - i];

        // Pairs when k is even
        if(k % 2 == 0)
            ans += freq[k / 2] * (freq[k / 2] - 1) / 2;

        return ans;
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

    cout << "Number of Pairs = "
         << obj.countKdivPairs(arr, k);

    return 0;
}