//989. Add to Array-Form of Integer
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {

        vector<int> ans;

        int i = num.size() - 1;
        int carry = 0;

        while (i >= 0 || k > 0 || carry) {

            int sum = carry;

            if (i >= 0) {
                sum += num[i];
                i--;
            }

            sum += (k % 10);
            k /= 10;

            ans.push_back(sum % 10);

            carry = sum / 10;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};

int main() {

    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> num(n);

    cout << "Enter digits of number: ";
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    int k;
    cout << "Enter value of k: ";
    cin >> k;

    Solution obj;

    vector<int> result = obj.addToArrayForm(num, k);

    cout << "Result: ";

    for (int digit : result) {
        cout << digit << " ";
    }

    cout << endl;

    return 0;
}