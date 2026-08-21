#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int transform(string& s1, string& s2)
    {
        int n = s1.size();

        if(n != s2.size())
            return -1;

        // Check whether both strings contain
        // the same characters
        int freq[256] = {0};

        for(char c : s1)
            freq[c]++;

        for(char c : s2)
            freq[c]--;

        for(int i = 0; i < 256; i++)
        {
            if(freq[i] != 0)
                return -1;
        }

        // Match characters from right side
        int i = n - 1;
        int j = n - 1;
        int matched = 0;

        while(i >= 0 && j >= 0)
        {
            if(s1[i] == s2[j])
            {
                matched++;
                j--;
            }

            i--;
        }

        // Unmatched characters need to be moved
        return n - matched;
    }
};

int main()
{
    string s1, s2;

    cout << "Enter first string: ";
    cin >> s1;

    cout << "Enter second string: ";
    cin >> s2;

    Solution obj;

    cout << "Minimum Operations = "
         << obj.transform(s1, s2);

    return 0;
}