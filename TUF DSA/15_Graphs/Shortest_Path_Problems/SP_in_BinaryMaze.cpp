#include<bits/stdc++.h>
using namespace std;

/*
    Given a n * m matrix grid where each element can either be 0 or 1. You need to find the shortest distance between a given source cell to a destination cell. The path can only be created out of a cell if its value is 1. 

    If the path is not possible between source cell and destination cell, then return -1.

    Note : You can move into an adjacent cell if that adjacent cell is filled with element 1. Two cells are adjacent if they share a side. In other words, you can move in one of the four directions, Up, Down, Left and Right. The source and destination cell are based on the zero based indexing. The destination cell should be 1.
*/

int shortestPath(vector<vector<int>> &grid, pair<int, int> src, pair<int, int> dst) {
    if(src.first == dst.first && src.second == dst.second) return 0;
    
    int n = grid.size();
    int m = grid[0].size();
    
    queue<pair<int, pair<int, int>>> q;
    vector<vector<int>> dis(n, vector<int>(m , 1e9));
    
    dis[src.first][src.second] = 0;
    q.push({0, {src.first, src.second}});
    
    int delrow[] = {-1, 0, 1, 0};
    int delcol[] = {0, 1, 0, -1};
    
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        
        int d = it.first;
        int r = it.second.first;
        int c = it.second.second;
        
        for(int i = 0 ; i < 4 ; i++){
            int nr = r + delrow[i];
            int nc = c + delcol[i];
            
            if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1 && d + 1 < dis[nr][nc]){
                dis[nr][nc] = d + 1;
                if(nr == dst.first && nc == dst.second){
                    return dis[nr][nc];
                }
                q.push({dis[nr][nc], {nr, nc}});
            }
        }
    }
    return -1;
}

int main(){
    vector<vector<int>> grid = 
            {{1, 1, 1, 1},
            {1, 1, 0, 1},
            {1, 1, 1, 1},
            {1, 1, 0, 0},
            {1, 0, 0, 1}};
    pair<int, int> source = {0, 1};
    pair<int, int> destination = {2, 2};

    cout << "The SD is : " << shortestPath(grid,source, destination);
    return 0;
}