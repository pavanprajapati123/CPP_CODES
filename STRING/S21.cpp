// C++ program to find the length of longest palindromic subsequence
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:

    int solve(string &s, int i, int j)
    {
        if(i > j)
            return 0;

        if(i == j)
            return 1;

        if(s[i] == s[j])
            return 2 + solve(s, i + 1, j - 1);

        return max(solve(s, i + 1, j),
                   solve(s, i, j - 1));
    }

    int longestPalindromeSubseq(string s)
    {
        return solve(s, 0, s.size() - 1);
    }
};

int main()
{
    string s;

    cout << "Enter String: ";
    cin >> s;

    Solution obj;

    cout << "Longest Palindromic Subsequence Length = "
         << obj.longestPalindromeSubseq(s);

    return 0;
}