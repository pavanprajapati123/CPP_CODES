//Remove Duplicate Characters
#include <bits/stdc++.h>
using namespace std;

string removeDuplicate(string &s)
{
    string ans = "";

    for(int i = 0; i < s.length(); i++)
    {
        if(i == 0 || s[i] != s[i - 1])
        {
            ans += s[i];
        }
    }

    return ans;
}

int main()
{
    string s;

    cout << "Enter string: ";
    cin >> s;

    cout << "After Removing Duplicates = "
         << removeDuplicate(s);

    return 0;
}