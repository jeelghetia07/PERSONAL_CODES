#include<bits/stdc++.h>
using namespace std;

/* 
    Given a grid of size n*m (n is the number of rows and m is the number of columns in the grid) consisting of 'W's (Water) and 'L's (Land). Find the number of islands.

    Note: An island is either surrounded by water or the boundary of a grid and is formed by connecting adjacent lands horizontally or vertically or diagonally i.e., in all 8 directions.
*/

void bfs(int r, int c, int n, int m, vector<vector<int>>& vis, vector<vector<char>>& grid){
    vis[r][c] = 1;
    
    queue<pair<int, int>> q;
    q.push({r,c});
    
    while(!q.empty()){
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        
        int delrow[] = {-1,-1,0,1,1,1,0,-1};
        int delcol[] = {0,1,1,1,0,-1,-1,-1};
        
        for(int i = 0 ; i < 8 ; i++){
            int nr = row + delrow[i];
            int nc = col + delcol[i];
            
            if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 'L' && !vis[nr][nc]){
                q.push({nr, nc});
                vis[nr][nc] = 1;
            }
        }
    }
}

int numberofIslands(vector<vector<char>>& grid){
    int n = grid.size();
    int m = grid[0].size();
    
    vector<vector<int>> vis(n, vector<int>(m, 0));
    int cnt = 0;
    
    for(int r = 0 ; r < n ; r++){
        for(int c = 0 ; c < m ; c++){
            if(!vis[r][c] && grid[r][c] == 'L'){
                cnt++;
                bfs(r, c, n, m, vis, grid);
            }
        }
    }
    return cnt;
}

int main(){
    vector<vector<char>> grid =
                {{'L', 'L', 'W', 'W', 'W'}, 
                {'W', 'L', 'W', 'W', 'L'}, 
                {'L', 'W', 'W', 'L', 'L'}, 
                {'W', 'W', 'W', 'W', 'W'}, 
                {'L', 'W', 'L', 'L', 'W'}};

    cout << "The number of islands are : "  << numberofIslands(grid);
    return 0;
}