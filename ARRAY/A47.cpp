// C++ program to set matrix zeroes
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    void setZeros(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();

        bool firstRow = false;
        bool firstCol = false;

        // Check first row
        for(int j = 0; j < m; j++)
        {
            if(matrix[0][j] == 0)
            {
                firstRow = true;
                break;
            }
        }

        // Check first column
        for(int i = 0; i < n; i++)
        {
            if(matrix[i][0] == 0)
            {
                firstCol = true;
                break;
            }
        }

        // Mark rows and columns
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

        // Set zeros
        for(int i = 1; i < n; i++)
        {
            for(int j = 1; j < m; j++)
            {
                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        }

        // First row
        if(firstRow)
        {
            for(int j = 0; j < m; j++)
                matrix[0][j] = 0;
        }

        // First column
        if(firstCol)
        {
            for(int i = 0; i < n; i++)
                matrix[i][0] = 0;
        }
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
    obj.setZeros(matrix);

    cout << "\nMatrix after setting zeros:\n";

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
            cout << matrix[i][j] << " ";

        cout << endl;
    }

    return 0;
}