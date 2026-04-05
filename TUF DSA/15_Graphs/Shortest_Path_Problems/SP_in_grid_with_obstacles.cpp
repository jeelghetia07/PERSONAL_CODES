#include<bits/stdc++.h>
using namespace std;

/*      LC = 1293
    You are given an m x n integer matrix grid where each cell is either 0 (empty) or 1 (obstacle). You can move up, down, left, or right from and to an empty cell in one step.

    Return the minimum number of steps to walk from the upper left corner (0, 0) to the lower right corner (m - 1, n - 1) given that you can eliminate at most k obstacles. If it is not possible to find such walk return -1.
*/

class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<int>>> vis(n, vector<vector<int>> (m, vector<int>(k+1, -1)));
        queue<tuple<int, int, int>> q;

        int steps = 0;
        q.push({0,0,k});
        vis[0][0][k] = 1;

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        while(!q.empty()){
            int size = q.size();
            
            // we traverse all the nodes that were moved one step ahead at a time at once., if not then at every node we will keep increasing the steps and that will make the ans wrong.
            for(int j = 0 ; j < size ; j++){
                auto [row, col, remK] = q.front();
                q.pop();     

                if(row == n-1 && col == m-1) return steps;

                for(int i = 0 ; i < 4 ; i++){
                    int nr = row + delrow[i];
                    int nc = col + delcol[i];

                    if((nr >= 0 && nr < n && nc >= 0 && nc < m) && grid[nr][nc] == 0 && vis[nr][nc][remK] == -1){
                        vis[nr][nc][remK] = 1;
                        q.push({nr, nc, remK});
                    }
                    else if((nr >= 0 && nr < n && nc >= 0 && nc < m) && remK > 0 && vis[nr][nc][remK-1] == -1 && grid[nr][nc] == 1){
                        vis[nr][nc][remK-1] = 1;
                        q.push({nr, nc, remK-1});
                    }
                }
            }
            steps++;        // after completing all cells moved at once we increase the steps.
        }
        return -1;
    }
};

int main(){
    /*
        Input: grid = [[0,0,0],[1,1,0],[0,0,0],[0,1,1],[0,0,0]], k = 1
        Output: 6
        Explanation: 
            The shortest path without eliminating any obstacle is 10.
            The shortest path with one obstacle elimination at position (3,2) is 6. Such path is (0,0) -> (0,1) -> (0,2) -> (1,2) -> (2,2) -> '(3,2)' -> (4,2).


        Input: grid = [[0,1,1],[1,1,1],[1,0,0]], k = 1
        Output: -1
        Explanation: 
            We need to eliminate at least two obstacles to find such a walk.
    */

    return 0;
}