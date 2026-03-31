#include<bits/stdc++.h>
using namespace std;

/*      GFG
    You are given a rectangular matrix mat[][] of size n x m, and your task is to return an array while traversing the matrix in spiral form.
*/

class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int>> &mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        int top = 0, bottom = n-1, left = 0, right = m-1;
        
        vector<int> ans;
        
        while(left <= right && top <= bottom){
            for(int j = left ; j <= right ; j++){
                ans.push_back(mat[top][j]);
            }
            top++;
            
            for(int i = top ; i <= bottom ; i++){
                ans.push_back(mat[i][right]);
            }
            right--;
            
            
            if(top <= bottom){
                for(int j = right ; j >= left ; j--){
                    ans.push_back(mat[bottom][j]);
                }
                bottom--;
            }
            
            if(left <= right){
                for(int i = bottom ; i >= top ; i--){
                    ans.push_back(mat[i][left]);
                }
                left++;
            }
        }
        
        return ans;
    }
};

int main(){
    /*
        Input: mat[][] = [[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12], [13, 14, 15, 16]]
        Output: [1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5, 6, 7, 11, 10]
        
        Input: mat[][] = [[1, 2, 3, 4, 5, 6], [7, 8, 9, 10, 11, 12], [13, 14, 15, 16, 17, 18]]
        Output: [1, 2, 3, 4, 5, 6, 12, 18, 17, 16, 15, 14, 13, 7, 8, 9, 10, 11]

        Input: mat[][] = [[32, 44, 27, 23], [54, 28, 50, 62]]
        Output: [32, 44, 27, 23, 62, 50, 28, 54]
    */

    return 0;
}