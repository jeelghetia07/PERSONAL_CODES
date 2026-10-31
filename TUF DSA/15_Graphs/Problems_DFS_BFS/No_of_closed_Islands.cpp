#include<bits/stdc++.h>
using namespace std;

/*      LC = 1254
    Given a 2D grid consists of 0s (land) and 1s (water).  An island is a maximal 4-directionally connected group of 0s and a closed island is an island totally (all left, top, right, bottom) surrounded by 1s.

    Return the number of closed islands.
*/

class Solution {
    int delrow[4] = {-1, 0, 1, 0};
    int delcol[4] = {0, 1, 0, -1};
public:
    bool isValid(int nr, int nc, int n, int m){
        return (nr >= 0 && nr < n && nc >= 0 && nc < m);
    }
    void dfs(int r, int c, vector<vector<int>>& vis, vector<vector<int>>& grid, int n, int m){
        vis[r][c] = 1;

        for(int i = 0 ; i < 4 ; i++){
            int nr = r + delrow[i];
            int nc = c + delcol[i];

            if(isValid(nr, nc, n, m) && !vis[nr][nc] && grid[nr][nc] == 0){
                dfs(nr, nc, vis, grid, n, m);
            }
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        // this dfs call removes all the components which are touched with the boundary cause they can never be closed one.
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(i == 0 || j == 0 || i == n-1 || j == m-1){
                    if(grid[i][j] == 0 && !vis[i][j]) dfs(i, j, vis, grid, n, m);
                }
            }
        }

        int cnt = 0;

        // the rest components left inside will definitely be closed so return the count.
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 0 && !vis[i][j]){
                    cnt++;
                    dfs(i, j, vis, grid, n, m);
                }
            }
        }

        return cnt;
    }
};

int main(){
    /*
        Example 1:

        Input: grid = [[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]
        Output: 2
        Explanation: 
        Islands in gray are closed because they are completely surrounded by water (group of 1s).


        Example 2:

        Input: grid = [[0,0,1,0,0],[0,1,0,1,0],[0,1,1,1,0]]
        Output: 1


        Example 3:

        Input: grid = [[1,1,1,1,1,1,1],
                    [1,0,0,0,0,0,1],
                    [1,0,1,1,1,0,1],
                    [1,0,1,0,1,0,1],
                    [1,0,1,1,1,0,1],
                    [1,0,0,0,0,0,1],
                    [1,1,1,1,1,1,1]]
        Output: 2
        

        Constraints:

        1 <= grid.length, grid[0].length <= 100
        0 <= grid[i][j] <=1
    */

    return 0;
}