//1. String Input and Output
#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;

    cout << "Enter a string: ";
    getline(cin, str);

    cout << "Length = " << str.length();

    return 0;
}