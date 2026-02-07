#include<bits/stdc++.h>
using namespace std;

/* Problem Statement:
    We are given two strings ‘S1’ and ‘S2’. We need to convert S1 to S2. The following three operations are allowed:

    Deletion of a character.
    Replacement of a character with another one.
    Insertion of a character.
    We have to return the minimum number of operations required to convert S1 to S2 as our answer. 

*/


// int func(int i, int j, string s1, string s2){
//     if(i<0) return j+1;      // this shows the number of operations to insert the remaining values in s1 to match with s2.
//     if(j<0) return i+1;      // this shows the number of operations to delete the remaining values in s1 to match with s2.

//     if(s1[i] == s2[j]) return func(i-1,j-1,s1,s2);
//     return 1 + min(func(i-1,j,s1,s2), min(func(i,j-1,s1,s2), func(i-1,j-1,s1,s2)));
// }

// int editDis(string s1, string s2){
//     int n = s1.size();
//     int m = s2.size();

//     return func(n-1,m-1,s1,s2);
// }


                // MEMOIZED 1 INDEXING

// int func(int i, int j, string& s1, string& s2, vector<vector<int>>& dp){
//     if(i == 0) return j;
//     if(j == 0) return i;

//     if(s1[i-1] == s2[j-1]) return func(i-1,j-1,s1,s2,dp);
//     return 1 + min(func(i-1,j,s1,s2,dp), min(func(i,j-1,s1,s2,dp), func(i-1,j-1,s1,s2,dp)));
// }

// int editDis(string s1, string s2){
//     int n = s1.size();
//     int m = s2.size();

//     vector<vector<int>> dp(n+1, vector<int>(m+1, -1));

//     return func(n,m,s1,s2,dp);
// }



                // TABULATION APPROACH


int editDis(string s1, string s2){
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));

    for(int j = 0 ; j <= m ; j++) dp[0][j] = j;
    for(int i = 0 ; i <= n ; i++) dp[i][0] = i;

    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            if(s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
        }
    }
    return dp[n][m];
}

int main(){
    string s1 = "intention", s2 = "execution";
    cout << "The min operations for s1 to s2 : " << editDis(s1,s2);
    return 0;
}