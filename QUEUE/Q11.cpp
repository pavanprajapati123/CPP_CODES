// Rotting Oranges
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {

    vector<vector<int>> grid = {
        {2,1,1},
        {1,1,0},
        {0,1,1}
    };

    int n = grid.size();
    int m = grid[0].size();

    queue<pair<int,int>> q;
    int fresh = 0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==2)
                q.push({i,j});
            else if(grid[i][j]==1)
                fresh++;
        }
    }

    int time = 0;

    int dx[] = {-1,1,0,0};
    int dy[] = {0,0,-1,1};

    while(!q.empty() && fresh){

        int sz = q.size();

        while(sz--){

            auto cur = q.front();
            q.pop();

            int x = cur.first;
            int y = cur.second;

            for(int k=0;k<4;k++){

                int nx = x + dx[k];
                int ny = y + dy[k];

                if(nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][ny]==1){

                    grid[nx][ny]=2;
                    fresh--;

                    q.push({nx,ny});
                }
            }
        }

        time++;
    }

    cout << time;

    return 0;
}