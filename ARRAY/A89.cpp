//Raksha Bandhan
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int rakshaBandhan(vector<int> arr, int n)
    {
        sort(arr.begin(), arr.end());

        long long sum = 0;
        int ans = 0;

        for(int i = n - 1; i >= 0; i--)
        {
            if(sum + arr[i] <= 0)
                break;

            sum += arr[i];
            ans++;
        }

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
    {
        cin >> arr[i];
    }

    Solution obj;

    cout << "Maximum Count = "
         << obj.rakshaBandhan(arr, n);

    return 0;
}