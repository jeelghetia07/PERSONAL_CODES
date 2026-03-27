// Max_Rec_area_with_1s.cpp
#include<bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int>& arr) {
    int n = arr.size();
    stack<int> st;          // we are storing the indexes.
    int maxAns = INT_MIN;

    for(int i = 0 ; i < n ; i++){
        while(!st.empty() && arr[st.top()] >= arr[i]){
            int element = st.top();
            st.pop();
            int nse = i;        // as we only pop when we find a smaller element than the top....so obv the next smaller element will be the i (which is smaller than top)....
            int pse = st.empty() ? -1 : st.top();
            maxAns = max(maxAns, arr[element] * (nse-pse-1));
        }
        st.push(i);
    }

    while(!st.empty()){    // if there are any elements left in the stack....for all them,....the nse will be n becoz....there are in the stack due to no further smaller elements(which can pop them out)....
        int nse = n;
        int element = st.top();
        st.pop();
        int pse = st.empty() ? -1 : st.top();
        maxAns = max(maxAns, arr[element] * (nse-pse-1));
    }
    return maxAns;
}
int maximalRectangle(vector<vector<char>>& mat) {
    int n = mat.size(), m = mat[0].size();
    vector<int> heights(m, 0);
    int maxArea = INT_MIN;

    for(int i = 0 ; i < n ; i++){       // traversing all rows.
        for(int j = 0 ; j < m ; j++){       // traversing all cols.
            if(mat[i][j] == '1') heights[j]++;      // if in the next row we get 1 then increase 1 to the heights....think like a histogram height.
            else heights[j] = 0;
        }
        int area = largestRectangleArea(heights);
        maxArea = max(maxArea, area);
    }
    return maxArea;
}

int main(){
    vector<vector<char>> mat ={
                {'1','0','1','0','0'},
                {'1','0','1','1','1'},
                {'1','1','1','1','1'},
                {'1','0','0','1','0'}};

    cout << "the max area of all 1's is : " << maximalRectangle(mat);
    return 0;
}