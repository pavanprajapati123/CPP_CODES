//3517 smallest palindrommice Rearrengement of Characters
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string smallestPalindrome(string s)
    {
        vector<int> freq(26, 0);

        for(char c : s)
        {
            freq[c - 'a']++;
        }

        string left = "";
        string mid = "";

        for(int i = 0; i < 26; i++)
        {
            left += string(freq[i] / 2, char('a' + i));

            if(freq[i] % 2)
            {
                mid = char('a' + i);
            }
        }

        string right = left;
        reverse(right.begin(), right.end());

        return left + mid + right;
    }
};

int main()
{
    string s;

    cout << "Enter string: ";
    cin >> s;

    Solution obj;

    cout << "Smallest Palindrome: "
         << obj.smallestPalindrome(s);

    return 0;
}