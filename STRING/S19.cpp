//647 palindromic substrings
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:

    bool isPalindrome(string &s, int l, int r)
    {
        while(l < r)
        {
            if(s[l] != s[r])
                return false;

            l++;
            r--;
        }

        return true;
    }

    int countSubstrings(string s)
    {
        int n = s.size();
        int cnt = 0;

        for(int i = 0; i < n; i++)
        {
            for(int j = i; j < n; j++)
            {
                if(isPalindrome(s, i, j))
                    cnt++;
            }
        }

        return cnt;
    }
};

int main()
{
    string s;

    cout << "Enter String: ";
    cin >> s;

    Solution obj;

    cout << "Total Palindromic Substrings = "
         << obj.countSubstrings(s);

    return 0;
}