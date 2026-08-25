//Run Length Encoding
#include <bits/stdc++.h>
using namespace std;

string encode(string &message)
{
    string ans = "";
    int n = message.size();

    for(int i = 0; i < n; )
    {
        char ch = message[i];
        int count = 0;

        while(i < n && message[i] == ch)
        {
            count++;
            i++;
        }

        ans += ch;
        ans += to_string(count);
    }

    return ans;
}

int main()
{
    string message;

    cout << "Enter message: ";
    cin >> message;

    cout << "Encoded String = "
         << encode(message);

    return 0;
}