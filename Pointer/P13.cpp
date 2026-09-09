//Search Word in Matrix
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> searchWord(vector<vector<char>>& mat, string& word)
    {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> ans;

        // 8 possible directions
        int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                // First character doesn't match
                if(mat[i][j] != word[0])
                    continue;

                bool found = false;

                // Check all 8 directions
                for(int d = 0; d < 8 && !found; d++)
                {
                    int x = i;
                    int y = j;
                    int k;

                    for(k = 1; k < word.size(); k++)
                    {
                        x += dx[d];
                        y += dy[d];

                        // Out of matrix
                        if(x < 0 || x >= n || y < 0 || y >= m)
                            break;

                        // Character doesn't match
                        if(mat[x][y] != word[k])
                            break;
                    }

                    if(k == word.size())
                        found = true;
                }

                if(found)
                    ans.push_back({i, j});
            }
        }

        return ans;
    }
};

int main()
{
    int n, m;

    cout << "Enter rows and columns: ";
    cin >> n >> m;

    vector<vector<char>> mat(n, vector<char>(m));

    cout << "Enter matrix characters: ";

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
        }
    }

    string word;

    cout << "Enter word: ";
    cin >> word;

    Solution obj;

    vector<vector<int>> ans = obj.searchWord(mat, word);

    cout << "Starting Positions: ";

    for(auto p : ans)
    {
        cout << "(" << p[0] << ", " << p[1] << ") ";
    }

    return 0;
}