//1260. Shift 2D Grid
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k)
    {
        int m = grid.size();
        int n = grid[0].size();

        while(k--)
        {
            vector<vector<int>> temp = grid;

            temp[0][0] = grid[m - 1][n - 1];

            for(int i = 0; i < m; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    if(i == 0 && j == 0)
                        continue;

                    if(j == 0)
                        temp[i][0] = grid[i - 1][n - 1];
                    else
                        temp[i][j] = grid[i][j - 1];
                }
            }

            grid = temp;
        }

        return grid;
    }
};

int main()
{
    int m, n;

    cout << "Enter rows and columns: ";
    cin >> m >> n;

    vector<vector<int>> grid(m, vector<int>(n));

    cout << "Enter grid elements:\n";

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }

    int k;

    cout << "Enter number of shifts: ";
    cin >> k;

    Solution obj;

    vector<vector<int>> ans = obj.shiftGrid(grid, k);

    cout << "Shifted Grid:\n";

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}