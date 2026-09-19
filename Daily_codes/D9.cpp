//
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkOverlap(int radius, int xCenter, int yCenter,
                      int x1, int y1, int x2, int y2)
    {
        int closestX = max(x1, min(xCenter, x2));
        int closestY = max(y1, min(yCenter, y2));

        int dx = xCenter - closestX;
        int dy = yCenter - closestY;

        return dx * dx + dy * dy <= radius * radius;
    }
};

int main()
{
    Solution obj;

    int radius = 1;
    int xCenter = 0;
    int yCenter = 0;

    int x1 = 1;
    int y1 = -1;
    int x2 = 3;
    int y2 = 1;

    cout << (obj.checkOverlap(
        radius,
        xCenter,
        yCenter,
        x1,
        y1,
        x2,
        y2
    ) ? "true" : "false");

    return 0;
}