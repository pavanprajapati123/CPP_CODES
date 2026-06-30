//non repeating character
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:

    char nonRepeatingChar(string &s)
    {
        int freq[26] = {0};

        // Count frequency of each character
        for(char ch : s)
            freq[ch - 'a']++;

        // Find first non-repeating character
        for(char ch : s)
        {
            if(freq[ch - 'a'] == 1)
                return ch;
        }

        return '$';
    }
};

int main()
{
    string s;

    cout << "Enter String: ";
    cin >> s;

    Solution obj;

    char ans = obj.nonRepeatingChar(s);

    if(ans == '$')
        cout << "No Non-Repeating Character";
    else
        cout << "First Non-Repeating Character = " << ans;

    return 0;
}