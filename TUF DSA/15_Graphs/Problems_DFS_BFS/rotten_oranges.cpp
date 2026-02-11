#include<bits/stdc++.h>
using namespace std;

int orangesRottenTime(vector<vector<int>>& grid){
    if(grid.empty()) return 0;

    int n = grid.size();
    int m = grid[0].size();

    queue<pair<pair<int, int>, int>> q;
    // vector<vector<int>> vis(n, vector<int>(m, 0));
    int vis[n][m];

    for(int i = 0 ; i < n ; i++){           // marked the visited matrix.
        for(int j = 0 ; j < m ; j++){
            if(grid[i][j] == 2){
                q.push({{i,j}, 0});
                vis[i][j] = 1;
            }
            else{
                vis[i][j] = 0;
            }
        }
    }

    int tm = 0;
    int delrow[] = {-1, 0, 1, 0};       // checking the 4 sides.
    int delcol[] = {0, 1, 0, -1};

    while(!q.empty()){
        int r = q.front().first.first;
        int c = q.front().first.second;
        int t = q.front().second;
        q.pop();
        tm = max(tm, t);

        for(int i = 0 ; i < 4 ; i++){
            int nr = r + delrow[i];
            int nc = c + delcol[i];

            if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1 && !vis[nr][nc]){        // checking validity and if visited or not.
                q.push({{nr, nc}, t+1});
                vis[nr][nc] = 1;
            }
        }
    }

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(grid[i][j] == 1 && !vis[i][j]) return -1;
        }
    }
    return tm;
}

int main(){
    vector<vector<int>> grid = {{2, 1, 1}, 
                          {1, 1, 0}, 
                          {0, 1, 1}};

    int ans = orangesRottenTime(grid);
    cout << "The number of provinces are  : " << ans;
}