//1927 Sum Game
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool sumGame(string num)
    {
        int n = num.size();
        int half = n / 2;

        int sumLeft = 0;
        int sumRight = 0;

        int qLeft = 0;
        int qRight = 0;

        for(int i = 0; i < half; i++)
        {
            if(num[i] == '?')
                qLeft++;
            else
                sumLeft += num[i] - '0';
        }

        for(int i = half; i < n; i++)
        {
            if(num[i] == '?')
                qRight++;
            else
                sumRight += num[i] - '0';
        }

        int qDiff = qLeft - qRight;
        int diff = sumLeft - sumRight;

        // Odd difference in '?' means Alice wins
        if(abs(qDiff) % 2 == 1)
            return true;

        // Even difference
        return diff != 9 * (qRight - qLeft) / 2;
    }
};

int main()
{
    string num;

    cout << "Enter string: ";
    cin >> num;

    Solution obj;

    if(obj.sumGame(num))
        cout << "Alice Wins";
    else
        cout << "Bob Wins";

    return 0;
}