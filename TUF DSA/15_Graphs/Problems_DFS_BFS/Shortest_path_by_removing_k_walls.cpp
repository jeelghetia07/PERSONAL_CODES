#include<bits/stdc++.h>
using namespace std;

/*      GFG
    Given a binary matrix arr of size n × m, where 0 represents an empty cell and 1 represents a wall, and an integer k representing the maximum number of walls that can be removed.

    Starting from the top-left cell (0, 0), find the minimum number of steps required to reach the bottom-right cell (n - 1, m - 1).
    Movement is allowed in four directions: up, down, left, and right.
    During the traversal, at most k walls can be removed.
    If the destination cannot be reached, return -1.
*/


// in this we didnt take the vis matrix that represents the shortest path of coming to that cell cause it can take more walls broken to reach a cell but with less number of walls broken, we can reach that very cell, even if there are more steps.


class Solution {
  public:
    int shortestPath(int k, vector<vector<int>> &mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        if(k >= n + m -2){
            return n + m - 2;
        }
        
        vector<vector<vector<bool>>> vis(
            n,
            vector<vector<bool>>(m, vector<bool>(k + 1, false))
        );
        vis[0][0][k] = true;
        
        queue<tuple<int, int, int>> q; 
        q.push({0,0,k});
        
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        
        int steps = 0;
        
        while(!q.empty()){
            int sz = q.size();
            
            while(sz--){
                auto [row, col, wallsRemaining] = q.front();
                q.pop();
                
                if(row == n-1 && col == m-1) return steps;
                
                for(int i = 0 ; i < 4 ; i++){
                    int nr = row + delrow[i];
                    int nc = col + delcol[i];
                    
                    if(nr >= 0 && nr < n && nc >= 0 && nc < m ){
                        
                        // empty cell
                        if(mat[nr][nc] == 0){
                            if(!vis[nr][nc][wallsRemaining]){
                                vis[nr][nc][wallsRemaining] = true;
                                q.push({nr, nc, wallsRemaining});
                            }
                        }
                        
                        // wall cell
                        else{
                            if(wallsRemaining > 0){
                                int newWallsLeft = wallsRemaining - 1;
                                if (!vis[nr][nc][newWallsLeft]) {
                                    vis[nr][nc][newWallsLeft] = true;
                                    q.push({nr, nc, newWallsLeft});
                                }
                            }
                        }
                    }
                }
                
            }
            steps++;
        }
        
        return -1;
    }
};

int main(){
    /*
        Input: k = 1, mat = [[0, 0, 0], [0, 0, 1], [0, 1, 0]]
        Output: 4
        Explanation: Since k = 1, one wall may be removed. Removing the wall at cell (2, 1) or (1, 2) opens a path connecting the start and destination cells. Following this path reaches the bottom-right corner in 4 steps.
            
        Input: k = 0, mat = [[0, 1], [1, 0]]
        Output: -1
        Explanation: Since k = 0, no walls can be removed. Every possible path from the start cell to the destination is blocked by a wall, so the destination cannot be reached.
    */

    return 0;
}