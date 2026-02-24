#include<bits/stdc++.h>
using namespace std;

/*      GFG     main thing is ADJECENT....read in book for better clarity....
    You are given a matrix mat[][] of size n*m containing english alphabets and a string word. Check if the word exists on the mat[][] or not. The word can be constructed by using letters from adjacent cells, either horizontally or vertically. The same cell cannot be used more than once.
*/

bool dfs(int row, int col, vector<vector<char>> &grid, string &word, vector<vector<int>>& vis, int n, int m, int ptr, int sz){
    vis[row][col] = 1;
    
    if(ptr == sz-1) return true;
    
    int delrow[] = {-1, 0, 1, 0};
    int delcol[] = {0, 1, 0, -1};
    
    for(int i = 0 ; i < 4 ; i++){
        int nr = row + delrow[i];
        int nc = col + delcol[i];
        
        if(nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && grid[nr][nc] == word[ptr+1]){
            if(dfs(nr, nc, grid, word, vis, n, m, ptr+1, sz)) return true;
        }
    }
    vis[row][col] = 0;
    return false;
}
bool isWordExist(vector<vector<char>> &grid, string &word) {
    // Code here
    int n = grid.size();
    int m = grid[0].size();
    
    vector<vector<int>> vis(n, vector<int>(m, 0));
    
    int ptr = 0;
    
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(grid[i][j] == word[ptr]){
                if(dfs(i, j, grid, word, vis, n, m, ptr, word.size())) return true;
            }
        }
    }
    return false;
}

int main(){
    vector<vector<char>> mat = {{'T', 'E', 'E'}, {'S', 'G', 'K'}, {'T', 'E', 'L'}};
    string word = "GEEK";       // ans is true;

    // vector<vector<char>> mat = {{'T', 'E', 'U'}, {'S', 'G', 'K'}, {'T', 'E', 'L'}};
    // string word = "GEEK";       // ans is false;


}