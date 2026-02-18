#include<bits/stdc++.h>
using namespace std;

/*
    You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns, where heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can move up, down, left, or right, and you wish to find a route that requires the minimum effort.

    A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.

    Return the minimum effort required to travel from the top-left cell to the bottom-right cell.
*/

int minCostPath(vector<vector<int>>& grid) {
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> vis(n, vector<int>(m, 1e9));
    vis[0][0] = 0;

    pq.push({0, {0,0}});

    int delrow[] = {-1, 0, 1, 0};
    int delcol[] = {0, 1, 0, -1};

    // TC = O(E logV)
    // .....O(n*m*4 log(n*m));

    while(!pq.empty()){
        int effort = pq.top().first;
        int r = pq.top().second.first;
        int c = pq.top().second.second;
        pq.pop();

        if(effort > vis[r][c]) continue;
        if(r == n-1 && c == m-1) return effort;

        for(int i = 0 ; i < 4 ; i++){
            int nr = r + delrow[i];
            int nc = c + delcol[i];

            if(nr >= 0 && nr < n && nc >= 0 && nc < m){
                int edgeDiff = abs(grid[nr][nc] - grid[r][c]);
                int newEffort = max(effort, edgeDiff);
                
                if(newEffort < vis[nr][nc]){
                    vis[nr][nc] = newEffort;
                    pq.push({newEffort, {nr, nc}});
                }
            }
        }
    }
    return 0;
}

int main(){
    vector<vector<int>> grid = {{1,2,2},{3,8,2},{5,3,5}};
    int ans = minCostPath(grid);

    cout << "The min effort is : " << ans;

    return 0;
}