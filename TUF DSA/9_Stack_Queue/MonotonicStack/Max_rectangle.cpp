#include<bits/stdc++.h>
using namespace std;

/*      LC = 85
    Given a 2D binary matrix mat[][], where each cell contains either 0 or 1. Find the maximum area of a rectangle that can be formed using only 1's within the matrix.
*/


class Solution {
  public:
    int largestRect(vector<int>& arr){
        int n = arr.size();
        int maxi = 0;
        
        stack<int> st;
       
        for(int i = 0 ; i < n ; i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                int ind = st.top();
                st.pop();
                
                int nse = i;
                int pse = st.empty() ? -1 : st.top();
                
                maxi = max(maxi, arr[ind] * (nse - pse - 1));
            }
            st.push(i);
        }
        
        while(!st.empty()){
            int ind = st.top();
            st.pop();
            
            int nse = n;
            int pse = st.empty() ? -1 : st.top();
            
            maxi = max(maxi, arr[ind] * (nse - pse - 1));
        }
        
        return maxi;
    }
    int maxArea(vector<vector<int>> &mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        
        vector<int> heights(m, 0);
        int maxi = 0;
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                heights[j] += mat[i][j];
                if(mat[i][j] == 0) heights[j] = 0;     // if the point is 0, there is no meaning of a histgram above 0, so we put a 0 there.
            }
            int area = largestRect(heights);
            maxi = max(maxi, area);
        }
        
        return maxi;
    }
};

int main(){
    /*
        Examples:

        Input: mat[][] = [[0, 1, 1, 0], [1, 1, 1, 1], [1, 1, 1, 1], [1, 1, 0, 0]]
        Output: 8
        Explanation: The largest rectangle of 1's highlighted in green, matching the area of 2 * 4 = 8.

        Input: mat[][] = [[0, 1, 1], [1, 1, 1], [0, 1, 1]]
        Output: 6
        Explanation: The largest rectangle of 1's highlighted in green, matching the area of 3 * 2 = 6.

        Constraints:
        1 ≤ mat.size(), mat[i].size() ≤ 1000
        0 ≤ mat[][] ≤ 1
    */

    return 0;
}