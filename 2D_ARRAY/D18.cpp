// Wave Print of a 2D Array
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    vector<int> wavePrint(vector<vector<int>> arr, int nRows, int mCols)
    {
        vector<int> ans;

        for(int col = 0; col < mCols; col++)
        {
            if(col % 2 == 0)
            {
                for(int row = 0; row < nRows; row++)
                    ans.push_back(arr[row][col]);
            }
            else
            {
                for(int row = nRows - 1; row >= 0; row--)
                    ans.push_back(arr[row][col]);
            }
        }

        return ans;
    }
};

int main()
{
    int nRows, mCols;

    cout << "Enter rows and columns: ";
    cin >> nRows >> mCols;

    vector<vector<int>> arr(nRows, vector<int>(mCols));

    cout << "Enter matrix:\n";

    for(int i = 0; i < nRows; i++)
    {
        for(int j = 0; j < mCols; j++)
            cin >> arr[i][j];
    }

    Solution obj;

    vector<int> ans = obj.wavePrint(arr, nRows, mCols);

    cout << "Wave Print: ";

    for(int x : ans)
        cout << x << " ";

    return 0;
}