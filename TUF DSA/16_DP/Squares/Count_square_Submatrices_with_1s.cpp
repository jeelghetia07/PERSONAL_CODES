// Count_square_Submatrices_with_1s.cpp
#include<bits/stdc++.h>
using namespace std;

int countSubmatrices(vector<vector<int>>& mat){
    int n = mat.size();
    int m = mat[0].size();

    vector<vector<int>> dp(n, vector<int>(m, 0));           // we count the submatrices as the right bottom "1" of each square.

    for(int j = 0 ; j < m ; j++) dp[0][j] = mat[0][j];          // base cases......
    for(int i = 0 ; i < n ; i++) dp[i][0] = mat[i][0];

    for(int i = 1 ; i < n ; i++){
        for(int j = 1 ; j < m ; j++){
            if(mat[i][j] == 0) dp[i][j] = 0;
            else{
                dp[i][j] = 1 + min({dp[i-1][j], dp[i-1][j-1], dp[i][j-1]});
            }
        }
    }
    
    int ans = 0;

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            ans += dp[i][j];
        }
    }
    return ans;
}

int main(){
    vector<vector<int>> mat = {
                    {0,1,1,1},
                    {1,1,1,1},
                    {0,1,1,1}};

    cout << "The number of square submatrices in total is : " <<  countSubmatrices(mat);
    return 0;
}