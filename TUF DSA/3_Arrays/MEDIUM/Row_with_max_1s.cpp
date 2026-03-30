#include<bits/stdc++.h>
using namespace std;

/*      GFG
    You are given a 2D binary array arr[][] consisting of only 1s and 0s. Each row of the array is sorted in non-decreasing order. Your task is to find and return the index of the first row that contains the maximum number of 1s. If no such row exists, return -1.

    Note:
    The array follows 0-based indexing.
    The number of rows and columns in the array are denoted by n and m respectively.
*/

class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        int n = arr.size();
        int m = arr[0].size();
        
        int i = 0, j = m-1;
        int maxRow = -1;
        
        while(i < n && j >= 0){
            if(arr[i][j] == 1){
                maxRow = i;
                j--;
            }
            else i++;
        }
        
        return maxRow;
        
        
        
        
        
        // vector<int> ans(n, 0);
        
        // for(int i = 0 ; i < n ; i++){
        //     int cnt = 0;
        //     for(int j = m-1 ; j >= 0 ; j--){
        //         if(arr[i][j] == 1) cnt++;
        //         else break;
        //     }
        //     ans[i] = cnt;
        // }
        
        // int maxi = -1, maxInd = -1;
        
        // for(int i = 0 ; i < n ; i++){
        //     if(maxi < ans[i]){
        //         maxi = ans[i];
        //         maxInd = i;
        //     }
        // }
        // if(maxi == 0) return -1;
        // return maxInd;
    }
};

int main(){
    /*
        Input: arr[][] = [[0,1,1,1], [0,0,1,1], [1,1,1,1], [0,0,0,0]]
        Output: 2
        Explanation: Row 2 contains the most number of 1s (4 1s). Hence, the output is 2.

        Input: arr[][] = [[0,0], [1,1]]
        Output: 1
        Explanation: Row 1 contains the most number of 1s (2 1s). Hence, the output is 1.
        
        Input: arr[][] = [[0,0], [0,0]]
        Output: -1
        Explanation: No row contains any 1s, so the output is -1.
    */

    return 0;
}