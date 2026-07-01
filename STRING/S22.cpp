// C++ program to find the longest palindromic substring
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:

    bool isPalindrome(string &s, int left, int right)
    {
        while(left < right)
        {
            if(s[left] != s[right])
                return false;

            left++;
            right--;
        }

        return true;
    }

    string longestPalindrome(string s)
    {
        int n = s.size();

        string ans = "";

        for(int i = 0; i < n; i++)
        {
            for(int j = i; j < n; j++)
            {
                if(isPalindrome(s, i, j))
                {
                    if(j - i + 1 > ans.size())
                    {
                        ans = s.substr(i, j - i + 1);
                    }
                }
            }
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

    cout << "Longest Palindromic Substring = "
         << obj.longestPalindrome(s);

    return 0;
}