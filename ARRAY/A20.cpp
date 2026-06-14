#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {

        int ans = INT_MAX;

        int n = landStartTime.size();
        int m = waterStartTime.size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                // Land ride first, then Water ride
                int landFinish =
                    landStartTime[i] +
                    landDuration[i];

                int waterFinish =
                    max(landFinish,
                        waterStartTime[j])
                    + waterDuration[j];

                ans = min(ans,
                          waterFinish);

                // Water ride first, then Land ride
                int waterFirstFinish =
                    waterStartTime[j] +
                    waterDuration[j];

                int landFinalFinish =
                    max(waterFirstFinish,
                        landStartTime[i])
                    + landDuration[i];

                ans = min(ans,
                          landFinalFinish);
            }
        }

        return ans;
    }
};

int main() {

    int n, m;

    cout << "Enter number of land rides: ";
    cin >> n;

    vector<int> landStartTime(n);
    vector<int> landDuration(n);

    cout << "Enter land start times: ";
    for (int i = 0; i < n; i++) {
        cin >> landStartTime[i];
    }

    cout << "Enter land durations: ";
    for (int i = 0; i < n; i++) {
        cin >> landDuration[i];
    }

    cout << "Enter number of water rides: ";
    cin >> m;

    vector<int> waterStartTime(m);
    vector<int> waterDuration(m);

    cout << "Enter water start times: ";
    for (int i = 0; i < m; i++) {
        cin >> waterStartTime[i];
    }

    cout << "Enter water durations: ";
    for (int i = 0; i < m; i++) {
        cin >> waterDuration[i];
    }

    Solution obj;

    int result = obj.earliestFinishTime(
        landStartTime,
        landDuration,
        waterStartTime,
        waterDuration
    );

    cout << "Earliest Finish Time = "
         << result << endl;

    return 0;
}