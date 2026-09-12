//Max Product Subsequence of Size K
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProduct(vector<int>& arr, int k)
    {
        const long long INF = 1e18;

        vector<long long> mn(k + 1, INF);
        vector<long long> mx(k + 1, -INF);

        mn[0] = mx[0] = 1;

        for (int x : arr)
        {
            for (int j = k; j >= 1; j--)
            {
                long long oldMax = mx[j - 1];
                long long oldMin = mn[j - 1];

                if (oldMax != -INF)
                {
                    mx[j] = max(mx[j], oldMax * x);
                    mn[j] = min(mn[j], oldMax * x);
                }

                if (oldMin != INF)
                {
                    mx[j] = max(mx[j], oldMin * x);
                    mn[j] = min(mn[j], oldMin * x);
                }
            }
        }

        return (int)mx[k];
    }
};

int main()
{
    Solution obj;

    vector<int> arr = {2, 3, -2, 4};
    int k = 2;

    cout << obj.maxProduct(arr, k);

    return 0;
}