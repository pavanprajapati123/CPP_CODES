//8. Character Frequency
#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    char ch;
    int count = 0;

    cout << "Enter string: ";
    getline(cin, str);

    cout << "Enter character: ";
    cin >> ch;

    for(char c : str) {
        if(c == ch)
            count++;
    }

    cout << "Frequency = " << count;

    return 0;
}