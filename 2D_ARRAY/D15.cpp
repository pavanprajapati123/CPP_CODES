// C++ program to set matrix zeroes in place
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m)
    {
        bool firstRow = false;
        bool firstCol = false;

        for(int j = 0; j < m; j++)
        {
            if(matrix[0][j] == 0)
            {
                firstRow = true;
                break;
            }
        }

        for(int i = 0; i < n; i++)
        {
            if(matrix[i][0] == 0)
            {
                firstCol = true;
                break;
            }
        }

        for(int i = 1; i < n; i++)
        {
            for(int j = 1; j < m; j++)
            {
                if(matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for(int i = 1; i < n; i++)
        {
            for(int j = 1; j < m; j++)
            {
                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }

        if(firstRow)
        {
            for(int j = 0; j < m; j++)
                matrix[0][j] = 0;
        }

        if(firstCol)
        {
            for(int i = 0; i < n; i++)
                matrix[i][0] = 0;
        }

        return matrix;
    }
};

int main()
{
    int n, m;

    cout << "Enter rows and columns: ";
    cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(m));

    cout << "Enter matrix:\n";

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
            cin >> matrix[i][j];
    }

    Solution obj;

    matrix = obj.zeroMatrix(matrix, n, m);

    cout << "\nResult Matrix:\n";

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
            cout << matrix[i][j] << " ";

        cout << endl;
    }

    return 0;
}