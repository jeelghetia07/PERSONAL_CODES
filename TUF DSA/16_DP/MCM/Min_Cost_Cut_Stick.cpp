// Min_Cost_Cut_Stick.cpp
#include<bits/stdc++.h>
using namespace std;

// int func(int i, int j, vector<int>& cuts){
//     if(i > j) return 0;
//     int mini = INT_MAX;

//     for(int ind = i; ind <= j ; ind++){
//        int cost = cuts[j+1] - cuts[i-1] + func(i, ind-1, cuts) + func(ind+1, j, cuts); 
//        mini = min(mini, cost);
//     }
//     return mini;
// }

// int cost(int n, int c, vector<int>& cuts){
//     cuts.push_back(n);              // at last.
//     cuts.insert(cuts.begin(),0);     // inserts the element at the front.
//     sort(cuts.begin(), cuts.end());
//     return func(1, c, cuts);
// }



                // MEMOIZATION

// int func(int i, int j, vector<int>& cuts, vector<vector<int>>& dp){
//     if(i > j) return 0;
//     int mini = INT_MAX;
//     if(dp[i][j] != -1) return dp[i][j];
//     for(int ind = i ; ind <= j ; ind++){
//         int cost = cuts[j+1]-cuts[i-1] + func(i, ind-1, cuts, dp) + func(ind+1, j, cuts, dp);
//         mini = min(cost, mini);
//     }
//     return dp[i][j] = mini;
// }

// int cost(int n, int c, vector<int>& cuts){
//     cuts.push_back(n);              // at last.
//     cuts.insert(cuts.begin(),0);     // inserts the element at the front.
//     sort(cuts.begin(), cuts.end());
//     vector<vector<int>> dp(c+1, vector<int>(c+1, -1));
//     return func(1, c, cuts, dp);
// }



                // TABULATION

int cost(int n, int c, vector<int>& cuts){
    cuts.push_back(n);              // at last.
    cuts.insert(cuts.begin(),0);     // inserts the element at the front.
    sort(cuts.begin(), cuts.end());
    vector<vector<int>> dp(c+2, vector<int>(c+2, 0));       // check the loop there is ind+1...but the i is from n...so it can go out of bounds...so we do +1 to the array size;

    for(int i = c ; i >= 1 ; i--){
        for(int j = 1 ; j <= c ; j++){
            if(i > j) continue;
            int mini = INT_MAX;
            for(int ind = i ; ind <= j ; ind++){
                int cost = cuts[j+1]-cuts[i-1] + dp[i][ind-1] + dp[ind+1][j];
                mini = min(cost, mini);
            }
            dp[i][j] = mini;
        }
    }
    return dp[1][c];
}

int main(){
    vector<int> cuts = {1,3,4,5};       // if given not sorted then firstly sort the complete array and then perform the steps.
    cout << "the minimum cost is : " << cost(7, cuts.size(), cuts);
    return 0;
}