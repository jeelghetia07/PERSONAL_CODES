#include<bits/stdc++.h>
using namespace std;

/*      LC = 221
    Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.
*/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dp(n, vector<int>(m, 0));

        for(int i = 0 ; i < n ; i++) dp[i][0] = (grid[i][0] - '0');
        for(int j = 0 ; j < m ; j++) dp[0][j] = (grid[0][j] - '0');

        for(int i = 1 ; i < n ; i++){
            for(int j = 1 ; j < m ; j++){
                if(grid[i][j] == '1')
                    dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
                else{
                    dp[i][j] = 0;
                }
            }
        }

        int maxSide = 0;

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                maxSide = max(maxSide, dp[i][j]);
            }
        }

        return maxSide*maxSide;
    }
};

int main(){
    /*
        Input: matrix = [["1","0","1","0","0"],
                         ["1","0","1","1","1"],
                         ["1","1","1","1","1"],
                         ["1","0","0","1","0"]]
        Output: 4
    */

    return 0;
}