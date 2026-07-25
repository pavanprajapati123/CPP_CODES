// max sum square submatrix of size k
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maximumSum(vector<vector<int>>& mat, int k)
    {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> pre(n + 1, vector<int>(m + 1, 0));

        // Build 2D Prefix Sum
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                pre[i][j] = mat[i - 1][j - 1]
                          + pre[i - 1][j]
                          + pre[i][j - 1]
                          - pre[i - 1][j - 1];
            }
        }

        int ans = INT_MIN;

        // Find Maximum Sum of k x k Submatrix
        for(int i = k; i <= n; i++)
        {
            for(int j = k; j <= m; j++)
            {
                int sum = pre[i][j]
                        - pre[i - k][j]
                        - pre[i][j - k]
                        + pre[i - k][j - k];

                ans = max(ans, sum);
            }
        }

        return ans;
    }
};

int main()
{
    int n, m;

    cout << "Enter number of rows and columns: ";
    cin >> n >> m;

    vector<vector<int>> mat(n, vector<int>(m));

    cout << "Enter matrix elements:\n";

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
        }
    }

    int k;

    cout << "Enter value of k: ";
    cin >> k;

    Solution obj;

    cout << "Maximum Sum = "
         << obj.maximumSum(mat, k);

    return 0;
}