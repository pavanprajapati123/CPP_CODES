//Maximum Fruits
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxFruits(vector<int>& arr, int m)
    {
        int n = arr.size();

        // If m is greater than or equal to n,
        // we can take all fruits.
        if(m >= n)
        {
            int sum = 0;

            for(int x : arr)
                sum += x;

            return sum;
        }

        // Sum of first m elements
        int sum = 0;

        for(int i = 0; i < m; i++)
            sum += arr[i];

        int ans = sum;

        // Sliding window on circular array
        for(int i = m; i < n + m - 1; i++)
        {
            sum -= arr[(i - m) % n];
            sum += arr[i % n];

            ans = max(ans, sum);
        }

        return ans;
    }
};

int main()
{
    int n, m;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter array elements: ";

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter number of fruits to take: ";
    cin >> m;

    Solution obj;

    cout << "Maximum Fruits: "
         << obj.maxFruits(arr, m);

    return 0;
}