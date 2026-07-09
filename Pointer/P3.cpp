// reverse each word in a string
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:

    string reverseEachWord(string input)
    {
        int start = 0;
        int n = input.length();

        for(int i = 0; i <= n; i++)
        {
            if(i == n || input[i] == ' ')
            {
                reverse(input.begin() + start, input.begin() + i);
                start = i + 1;
            }
        }

        return input;
    }
};

int main()
{
    string input;

    cout << "Enter String: ";
    getline(cin, input);

    Solution obj;

    cout << "Output: "
         << obj.reverseEachWord(input);

    return 0;
}