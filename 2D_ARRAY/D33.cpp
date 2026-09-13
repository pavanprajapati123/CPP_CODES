//835 image overlap
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2)
    {
        int n = img1.size();
        int ans = 0;

        // Try every possible shift
        for (int dr = -(n - 1); dr <= n - 1; dr++)
        {
            for (int dc = -(n - 1); dc <= n - 1; dc++)
            {
                int overlap = 0;

                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < n; j++)
                    {
                        int ni = i + dr;
                        int nj = j + dc;

                        if (ni >= 0 && ni < n &&
                            nj >= 0 && nj < n &&
                            img1[i][j] == 1 &&
                            img2[ni][nj] == 1)
                        {
                            overlap++;
                        }
                    }
                }

                ans = max(ans, overlap);
            }
        }

        return ans;
    }
};

int main()
{
    Solution obj;

    vector<vector<int>> img1 = {
        {1, 1, 0},
        {0, 1, 0},
        {0, 1, 0}
    };

    vector<vector<int>> img2 = {
        {0, 0, 0},
        {0, 1, 1},
        {0, 0, 1}
    };

    cout << obj.largestOverlap(img1, img2);

    return 0;
}