//3501 Maximum Active Sections After Trade
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Group
{
    int start;
    int length;
};

class SparseTable
{
    int n;
    vector<vector<int>> st;

public:
    SparseTable(const vector<int> &nums)
    {
        n = nums.size();

        int LOG = 1;

        while((1 << LOG) <= n)
            LOG++;

        st.assign(LOG + 1, vector<int>(n));

        st[0] = nums;

        for(int i = 1; i <= LOG; i++)
        {
            for(int j = 0; j + (1 << i) <= n; j++)
            {
                st[i][j] = max(st[i - 1][j],
                               st[i - 1][j + (1 << (i - 1))]);
            }
        }
    }

    int query(int l, int r)
    {
        int len = r - l + 1;

        int k = 31 - __builtin_clz(len);

        return max(st[k][l],
                   st[k][r - (1 << k) + 1]);
    }
};

class Solution
{
public:
    vector<int> maxActiveSectionsAfterTrade(string s,
                                            vector<vector<int>> &queries)
    {
        int n = s.size();

        int ones = 0;

        for(char c : s)
        {
            if(c == '1')
                ones++;
        }

        vector<Group> zeroGroups;

        vector<int> zeroGroupIndex(n);

        for(int i = 0; i < n; i++)
        {
            if(s[i] == '0')
            {
                if(i > 0 && s[i - 1] == '0')
                    zeroGroups.back().length++;
                else
                    zeroGroups.push_back({i, 1});
            }

            zeroGroupIndex[i] = (int)zeroGroups.size() - 1;
        }

        int qn = queries.size();

        if(zeroGroups.empty())
            return vector<int>(qn, ones);

        vector<int> zeroMergeLengths;

        for(int i = 0; i + 1 < (int)zeroGroups.size(); i++)
        {
            zeroMergeLengths.push_back(
                zeroGroups[i].length +
                zeroGroups[i + 1].length);
        }

        SparseTable *st = NULL;

        if(!zeroMergeLengths.empty())
            st = new SparseTable(zeroMergeLengths);

        vector<int> ans;

        ans.reserve(qn);

        for(auto &query : queries)
        {
            int l = query[0];
            int r = query[1];

            int left =
                (zeroGroupIndex[l] == -1)
                    ? -1
                    : (zeroGroups[zeroGroupIndex[l]].length -
                       (l - zeroGroups[zeroGroupIndex[l]].start));

            int right =
                (zeroGroupIndex[r] == -1)
                    ? -1
                    : (r - zeroGroups[zeroGroupIndex[r]].start + 1);

            int startAdj = zeroGroupIndex[l] + 1;

            int endAdj =
                (s[r] == '1'
                     ? zeroGroupIndex[r]
                     : zeroGroupIndex[r] - 1) -
                1;

            int activeSections = ones;

            if(s[l] == '0' &&
               s[r] == '0' &&
               zeroGroupIndex[l] + 1 == zeroGroupIndex[r])
            {
                activeSections = max(activeSections,
                                     ones + left + right);
            }
            else if(st && startAdj <= endAdj)
            {
                activeSections = max(activeSections,
                                     ones + st->query(startAdj, endAdj));
            }

            int rBound =
                (s[r] == '1'
                     ? zeroGroupIndex[r]
                     : zeroGroupIndex[r] - 1);

            if(s[l] == '0' &&
               zeroGroupIndex[l] + 1 <= rBound)
            {
                activeSections =
                    max(activeSections,
                        ones + left +
                            zeroGroups[zeroGroupIndex[l] + 1].length);
            }

            if(s[r] == '0' &&
               zeroGroupIndex[l] < zeroGroupIndex[r] - 1)
            {
                activeSections =
                    max(activeSections,
                        ones + right +
                            zeroGroups[zeroGroupIndex[r] - 1].length);
            }

            ans.push_back(activeSections);
        }

        delete st;

        return ans;
    }
};

int main()
{
    string s;

    cout << "Enter Binary String: ";
    cin >> s;

    int q;

    cout << "Enter Number of Queries: ";
    cin >> q;

    vector<vector<int>> queries(q, vector<int>(2));

    cout << "Enter Queries (l r):\n";

    for(int i = 0; i < q; i++)
    {
        cin >> queries[i][0] >> queries[i][1];
    }

    Solution obj;

    vector<int> ans =
        obj.maxActiveSectionsAfterTrade(s, queries);

    cout << "Answers:\n";

    for(int x : ans)
        cout << x << " ";

    return 0;
}