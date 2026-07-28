// Permutations of a String
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    void solve(int index, string &s, vector<string> &ans)
    {
        if(index == s.size())
        {
            ans.push_back(s);
            return;
        }

        for(int i = index; i < s.size(); i++)
        {
            swap(s[index], s[i]);

            solve(index + 1, s, ans);

            swap(s[index], s[i]);   // Backtrack
        }
    }

    vector<string> findPermutations(string &s)
    {
        vector<string> ans;

        solve(0, s, ans);

        return ans;
    }
};

int main()
{
    string s;

    cout << "Enter string: ";
    cin >> s;

    Solution obj;

    vector<string> ans = obj.findPermutations(s);

    cout << "All Permutations:\n";

    for(string str : ans)
    {
        cout << str << endl;
    }

    return 0;
}