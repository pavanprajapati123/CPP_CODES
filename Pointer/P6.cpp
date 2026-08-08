//3302. Find the Lexicographically Smallest Valid Sequence
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    vector<int> validSequence(string word1, string word2)
    {
        int n = word1.size();
        int m = word2.size();

        vector<int> ans(m);
        vector<int> last(m, -1);

        // Find positions for matching suffix
        int i = n - 1;
        int j = m - 1;

        while(i >= 0 && j >= 0)
        {
            if(word1[i] == word2[j])
            {
                last[j] = i;
                j--;
            }

            i--;
        }

        bool canChange = true;
        j = 0;

        // Find lexicographically smallest valid index sequence
        for(i = 0; i < n && j < m; i++)
        {
            if(word1[i] == word2[j])
            {
                ans[j] = i;
                j++;
            }
            else if(canChange &&
                    (j == m - 1 || i < last[j + 1]))
            {
                canChange = false;
                ans[j] = i;
                j++;
            }
        }

        if(j == m)
        {
            return ans;
        }

        return {};
    }
};

int main()
{
    string word1, word2;

    cout << "Enter word1: ";
    cin >> word1;

    cout << "Enter word2: ";
    cin >> word2;

    Solution obj;

    vector<int> ans = obj.validSequence(word1, word2);

    if(ans.empty())
    {
        cout << "No Valid Sequence";
    }
    else
    {
        cout << "Valid Sequence: ";

        for(int x : ans)
        {
            cout << x << " ";
        }
    }

    return 0;
}