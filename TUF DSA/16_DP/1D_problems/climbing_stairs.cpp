#include<bits/stdc++.h>
using namespace std;

// int func(int ind){
//     if(ind == 0 || ind == 1) return 1;
//     int left = func(ind-1);
//     int right = func(ind-2);
//     return left + right;
// }

int climbStairs(int n) {
    // return func(n);

    vector<int> dp(n+1);

    dp[0] = 1, dp[1] = 1;
    
    for(int i = 2 ; i <= n ; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

int main(){

}