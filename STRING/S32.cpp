// Maximum Index Difference Using DP and Binary Search
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxIndexDifference(string &s)
    {
        int n = s.size();

        vector<vector<int>> pos(26);

        for(int i = 0; i < n; i++)
        {
            pos[s[i] - 'a'].push_back(i);
        }

        // f[c][i] = Maximum reachable index
        vector<vector<int>> f(26);

        // Base Case for 'z'
        f[25].resize(pos[25].size());

        for(int i = 0; i < (int)pos[25].size(); i++)
        {
            f[25][i] = pos[25][i];
        }

        // Process from 'y' to 'a'
        for(int c = 24; c >= 0; c--)
        {
            int sz = pos[c].size();

            f[c].resize(sz);

            if(sz == 0)
                continue;

            int nxt = c + 1;

            if(pos[nxt].empty())
            {
                for(int i = 0; i < sz; i++)
                {
                    f[c][i] = pos[c][i];
                }
                continue;
            }

            int nsz = pos[nxt].size();

            vector<int> suffixMax(nsz);

            suffixMax[nsz - 1] = f[nxt][nsz - 1];

            for(int i = nsz - 2; i >= 0; i--)
            {
                suffixMax[i] = max(f[nxt][i], suffixMax[i + 1]);
            }

            for(int i = 0; i < sz; i++)
            {
                int p = pos[c][i];

                int idx = upper_bound(pos[nxt].begin(),
                                      pos[nxt].end(),
                                      p) - pos[nxt].begin();

                if(idx == nsz)
                {
                    f[c][i] = p;
                }
                else
                {
                    f[c][i] = max(p, suffixMax[idx]);
                }
            }
        }

        if(pos[0].empty())
            return -1;

        int ans = -1;

        for(int i = 0; i < (int)pos[0].size(); i++)
        {
            int p = pos[0][i];

            ans = max(ans, f[0][i] - p);
        }

        return ans;
    }
};

int main()
{
    string s;

    cout << "Enter String: ";
    cin >> s;

    Solution obj;

    cout << "Maximum Index Difference = "
         << obj.maxIndexDifference(s);

    return 0;
}