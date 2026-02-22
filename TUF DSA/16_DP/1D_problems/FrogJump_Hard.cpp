#include<bits/stdc++.h>
using namespace std;

bool func(int curr_ind, int lastjump, unordered_map<int,int>& mpp, vector<int>& stones, vector<vector<int>>& dp){
    if(curr_ind == stones.size()-1) return true;

    if(dp[curr_ind][lastjump] != -1) return dp[curr_ind][lastjump];

    int curr_pos = stones[curr_ind];

    for(int i = -1 ; i <= 1 ; i++){
        int nextjump = lastjump+i;
        if(nextjump > 0){
            int tar = curr_pos + nextjump;
            if(mpp.find(tar) != mpp.end()){
                int next_ind = mpp[tar];
                if(func(next_ind, nextjump, mpp, stones, dp) == true) return dp[curr_ind][lastjump] = true;
            }
        }
    }
    return dp[curr_ind][lastjump] = false;
}

bool canCross(vector<int>& stones) {
    int n = stones.size();
    if(n == 1) return true;
    unordered_map<int, int> mpp;

    for(int i = 0 ; i < n ; i++){
        mpp[stones[i]] = i;
    }

    vector<vector<int>> dp(n, vector<int>(n, -1));

    if(mpp.find(1) == mpp.end()) return false;  // this checks if the stone 1 is there or not...becoz its failing the test case [0,2]....my ans is true...real ans is false;

    return func(1, 1, mpp, stones, dp);
}

int main(){
    vector<int> stones = {0,1,3,5,6,8,12,17};
    bool ans = canCross(stones);
    if(ans) cout << "Yes the frog can cross the river";
    else cout << "No impossible";

    return 0;
}