#include<bits/stdc++.h>
using namespace std;

/*      LC = 240
    Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

    Integers in each row are sorted in ascending from left to right.
    Integers in each column are sorted in ascending from top to bottom.
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int n = mat.size();
        int m = mat[0].size();

        int row = 0, col = m-1;

        while(row < n && col >= 0){
            int val = mat[row][col];
            if(val == target){
                return true;
            }
            else if(val < target){
                row++;
            }
            else col--;
        }

        return false;
    }
};

// TC is O(n+m) , SC = O(1).

int main(){
    /*
        Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
        Output: true
    */

    return 0;
}