//Minimum Cost to Reach 0
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:

    int minCost(int n, int i, int d, int c)
    {
        int N = 2 * n + 2;

        const long long INF = 1e18;

        vector<long long> dist(N, INF);

        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<pair<long long, int>>
        > pq;

        // Starting from n
        dist[n] = 0;
        pq.push({0, n});

        while(!pq.empty())
        {
            pair<long long, int> cur = pq.top();
            pq.pop();

            long long cost = cur.first;
            int x = cur.second;

            if(cost != dist[x])
                continue;

            // Reached 0
            if(x == 0)
                return (int)cost;

            // Operation 1: Decrease by 1
            if(x > 0 &&
               cost + i < dist[x - 1])
            {
                dist[x - 1] = cost + i;

                pq.push({
                    dist[x - 1],
                    x - 1
                });
            }

            // Operation 2: Increase by 1
            if(x + 1 < N &&
               cost + d < dist[x + 1])
            {
                dist[x + 1] = cost + d;

                pq.push({
                    dist[x + 1],
                    x + 1
                });
            }

            // Operation 3: Divide by 2
            if(x % 2 == 0 &&
               x / 2 < N &&
               cost + c < dist[x / 2])
            {
                dist[x / 2] = cost + c;

                pq.push({
                    dist[x / 2],
                    x / 2
                });
            }
        }

        return -1;
    }
};

int main()
{
    int n, i, d, c;

    cout << "Enter n: ";
    cin >> n;

    cout << "Enter cost of decrement: ";
    cin >> i;

    cout << "Enter cost of increment: ";
    cin >> d;

    cout << "Enter cost of divide by 2: ";
    cin >> c;

    Solution obj;

    cout << "Minimum Cost = "
         << obj.minCost(n, i, d, c);

    return 0;
}