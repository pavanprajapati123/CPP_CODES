//minimum number of insertions and deletions 
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    int minInsAndDel(vector<int>& a, vector<int>& b)
    {
        int n = a.size();
        int m = b.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(a[i - 1] == b[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        int L = dp[n][m];

        return (n - L) + (m - L);
    }
};

int main()
{
    int n, m;

    cout << "Enter size of first array: ";
    cin >> n;

    vector<int> a(n);

    cout << "Enter first array elements: ";
    for(int i = 0; i < n; i++)
        cin >> a[i];

    cout << "Enter size of second array: ";
    cin >> m;

    vector<int> b(m);

    cout << "Enter second array elements: ";
    for(int i = 0; i < m; i++)
        cin >> b[i];

    Solution obj;

    cout << "Minimum Insertions and Deletions = "
         << obj.minInsAndDel(a, b);

    return 0;
}