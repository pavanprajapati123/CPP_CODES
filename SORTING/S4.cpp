//3754 concatination of two strings
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

    int largestArea(int n, int m, vector<vector<int>> &arr)
    {
        vector<int> rows, cols;

        for(auto &it : arr)
        {
            rows.push_back(it[0]);
            cols.push_back(it[1]);
        }

        sort(rows.begin(), rows.end());
        sort(cols.begin(), cols.end());

        int maxRows = rows.empty() ? n : max(rows[0] - 1, n - rows.back());
        int maxCols = cols.empty() ? m : max(cols[0] - 1, m - cols.back());

        for(int i = 1; i < rows.size(); i++)
            maxRows = max(maxRows, rows[i] - rows[i - 1] - 1);

        for(int i = 1; i < cols.size(); i++)
            maxCols = max(maxCols, cols[i] - cols[i - 1] - 1);

        return maxRows * maxCols;
    }
};

int main()
{
    int n, m, k;

    cout << "Enter number of rows and columns: ";
    cin >> n >> m;

    cout << "Enter number of blocked cells: ";
    cin >> k;

    vector<vector<int>> arr(k, vector<int>(2));

    cout << "Enter blocked cell coordinates:\n";

    for(int i = 0; i < k; i++)
    {
        cin >> arr[i][0] >> arr[i][1];
    }

    Solution obj;

    cout << "Largest Area = "
         << obj.largestArea(n, m, arr);

    return 0;
}