#include<bits/stdc++.h>
using namespace std;

/*      LC = 3905
    You are given two integers n and m representing the number of rows and columns of a grid, respectively.

    You are also given a 2D integer array sources, where sources[i] = [ri, ci, color​​​​​​​i] indicates that the cell (ri, ci) is initially colored with colori. All other cells are initially uncolored and represented as 0.

    At each time step, every currently colored cell spreads its color to all adjacent uncolored cells in the four directions: up, down, left, and right. All spreads happen simultaneously.

    If multiple colors reach the same uncolored cell at the same time step, the cell takes the color with the maximum value.

    The process continues until no more cells can be colored.

    Return a 2D integer array representing the final state of the grid, where each cell contains its final color.
*/

class Solution {
public:
    bool isValid(int nr, int nc, int n, int m){
        return (nr >= 0 && nr < n && nc >= 0 && nc < m);
    }
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        vector<vector<int>> visTime(n, vector<int>(m, INT_MAX));
        vector<vector<int>> grid(n, vector<int>(m, 0));

        queue<tuple<int, int, int, int>> q;

        for(auto &it : sources){
            int row = it[0];
            int col = it[1];
            int color = it[2];

            grid[row][col] = color;
            visTime[row][col] = 0;
            
            q.push({row, col, color, 0});
        }

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        while(!q.empty()){
            auto [row, col, color, time] = q.front();
            q.pop();

            for(int i = 0 ; i < 4 ; i++){
                int nr = row + delrow[i];
                int nc = col + delcol[i];

                if(!isValid(nr, nc, n, m)) continue;

                if(visTime[nr][nc] > time+1){       // here we are visiting the first time.
                    grid[nr][nc] = color;
                    visTime[nr][nc] = time+1;
                    q.push({nr, nc, color, time+1});
                }
                else if(visTime[nr][nc] == time+1){        // we reached here at the same time.
                    if(grid[nr][nc] < color){
                        grid[nr][nc] = color;
                        q.push({nr, nc, color, time+1});
                    }
                }
            }
        }

        return grid;
    }
};

int main(){
    int n = 3, m = 3;
    vector<vector<int>> sources = {{0,0,1},{2,2,2}};

    Solution obj;

    vector<vector<int>> grid = obj.colorGrid(n,m,sources);

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}