#include<bits/stdc++.h>
using namespace std;

/*      GFG
    Consider a rat placed at position (0, 0) in an n x n square matrix maze[][]. The rat's goal is to reach the destination at position (n-1, n-1). The rat can move in four possible directions: 'U'(up), 'D'(down), 'L' (left), 'R' (right).

    The matrix contains only two possible values:

    0: A blocked cell through which the rat cannot travel.
    1: A free cell that the rat can pass through.
    Your task is to find all possible paths the rat can take to reach the destination, starting from (0, 0) and ending at (n-1, n-1), under the condition that the rat cannot revisit any cell along the same path. Furthermore, the rat can only move to adjacent cells that are within the bounds of the matrix and not blocked.
    If no path exists, return an empty list.

    Note: Return the final result vector in lexicographically smallest order.
*/

class Solution {
  public:
    bool isValid(int nr, int nc, int n){
        return (nr >= 0 && nr < n && nc >= 0 && nc < n);
    }
    void func(int row, int col, string word, int n, vector<vector<int>>& maze, vector<vector<int>>& vis, int delrow[], int delcol[], vector<string>& ans){
        if(row == n-1 && col == n-1){
            ans.push_back(word);
            return;
        }
        
        string direction = "DLRU";      // this for moving in the directions lexicographically
        for(int i = 0 ; i < 4 ; i++){
            int nr = row + delrow[i];
            int nc = col + delcol[i];
            
            if(isValid(nr, nc, n) && !vis[nr][nc] && maze[nr][nc] == 1){
                vis[nr][nc] = 1;
                func(nr, nc, word + direction[i], n, maze, vis, delrow, delcol, ans);
                vis[nr][nc] = 0;
            }
        }
    }
  
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        int n = maze.size();
        vector<string> ans;
        vector<vector<int>> vis(n, vector<int>(n, 0));
        
        int delrow[] = {1, 0, 0, -1};
        int delcol[] = {0, -1, 1, 0};
        
        string word = "";
        
        if(maze[0][0] == 1){
            vis[0][0] = 1;
            func(0, 0, word, n, maze, vis, delrow, delcol, ans); 
        }
        
        return ans;
    }
};

int main(){
    vector<vector<int>> maze= [[1, 0, 0, 0], [1, 1, 0, 1], [1, 1, 0, 0], [0, 1, 1, 1]];
    // ans is : ["DDRDRR", "DRDDRR"]

    return 0;
}