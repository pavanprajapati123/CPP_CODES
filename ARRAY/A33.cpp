//1051. Height Checker
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int heightChecker(vector<int>& heights) {

        vector<int> expected = heights;

        sort(expected.begin(), expected.end());

        int count = 0;

        for (int i = 0; i < heights.size(); i++) {
            if (heights[i] != expected[i]) {
                count++;
            }
        }

        return count;
    }
};

int main() {

    int n;
    cout << "Enter number of students: ";
    cin >> n;

    vector<int> heights(n);

    cout << "Enter heights: ";
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }

    Solution obj;

    cout << "Students in wrong positions = "
         << obj.heightChecker(heights)
         << endl;

    return 0;
}