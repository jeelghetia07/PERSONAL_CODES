// Evaluate_Boolean_Exp_to_True.cpp
#include<bits/stdc++.h>
using namespace std;
#define ll long long


                // MEMOIZATION

// ll f(int i, int j, int isTrue, string& exp, vector<vector<vector<int>>>& dp){
//     if(i > j) return 0;
//     if(i == j){
//         if(isTrue){
//             return exp[i] == 'T';
//         }
//         else return exp[i] == 'F';
//     }
//     if(dp[i][j][isTrue] != -1) return dp[i][j][isTrue];
//     ll ways = 0;
//     for(int ind = i+1 ; ind <= j-1 ; ind += 2){
//         ll LT = f(i, ind-1, 1, exp, dp);
//         ll LF = f(i, ind-1, 0, exp, dp);
//         ll RT = f(ind+1, j, 1, exp, dp);
//         ll RF = f(ind+1, j, 0, exp, dp);

//         if(exp[ind] == '&'){
//             if(isTrue) ways += (RT*LT);
//             else ways += (RT*LF) + (RF*LT) + (RF*LF);
//         }
//         else if(exp[ind] == '|'){
//             if(isTrue) ways += (LT*RT + LT*RF + LF*RT);
//             else ways += LF * RF;
//         }
//         else{
//             // T^T = F , F^F = F , T^F = T , F^T = T
//             if(isTrue) ways += (LT*RF + LF*RT);
//             else ways += (LT*RT + LF*RF);
//         }
//     }
//     return dp[i][j][isTrue] = ways;
// }

// int evaluate(string& exp){
//     int n = exp.size();
//     vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, -1)));
//     return f(0, n-1, 1, exp, dp);
// }



                // TABULATION

int evaluate(string& exp){
    int n = exp.size();
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(n+1, vector<int>(2, 0)));

    for(int i = 0 ; i < n ; i++){       // for any i == j
        dp[i][i][1] = (exp[i] == 'T');
        dp[i][i][0] = (exp[i] == 'F');
    }

    for(int i = n-1 ; i >= 0 ; i--){
        for(int j = 0 ; j <= n-1 ; j++){
            if(i > j) continue;
            
            for(int ind = i+1 ; ind <= j-1 ; ind += 2){
                ll LT = dp[i][ind-1][1];
                ll LF = dp[i][ind-1][0];
                ll RT = dp[ind+1][j][1];
                ll RF = dp[ind+1][j][0];

                if(exp[ind] == '&'){
                    dp[i][j][1] += (RT*LT);
                    dp[i][j][0] += (RT*LF) + (RF*LT) + (RF*LF);
                }
                else if(exp[ind] == '|'){
                    dp[i][j][1] += (LT*RT + LT*RF + LF*RT);
                    dp[i][j][0] += LF * RF;
                }
                else{
                    // T^T = F , F^F = F , T^F = T , F^T = T
                    dp[i][j][1] += (LT*RF + LF*RT);
                    dp[i][j][0] += (LT*RT + LF*RF);
                }
            }
        }
    }
    return dp[0][n-1][1];
}

int main(){
    string exp = "T|F&T";
    cout << "The total ways of true is : " << evaluate(exp);
    return 0;
}