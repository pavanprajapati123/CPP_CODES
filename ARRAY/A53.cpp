// max sum path in two arrays
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

    int solve(vector<int>& a, vector<int>& b,
              int i, int j, bool first)
    {
        if(first)
        {
            if(i >= a.size())
                return 0;

            int ans = a[i] + solve(a, b, i + 1, j, true);

            while(j < b.size())
            {
                if(b[j] == a[i])
                {
                    ans = max(ans,
                              a[i] + solve(a, b, i + 1, j + 1, false));
                }
                j++;
            }

            return ans;
        }
        else
        {
            if(j >= b.size())
                return 0;

            int ans = b[j] + solve(a, b, i, j + 1, false);

            while(i < a.size())
            {
                if(a[i] == b[j])
                {
                    ans = max(ans,
                              b[j] + solve(a, b, i + 1, j + 1, true));
                }
                i++;
            }

            return ans;
        }
    }

    int maxPathSum(vector<int>& a, vector<int>& b)
    {
        return max(solve(a, b, 0, 0, true),
                   solve(a, b, 0, 0, false));
    }
};

int main()
{
    int n, m;

    cout << "Enter size of first array: ";
    cin >> n;

    vector<int> a(n);

    cout << "Enter first array: ";
    for(int i = 0; i < n; i++)
        cin >> a[i];

    cout << "Enter size of second array: ";
    cin >> m;

    vector<int> b(m);

    cout << "Enter second array: ";
    for(int i = 0; i < m; i++)
        cin >> b[i];

    Solution obj;

    cout << "Maximum Path Sum = "
         << obj.maxPathSum(a, b);

    return 0;
}