//Subsets with Products of Distinct Primes
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    const int MOD = 1000000007;
    const vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

    int countSubsets(vector<int> &arr)
    {
        vector<int> freq(31, 0);

        for(int x : arr)
        {
            freq[x]++;
        }

        vector<int> mask(31, -1);

        for(int x = 2; x <= 30; x++)
        {
            int t = x;
            int m = 0;
            bool ok = true;

            for(int i = 0; i < 10; i++)
            {
                int cnt = 0;

                while(t % primes[i] == 0)
                {
                    t /= primes[i];
                    cnt++;
                }

                if(cnt > 1)
                {
                    ok = false;
                    break;
                }

                if(cnt == 1)
                {
                    m |= (1 << i);
                }
            }

            if(ok && t == 1)
            {
                mask[x] = m;
            }
        }

        vector<long long> dp(1 << 10, 0);
        dp[0] = 1;

        for(int x = 2; x <= 30; x++)
        {
            if(freq[x] == 0 || mask[x] == -1)
            {
                continue;
            }

            vector<long long> ndp = dp;

            for(int s = 0; s < (1 << 10); s++)
            {
                if((s & mask[x]) == 0)
                {
                    ndp[s | mask[x]] =
                        (ndp[s | mask[x]] + dp[s] * freq[x]) % MOD;
                }
            }

            dp = ndp;
        }

        long long ans = 0;

        for(int s = 1; s < (1 << 10); s++)
        {
            ans = (ans + dp[s]) % MOD;
        }

        long long ways = 1;

        while(freq[1]--)
        {
            ways = (ways * 2) % MOD;
        }

        ans = (ans * ways) % MOD;

        return (int)ans;
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

    cout << "Count of Good Subsets = "
         << obj.countSubsets(arr);

    return 0;
}