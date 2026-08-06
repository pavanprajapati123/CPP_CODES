//valid Pairing of Array Elements
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool isValidPair(vector<int> &arr, int n, int k, int m)
    {
        if(n % 2)
        {
            return false;
        }

        vector<int> freq(k, 0);

        for(int x : arr)
        {
            int rem = ((x % k) + k) % k;
            freq[rem]++;
        }

        vector<bool> vis(k, false);

        for(int r = 0; r < k; r++)
        {
            if(vis[r])
            {
                continue;
            }

            int need = (m - r + k) % k;

            if(r == need)
            {
                if(freq[r] % 2 != 0)
                {
                    return false;
                }
            }
            else
            {
                if(freq[r] != freq[need])
                {
                    return false;
                }
            }

            vis[r] = true;
            vis[need] = true;
        }

        return true;
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

    int k, m;

    cout << "Enter k and m: ";
    cin >> k >> m;

    Solution obj;

    if(obj.isValidPair(arr, n, k, m))
    {
        cout << "Valid Pairing Possible";
    }
    else
    {
        cout << "Valid Pairing Not Possible";
    }

    return 0;
}