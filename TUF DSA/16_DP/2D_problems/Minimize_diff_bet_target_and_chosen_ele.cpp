#include<bits/stdc++.h>
using namespace std;

/*      LC = 1981
    You are given an m x n integer matrix mat and an integer target.

    Choose one integer from each row in the matrix such that the absolute difference between target and the sum of the chosen elements is minimized.

    Return the minimum absolute difference.

    The absolute difference between two numbers a and b is the absolute value of a - b.
*/

class Solution {
public:
    int mainTarget;
    int minDiff = INT_MAX;

    int func(int row, int Currsum, vector<vector<int>>& mat, int n, int m, vector<vector<int>>& dp){
        if(row == n){
            return abs(Currsum - mainTarget);
        }

        int mini = INT_MAX;

        if(dp[row][Currsum] != -1) return dp[row][Currsum];

        // if its a valid row or not.
        if(row + 1 <= n){
            for(int col = 0 ; col < m ; col++){
                // this will be like solve for the row+1 and take the currSum as the prevSum + currentRowCol value.     this takes all the first row val.
                mini = min(mini,  func(row+1, Currsum + mat[row][col], mat, n, m, dp));       
            }
        }

        return dp[row][Currsum] = mini;
    }
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        int n = mat.size();
        int m = mat[0].size();

        mainTarget = target;

        vector<vector<int>> dp(n, vector<int>(70*70, -1));

        return func(0, 0, mat, n, m, dp);
    }
};

int main(){
    /*
        Input: mat = [[1,2,3],[4,5,6],[7,8,9]], target = 13
        Output: 0
        Explanation: One possible choice is to:
        - Choose 1 from the first row.
        - Choose 5 from the second row.
        - Choose 7 from the third row.
        The sum of the chosen elements is 13, which equals the target, so the absolute difference is 0.
        Example 2:


        Input: mat = [[1],[2],[3]], target = 100
        Output: 94
        Explanation: The best possible choice is to:
        - Choose 1 from the first row.
        - Choose 2 from the second row.
        - Choose 3 from the third row.
        The sum of the chosen elements is 6, and the absolute difference is 94.
        Example 3:


        Input: mat = [[1,2,9,8,7]], target = 6
        Output: 1
        Explanation: The best choice is to choose 7 from the first row.
        The absolute difference is 1.
        

        Constraints:

        m == mat.length
        n == mat[i].length
        1 <= m, n <= 70
        1 <= mat[i][j] <= 70
        1 <= target <= 800
    */

    return 0;
}