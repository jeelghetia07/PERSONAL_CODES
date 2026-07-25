#include<bits/stdc++.h>
using namespace std;

/*      GFG
    Given a row-wise sorted matrix mat[][] of size n x m, where the number of rows and columns is always odd. Return the median of the matrix.
*/

class Solution {
  public:
    int upperBound(vector<int>& arr, int x){
        int n = arr.size();
        
        return (upper_bound(arr.begin(), arr.end(), x)-arr.begin());
    }
    
    int blackbox(vector<vector<int>>& mat, int x){      // this func will tell me how many ele are smaller than or equal to x.
        int cnt = 0;
            
        for(int i = 0 ; i < mat.size() ; i++){
            cnt += upperBound(mat[i], x);
        }
        
        return cnt;
    }
    
    int median(vector<vector<int>> &mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        int reqEle = (n*m)/2;
        
        int low = INT_MAX, high = -1;
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                low = min(low, mat[i][j]);
                high = max(high, mat[i][j]);
            }
        }
        
        while(low <= high){
            int mid = (low+high) / 2;
            
            int smallerEquals = blackbox(mat, mid);
            if(smallerEquals <= reqEle){
                low = mid+1;
            }
            else high = mid-1;
        }
        
        return low;
    }
};

// TC -> log(1e9) * n * logm;       BS * BB

int main(){
    /*
        Input: mat[][] = [[1, 3, 5], [2, 6, 9], [3, 6, 9]]
        Output: 5
        Explanation: Sorting matrix elements gives us [1, 2, 3, 3, 5, 6, 6, 9, 9]. Hence, 5 is median.
        Input: mat[][] = [[2, 4, 9], [3, 6, 7], [4, 7, 10]]
        Output: 6
        Explanation: Sorting matrix elements gives us [2, 3, 4, 4, 6, 7, 7, 9, 10]. Hence, 6 is median.
        Input: mat = [[3], [4], [8]]
        Output: 4
        Explanation: Sorting matrix elements gives us [3, 4, 8]. Hence, 4 is median.
    */

    return 0;
}