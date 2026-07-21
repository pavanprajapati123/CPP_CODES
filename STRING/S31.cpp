// Solution to find the maximum number of active sections after a trade
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxActiveSectionsAfterTrade(string s)
    {
        int n = s.size();

        string t = "1" + s + "1";

        int m = t.size();

        // Run Length Encoding
        vector<pair<char, int>> blocks;

        int i = 0;

        while(i < m)
        {
            int j = i;

            while(j < m && t[j] == t[i])
                j++;

            blocks.push_back({t[i], j - i});

            i = j;
        }

        int baseOnes = 0;

        for(char c : s)
        {
            if(c == '1')
                baseOnes++;
        }

        int zmax = 0;

        for(auto &b : blocks)
        {
            if(b.first == '0')
                zmax = max(zmax, b.second);
        }

        int bestNet = 0;

        int bcount = blocks.size();

        // Check only interior '1' blocks
        for(int idx = 1; idx + 1 < bcount; idx++)
        {
            if(blocks[idx].first != '1')
                continue;

            int ownLen = blocks[idx].second;

            int L = blocks[idx - 1].second;

            int R = blocks[idx + 1].second;

            int optionSelf = L + R;

            int optionOther = zmax - ownLen;

            bestNet = max(bestNet, max(optionSelf, optionOther));
        }

        return baseOnes + bestNet;
    }
};

int main()
{
    string s;

    cout << "Enter Binary String: ";
    cin >> s;

    Solution obj;

    cout << "Maximum Active Sections = "
         << obj.maxActiveSectionsAfterTrade(s);

    return 0;
}