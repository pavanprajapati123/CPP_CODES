#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {

        int left = 0;
        int right = s.size() - 1;

        while (left < right) {
            swap(s[left], s[right]);

            left++;
            right--;
        }
    }
};

int main() {

    int n;

    cout << "Enter number of characters: ";
    cin >> n;

    vector<char> s(n);

    cout << "Enter characters: ";
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    Solution obj;
    obj.reverseString(s);

    cout << "Reversed String: ";

    for (char ch : s) {
        cout << ch << " ";
    }

    cout << endl;

    return 0;
}