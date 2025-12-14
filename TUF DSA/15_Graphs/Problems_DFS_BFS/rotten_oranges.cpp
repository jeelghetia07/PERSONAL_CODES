#include<bits/stdc++.h>
using namespace std;

class ROTTEN{
public:
    int orangesRotten(vector<vector<int>>& grid){

        if(grid.empty()) return 0;

        int n = grid.size();
        int m = grid[0].size();

        queue<pair< pair<int,int> , int>> q;     // this will store a pair of {{row, col}, time}
        int vis[n][m]; 
        for(int i = 0 ; i < n ; i++){
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
        int delrow[] = {-1,0,+1,0};
        int delcol[] = {0,1,0,-1};
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second; 
            tm = max(tm, t);
            q.pop();
            for(int i = 0 ; i < 4 ; i++){
                int nr = r + delrow[i];
                int nc = c + delcol[i];

                if(nr >= 0 && nr < n && nc >= 0 && nc < m && vis[nr][nc] != 2 && grid[nr][nc] == 1){
                    q.push({{nr, nc}, t+1});
                    vis[nr][nc] = 1;
                }
            }
        }

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(vis[i][j] != 2 && grid[i][j] == 1){
                    return -1;
                }
            }
        }
        return tm;
    }
};

int main(){
    // Input grid with 2 = rotten, 1 = fresh, 0 = empty
    vector<vector<int>> v{{2, 1, 1}, 
                          {1, 1, 0}, 
                          {0, 1, 1}};
    
    // Call the function to calculate minimum time required
    ROTTEN obj;
    int rotting = obj.orangesRotten(v);

    // Output the result
    cout << "Minimum Number of Minutes Required " << rotting << endl;

    return 0;
}