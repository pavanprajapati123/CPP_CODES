//Unoccupied Computers
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int n, string s) {
        vector<int> status(26, 0);

        int available = n;
        int ans = 0;

        for (char ch : s) {
            int x = ch - 'A';

            // Person is not currently in the room
            if (status[x] == 0) {
                if (available > 0) {
                    // Give a computer
                    status[x] = 1;
                    available--;
                } else {
                    // No computer available
                    status[x] = 2;
                    ans++;
                }
            }
            // Person leaves
            else if (status[x] == 1) {
                status[x] = 0;
                available++;
            }
            // Person who could not get a computer leaves
            else {
                status[x] = 0;
            }
        }

        return ans;
    }
};

int main() {
    Solution obj;

    int n;
    string s;

    cin >> n;
    cin >> s;

    cout << obj.solve(n, s) << endl;

    return 0;
}