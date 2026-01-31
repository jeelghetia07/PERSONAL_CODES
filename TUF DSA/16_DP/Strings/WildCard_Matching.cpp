#include<bits/stdc++.h>
using namespace std;

/* 
    Problem Statement: We are given two strings ‘S1’ and ‘S2’. String S1 can have the following two special characters.
    ‘?’ can be matched to a single character of S2.
    ‘*’ can be matched to any sequence of characters of S2. (sequence can be of length zero or more).
    We need to check whether strings S1 and S2 match or not.
    
*/



// bool func(int i, int j, string& s1, string& s2){
//     if(i <0 && j<0) return true;
//     if(i < 0 && j >= 0) return false;
//     if(j < 0 && i >= 0){        // if s2 is over means empty string...and s1 is there....then in s1 there should only be * for returning true.
//         for(int idx = 0 ; idx <= i ; idx++){
//             if(s1[idx] != '*') return false;
//         }
//         return true;
//     }

//     if(s1[i] == s2[j] || s1[i] == '?'){
//         return func(i-1, j-1, s1, s2);
//     }
//     if(s1[i] == '*'){
//         return (func(i-1, j, s1, s2)         // this means stars says nothing..so remove * and compare normally.
//             | func(i, j-1, s1, s2));         // this says let * be matched with the jth ele and move j-1....and compare other ele for removal.
//     }
//     return false;
// }

// bool wildcard(string pattern, string text){
//     int n = pattern.size();
//     int m = text.size();

//     return func(n-1, m-1, pattern, text);
// }





                    // MEMOIZATION

// bool func(int i, int j, string& s1, string& s2, vector<vector<int>>& dp){
//     if(i <0 && j<0) return true;
//     if(i < 0 && j >= 0) return false;
//     if(j < 0 && i >= 0){        // if s2 is over means empty string...and s1 is there....then in s1 there should only be * for returning true.
//         for(int idx = 0 ; idx <= i ; idx++){
//             if(s1[idx] != '*') return false;
//         }
//         return true;
//     }
//     if(dp[i][j] != -1) return dp[i][j];

//     if(s1[i] == s2[j] || s1[i] == '?'){
//         return dp[i][j] = func(i-1, j-1, s1, s2, dp);
//     }
//     if(s1[i] == '*'){
//         return dp[i][j] = (func(i-1, j, s1, s2, dp)         // this means stars says nothing..so remove * and compare normally.
//             | func(i, j-1, s1, s2, dp));         // this says let * be matched with the jth ele and move j-1....and compare other ele for removal.
//     }
//     return dp[i][j] = false;
// }

// bool wildcard(string pattern, string text){
//     int n = pattern.size();
//     int m = text.size();

//     vector<vector<int>> dp(n, vector<int>(m, -1));

//     return func(n-1, m-1, pattern, text, dp);
// }






                        // 1 based indexing

// bool func(int i, int j, string& s1, string& s2, vector<vector<int>>& dp){
//     if(i == 0 && j == 0) return true;
//     if(i == 0 && j > 0) return false;
//     if(j == 0 && i > 0){        // if s2 is over means empty string...and s1 is there....then in s1 there should only be * for returning true.
//         for(int idx = 1 ; idx <= i ; idx++){        // its 1 based indexing so traverse from 1. 
//             if(s1[idx-1] != '*') return false;
//         }
//         return true;
//     }
//     if(dp[i][j] != -1) return dp[i][j];

//     if(s1[i-1] == s2[j-1] || s1[i-1] == '?'){
//         return dp[i][j] = func(i-1, j-1, s1, s2, dp);
//     }
//     if(s1[i-1] == '*'){
//         return dp[i][j] =  (func(i-1, j, s1, s2, dp)         // this means stars says nothing..so remove * and compare normally.
//             | func(i, j-1, s1, s2, dp));         // this says let * be matched with the jth ele and move j-1....and compare other ele for removal.
//     }
//     return dp[i][j] = false;
// }

// bool wildcard(string pattern, string text){
//     int n = pattern.size();
//     int m = text.size();

//     vector<vector<int>> dp(n+1, vector<int>(m+1, -1));

//     return func(n, m, pattern, text, dp);
// }





                        // TABULATION

bool wildcard(string s1, string s2){
    int n = s1.size();
    int m = s2.size();

    vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));
    dp[0][0] = true;
    for(int j = 1 ; j <= m ; j++){
        dp[0][j] = false;
    }

    for(int i = 1 ; i <= n ; i++){
        int flag = true;
        for(int idx = 1 ; idx <= i ; idx++){        // its 1 based indexing so traverse from 1. 
            if(s1[idx-1] != '*'){
                flag = false    ;
                break;
            }
        }
        dp[i][0] = flag;
    }

    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            if(s1[i-1] == s2[j-1] || s1[i-1] == '?'){
                return dp[i][j] = dp[i-1][j-1];
            }
            else if(s1[i-1] == '*'){
                return dp[i][j] =  (dp[i-1][j]        // this means stars says nothing..so remove * and compare normally.
                    | dp[i][j-1]);         // this says let * be matched with the jth ele and move j-1....and compare other ele for removal.
            }
            else dp[i][j] = false;
        }
    }
    return dp[n][m]; 
}


int main(){
    string s1 = "ab*c?", s2 = "abdefcd";
    if(wildcard(s1,s2)){
        cout << "Both strings match." << endl;
    }
    else{
        cout << "NO match" << endl;
    }
    return 0;
}