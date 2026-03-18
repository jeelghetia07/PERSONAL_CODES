#include<bits/stdc++.h>
using namespace std;

/*      LC = 51
    The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

    Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

    Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.
*/

class Solution {
    bool isSafe(int row, int col, int n, vector<string>& board){       //i know that i have to just check only 3 dire for safety that are..... NorthWest (NW), W, SW...because we go ahead after placing the queens to the left...so we check only the left part.
        int duprow = row , dupcol = col;

        while(row >= 0 && col >= 0){        // in the NW direction (upper left diagonal)
            if(board[row][col] == 'Q') return false;
            row--;
            col--;
        }

        row = duprow, col = dupcol;

        while(col >= 0){
            if(board[row][col] == 'Q') return false;
            col--;
        }

        row = duprow, col = dupcol;

        while(row < n && col >= 0){
            if(board[row][col] == 'Q') return false;
            row++;
            col--;
        }
        return true;
    }
public:
    void func(int col, vector<string>& board, vector<vector<string>>& ans, int n){
        if(col == n){
            ans.push_back(board);
            return;
        }

        for(int row = 0 ; row < n ; row++){
            if(isSafe(row, col, n, board)){
                board[row][col] = 'Q';
                func(col+1, board, ans, n);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');

        for(int i = 0 ; i < n ; i++){
            board[i] = s;
        }

        func(0, board, ans, n);

        return ans;
    }
};

int main(){
    int n = 4;
    // [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
    Solution obj;
    vector<vector<string>> ans = obj.solveNQueens(n);

    return 0;
}