#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // int solve(int ind, const vector<int>& height, vector<int>& dp) {
    //     if (ind == 0) return 0;

    //     if (dp[ind] != -1) return dp[ind];

    //     int jumpTwo = INT_MAX;

    //     int jumpOne = solve(ind - 1, height, dp) + abs(height[ind] - height[ind - 1]);

    //     if (ind > 1) {
    //         jumpTwo = solve(ind - 2, height, dp) + abs(height[ind] - height[ind - 2]);
    //     }

    //     return dp[ind] = min(jumpOne, jumpTwo);
    // }
    // int frogJump(const vector<int>& height) {
    //     // Handle empty input
    //     if (height.empty()) return 0;

    //     int n = (int)height.size();
    //     vector<int> dp(n, -1);

    //     return solve(n - 1, height, dp);
    // }




    int frogJump(const vector<int>& height) {
        if (height.empty()) return 0;
        int n = (int)height.size();
        vector<int> dp(n, 0);

        dp[0] = 0;

        for(int ind = 1 ; ind < n ; ind++){
            int jumpTwo = INT_MAX;
            int jumpOne = dp[ind - 1] + abs(height[ind] - height[ind - 1]);
            if (ind > 1) {
                jumpTwo = dp[ind - 2] + abs(height[ind] - height[ind - 2]);
            }
            dp[ind] = min(jumpOne, jumpTwo);
        }
        return dp[n-1];
    }
};

int main(){
    vector<int> height{30, 10, 60, 10, 60, 50};
    Solution sol;

    cout << sol.frogJump(height) << endl; // Expected: 40

    return 0;
}