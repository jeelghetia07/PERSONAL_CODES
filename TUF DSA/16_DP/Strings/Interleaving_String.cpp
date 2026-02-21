#include<bits/stdc++.h>
using namespace std;

/*      LC : 97

    Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1 and s2.

    An interleaving of two strings s and t is a configuration where s and t are divided into n and m substrings respectively, such that:

    s = s1 + s2 + ... + sn
    t = t1 + t2 + ... + tm
    |n - m| <= 1
    The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + t3 + s3 + ...
    Note: a + b is the concatenation of strings a and b.
*/


                // RECURSION VERSION

// bool func(int i, int j, string& s1, string& s2, string& s3, vector<vector<int>>& dp){

//     if(i == 0 && j == 0) return dp[i][j] = true;
//     if(dp[i][j] != -1) return dp[i][j];
//     // else if(i < 0 && j >= 0){        // this base cases are handled by the recursive part already.
//     //     for(int ind2 = j ; ind2 >= 0 ; ind2--){
//     //         if(s2[ind2] != s3[k]) return false;
//     //         else k--;
//     //     }
//     //     return true;
//     // }
//     // else if(j < 0 && i >= 0){
//     //     for(int ind1 = i ; ind1 >= 0 ; ind1--){
//     //         if(s1[ind1] != s3[k]) return false;
//     //         else k--;
//     //     }
//     //     return true;
//     // }

//     bool ans = false;

//     if(i > 0 && s1[i-1] == s3[i+j-1]){
//         ans = ans || func(i-1, j, s1, s2,s3, dp);
//     }
//     if(j > 0 && s2[j-1] == s3[i+j-1]){
//         ans = ans || func(i, j-1, s1, s2,s3, dp);
//     }
//     return dp[i][j] = ans;
// }
// bool isInterleave(string s1, string s2, string s3) {
//     int n = s1.size();
//     int m = s2.size();
//     int p = s3.size();

//     if(n + m != p) return false;

//     vector<vector<int>> dp(n+1, vector<int>(m+1, -1));

//     return func(n, m, s1, s2, s3, dp);
// }



                // MEMOIZED VERSION

bool func(int i, int j, string& s1, string& s2, string& s3, vector<vector<int>>& dp){
    if(i == 0 && j == 0) return dp[i][j] = true;
    if(dp[i][j] != -1) return dp[i][j];
    // else if(i < 0 && j >= 0){        // this base cases are handled by the recursive part already.
    //     for(int ind2 = j ; ind2 >= 0 ; ind2--){
    //         if(s2[ind2] != s3[k]) return false;
    //         else k--;
    //     }
    //     return true;
    // }
    // else if(j < 0 && i >= 0){
    //     for(int ind1 = i ; ind1 >= 0 ; ind1--){
    //         if(s1[ind1] != s3[k]) return false;
    //         else k--;
    //     }
    //     return true;
    // }

    bool ans = false;

    if(i > 0 && s1[i-1] == s3[i+j-1]){
        ans = ans || func(i-1, j, s1, s2,s3, dp);
    }
    if(j > 0 && s2[j-1] == s3[i+j-1]){
        ans = ans || func(i, j-1, s1, s2,s3, dp);
    }
    return dp[i][j] = ans;
}
bool isInterleave(string s1, string s2, string s3) {
    int n = s1.size();
    int m = s2.size();
    int p = s3.size();

    if(n + m != p) return false;

    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));

    return func(n, m, s1, s2, s3, dp);
}


int main(){
    // string s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc";   // false
    string s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac";   // true;
    bool ans = isInterleave(s1,s2,s3);
    if(ans){
        cout << "Yes";
    }
    else{
        cout << "No";
    }
    return 0;
}