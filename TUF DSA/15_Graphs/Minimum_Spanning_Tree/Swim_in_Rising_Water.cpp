#include<bits/stdc++.h>
using namespace std;

/*      LC = 778
    You are given an n x n integer matrix grid where each value grid[i][j] represents the elevation at that point (i, j).

    It starts raining, and water gradually rises over time. At time t, the water level is t, meaning any cell with elevation less than equal to t is submerged or reachable.

    You can swim from a square to another 4-directionally adjacent square if and only if the elevation of both squares individually are at most t. You can swim infinite distances in zero time. Of course, you must stay within the boundaries of the grid during your swim.

    Return the minimum time until you can reach the bottom right square (n - 1, n - 1) if you start at the top left square (0, 0)
*/

class Solution {
public:

    bool isValid(int nr, int nc, int n){
        return (nr >= 0 && nr < n && nc >= 0 && nc < n);
    }


    bool EndOfGrid(int row, int col, int n){
        return (row == n-1 && col == n-1);
    }

    int swimInWater(vector<vector<int>> grid){
        int n = grid.size();

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        vector<vector<int>> vis(n, vector<int>(n, 0));

        pq.push({grid[0][0], {0, 0}});

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();

            int time = it.first;
            int row = it.second.first;
            int col = it.second.second;

            if(EndOfGrid(row, col, n)){
                return time;
            }

            if(vis[row][col]) continue;

            vis[row][col] = 1;

            for(int i = 0 ; i < 4 ; i++){
                int nr = row + delrow[i];
                int nc = col + delcol[i];

                if(isValid(nr, nc, n) && !vis[nr][nc]){
                    int newTime = max(grid[nr][nc], time);
                    pq.push({newTime, {nr, nc}});
                }
            }
        }

        return -1;
    }




                // Binary Search and BFS.....Guessing the water level.


    // bool canReach(int level, int n, vector<vector<int>>& grid){
    //     queue<pair<int, int>> q;
    //     vector<vector<int>> vis(n, vector<int>(n, 0));

    //     if(grid[0][0] > level) return false;
        
    //     q.push({0, 0});     // {row, col}
    //     vis[0][0] = 1;

    //     while(!q.empty()){
    //         auto it = q.front();
    //         q.pop();

    //         int row = it.first;
    //         int col = it.second;

    //         if(row == n-1 && col == n-1) return true;

    //         int delrow[] = {-1, 0, 1, 0};
    //         int delcol[] = {0, 1, 0, -1};

    //         for(int i = 0 ; i < 4 ; i++){
    //             int nr = row + delrow[i];
    //             int nc = col + delcol[i];

    //             if(isValid(nr, nc, n) && vis[nr][nc] == 0){
    //                 if(grid[nr][nc] <= level){
    //                     q.push({nr, nc});
    //                     vis[nr][nc] = 1;
    //                 }
    //             }
    //         }
    //     }

    //     return false;
    // }

    // int swimInWater(vector<vector<int>>& grid) {
    //     int n = grid.size();
    //     int low = 0, high = (n*n)-1;

    //     while(low < high){
    //         int mid = (low + high)/2;

    //         if(canReach(mid, n, grid)){
    //             high = mid;
    //         }
    //         else{
    //             low = mid + 1;
    //         }
    //     }

    //     return low;
    // }
};

int main(){
    vector<vector<int>> grid = {{0,2},{1,3}};   // ans = 3;
    vector<vector<int>> grid = {{0,1,2,3,4},{24,23,22,21,5},{12,13,14,15,16},{11,17,18,19,20},{10,9,8,7,6}};   // ans = 16;

    return 0;
}