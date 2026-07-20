#include<bits/stdc++.h>
using namespace std;

/*      LC = 3286
    You are given an m x n binary matrix grid and an integer health.
    You start on the upper-left corner (0, 0) and would like to get to the lower-right corner (m - 1, n - 1).
    You can move up, down, left, or right from one cell to another adjacent cell as long as your health remains positive.
    Cells (i, j) with grid[i][j] = 1 are considered unsafe and reduce your health by 1.
    Return true if you can reach the final cell with a health value of 1 or more, and false otherwise.
*/

class Solution {
public:
    bool isValid(int nr, int nc, int n, int m){
        return (nr >= 0 && nr < n && nc >= 0 && nc < m);
    }
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size();
        int m = grid[0].size();

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        vector<vector<int>> best(n, vector<int>(m, -1));        // this helps to find the best health we can reach that pos.

        // {health, {row, col}};
        queue<pair<int, pair<int, int>>> q;
        if(grid[0][0] == 1){
            best[0][0] = health-1;
            q.push({health-1, {0,0}});
        }
        else{
            best[0][0] = health;
            q.push({health, {0,0}});
        }

        while(!q.empty()){
            auto p = q.front();
            q.pop();

            int remainingHealth = p.first;
            int row = p.second.first;
            int col = p.second.second;

            if(row == n-1 && col == m-1){
                if(remainingHealth >= 1) return true;
                else continue;
            }

            for(int i = 0 ; i < 4 ; i++){
                int nr = row + delrow[i];
                int nc = col + delcol[i];

                if(isValid(nr, nc, n, m) && grid[nr][nc]){      // has one in the grid
                    if(remainingHealth > best[nr][nc]){         // has a better health when reached at {nr, nc}.
                        best[nr][nc] = remainingHealth;
                        q.push({remainingHealth-1, {nr, nc}});
                    }
                }
                else if(isValid(nr, nc, n, m) && !grid[nr][nc]){        // has 0 in the grid.
                    if(remainingHealth > best[nr][nc]){
                        best[nr][nc] = remainingHealth;
                        q.push({remainingHealth, {nr, nc}});
                    }
                }
            }
        }

        return false;
    }
};

int main(){
    /*
        Example 1:

        Input: grid = [[0,1,0,0,0],[0,1,0,1,0],[0,0,0,1,0]], health = 1
        Output: true
        Explanation:
        The final cell can be reached safely by walking along the gray cells below.

        Example 2:

        Input: grid = [[0,1,1,0,0,0],[1,0,1,0,0,0],[0,1,1,1,0,1],[0,0,1,0,1,0]], health = 3
        Output: false
        Explanation:
        A minimum of 4 health points is needed to reach the final cell safely.

        Example 3:

        Input: grid = [[1,1,1],[1,0,1],[1,1,1]], health = 5
        Output: true
        Explanation:
        The final cell can be reached safely by walking along the gray cells below.
        Any path that does not go through the cell (1, 1) is unsafe since your health will drop to 0 when reaching the final cell.
    */

    return 0;
}