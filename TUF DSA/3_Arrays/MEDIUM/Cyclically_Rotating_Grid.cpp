#include<bits/stdc++.h>
using namespace std;

/*      LC = 1914
    You are given an m x n integer matrix grid​​​, where m and n are both even integers, and an integer k.

    The matrix is composed of several layers, which is shown in the below image, where each color is its own layer:
    A cyclic rotation of the matrix is done by cyclically rotating each layer in the matrix. To cyclically rotate a layer once, each element in the layer will take the place of the adjacent element in the counter-clockwise direction. An example rotation is shown below:

    Return the matrix after applying k cyclic rotations to it.
*/

class Solution {
public:
    void put_back(int top, int bottom, int left, int right, vector<int>& temp, vector<vector<int>>& grid){
        int k = 0;

        for(int i = left ; i <= right ; i++){
            grid[top][i] = temp[k++];
        }
        for(int i = top+1 ; i <= bottom ; i++){
            grid[i][right] = temp[k++];
        }
        for(int i = right-1 ; i >= left ; i--){
            grid[bottom][i] = temp[k++];
        }
        for(int i = bottom-1 ; i >= top+1 ; i--){
            grid[i][left] = temp[k++];
        }   
    }
    void reverse(int left, int right, vector<int>& arr){
        while(left < right){
            swap(arr[left], arr[right]);
            left++, right--;
        }
    }
    void shiftEle(vector<int>& temp, int k){        // this does left shift and then stores the ele accoridng to the extraction algo
        int n = temp.size();
        reverse(0, k-1, temp);
        reverse(k, n-1, temp);
        reverse(0, n-1, temp);
    }
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        int top = 0, bottom = n-1, left = 0, right = m-1;

        vector<vector<int>> ans(n, vector<int>(m, 0));

        while(top < bottom && left < right){
            vector<int> temp;

            for(int i = left ; i <= right ; i++){
                temp.push_back(grid[top][i]);
            }
            for(int i = top+1 ; i <= bottom ; i++){
                temp.push_back(grid[i][right]);
            }
            for(int i = right-1 ; i >= left ; i--){
                temp.push_back(grid[bottom][i]);
            }
            for(int i = bottom-1 ; i >= top+1 ; i--){
                temp.push_back(grid[i][left]);
            }

            int len = temp.size();
            int rotate = k % len;       // dont do k = k % len, this will modify the enitre k but thats not valid, so we use a temp variable.

            shiftEle(temp, rotate);
            put_back(top, bottom, left, right, temp, ans);

            top++, left++, right--, bottom--;
        }

        return ans;
    }
};

int main(){
    /*
        Input: grid = [[40,10],
                       [30,20]], k = 1
        Output: [[10,20],
                 [40,30]];



        Input: grid = [[1,2,3,4],
                       [5,6,7,8],
                       [9,10,11,12],
                       [13,14,15,16]], k = 2

        Output: [[3,4,8,12],
                [2,11,10,16],
                [1,7,6,15],
                [5,9,13,14]]

    */

    return 0;
}