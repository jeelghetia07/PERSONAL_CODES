#include<bits/stdc++.h>
using namespace std;

/*
    Problem Statement: Given a boolean 2D matrix grid of size N x M. You have to find the number of distinct islands where a group of connected 1s (horizontally or vertically) forms an island. Two islands are considered to be distinct if and only if one island is equal to another (not rotated or reflected)
*/

void dfs(int row, int col, vector<vector<int>>& vis, vector<vector<int>>& grid, vector<pair<int, int>>& vec, int row0, int col0, int n, int m){
    vis[row][col] = 1;
    vec.push_back({row-row0, col-col0});

    int delrow[] = {-1, 0, 1, 0};
    int delcol[] = {0, 1, 0, -1};

    for(int i = 0 ; i < 4 ; i++){
        int nr = row + delrow[i];
        int nc = col + delcol[i];

        if(nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && grid[nr][nc] == 1){
            dfs(nr, nc, vis, grid, vec, row0, col0, n, m);
        }
    }
}

int countDistinctIslands(vector<vector<int>>& grid){
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> vis(n, vector<int>(m, 0));
    set<vector<pair<int, int>>> st;

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(!vis[i][j] && grid[i][j] == 1){
                vector<pair<int, int>> vec;
                dfs(i, j, vis, grid, vec, i, j, n, m);
                st.insert(vec);
            }
        }
    }
    return st.size();
}


int main(){
    vector<vector<int>> grid = 
            {{1, 1, 0, 0, 0},
            {1, 1, 0, 0, 0},
            {0, 0, 0, 1, 1},
            {0, 0, 0, 1, 1}};

    cout << "The number of distinct islands are : " << countDistinctIslands(grid);
    return 0;
}