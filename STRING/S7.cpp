//4. String Reverse Karna
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string str;

    cout << "Enter a string: ";
    getline(cin, str);

    reverse(str.begin(), str.end());

    cout << "Reversed String: " << str;

    return 0;
}