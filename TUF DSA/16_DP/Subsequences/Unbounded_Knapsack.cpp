#include<bits/stdc++.h>
using namespace std;

// PROBLEM : 
/*  

*/


                    // MEMOIZATION APPROACH

// int f(int ind, int tarW, vector<int>& val, vector<int>& wt){
//     if(ind == 0){
//         return (tarW / wt[0]) * val[0];
//     }

//     int nontake = 0 + f(ind-1, tarW, val, wt);
//     int take = INT_MIN;
//     if(tarW >= wt[ind]) take = val[ind] + f(ind, tarW-wt[ind], val, wt);    // add the val becoz we want the maximum value.

//     return max(take, nontake);
// }



                    // TABULATION APPROACH.

int calc(int n, int tarw, vector<int>& val, vector<int>& wt){
    vector<vector<int>> dp(n, vector<int>(tarw+1, -1));

    for(int W = 0 ; W <= tarw ; W++){
        dp[0][W] = ((int) (W/wt[0])) * val[0];
    }

    for(int ind = 1 ; ind < n ; ind++){
        for(int tar = 0 ; tar <= tarw ; tar++){
            int nontake = 0 + dp[ind-1][tar];
            int take = INT_MIN;
            if(tar >= wt[ind]) take = val[ind] + dp[ind][tar-wt[ind]];

            dp[ind][tar] = max(take, nontake);
        }
    }
    return dp[n-1][tarw];
    // return f(n, w, val, wt);
}

int main(){
    vector<int> val = {5,11,13};
    vector<int> wt = {2,4,6};

    int n = wt.size();
    int w = 10;     // its the bag weight.

    cout << "The maximum is : " << calc(n, w, val, wt);
    return 0;
}