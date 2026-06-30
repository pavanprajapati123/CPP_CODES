//151. Reverse Words in a String
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string reverseWords(string &s)
    {
        vector<string> words;
        string word = "";

        for(char ch : s)
        {
            if(ch != '.')
            {
                word += ch;
            }
            else
            {
                if(!word.empty())
                {
                    words.push_back(word);
                    word = "";
                }
            }
        }

        if(!word.empty())
            words.push_back(word);

        string ans = "";

        for(int i = words.size() - 1; i >= 0; i--)
        {
            ans += words[i];

            if(i != 0)
                ans += ".";
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

    cout << "Reversed String: "
         << obj.reverseWords(s);

    return 0;
}