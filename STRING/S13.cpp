// Reverse Words in a String
#include <iostream>
#include <vector>
#include <string>
using namespace std;

string reverseString(string &str)
{
    vector<string> words;
    string word = "";

    for (char ch : str)
    {
        if (ch != ' ')
        {
            word += ch;
        }
        else
        {
            if (!word.empty())
            {
                words.push_back(word);
                word = "";
            }
        }
    }

    if (!word.empty())
    {
        words.push_back(word);
    }

    string ans = "";

    for (int i = words.size() - 1; i >= 0; i--)
    {
        ans += words[i];

        if (i != 0)
        {
            ans += " ";
        }
    }

    return ans;
}

int main()
{
    string str;

    cout << "Enter String: ";
    getline(cin, str);

    cout << "Reversed String: "
         << reverseString(str)
         << endl;

    return 0;
}