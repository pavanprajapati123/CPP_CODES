//1358. Number of Substrings Containing All Three Characters
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {

        vector<int> last(3, -1);
        int ans = 0;

        for(int i = 0; i < s.size(); i++)
        {
            last[s[i] - 'a'] = i;

            ans += min({last[0], last[1], last[2]}) + 1;
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

    cout << "Number of Substrings = "
         << obj.numberOfSubstrings(s);

    return 0;
}