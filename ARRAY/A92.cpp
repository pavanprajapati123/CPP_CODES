//Minimum Cost Selection
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minCost(vector<vector<int>>& mat)
    {
        int n = mat.size();

        int a = mat[0][0];
        int b = mat[0][1];
        int c = mat[0][2];

        for(int i = 1; i < n; i++)
        {
            int x = mat[i][0] + min(b, c);
            int y = mat[i][1] + min(a, c);
            int z = mat[i][2] + min(a, b);

            a = x;
            b = y;
            c = z;
        }

        return min({a, b, c});
    }
};

int main()
{
    int n;

    cout << "Enter number of rows: ";
    cin >> n;

    vector<vector<int>> mat(n, vector<int>(3));

    cout << "Enter cost matrix:\n";

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            cin >> mat[i][j];
        }
    }

    Solution obj;

    cout << "Minimum Cost = "
         << obj.minCost(mat);

    return 0;
}