#include<bits/stdc++.h>
using namespace std;

/*      LC = 377
    Given an array of distinct integers nums and a target integer target, return the number of possible combinations that add up to target.

    The test cases are generated so that the answer can fit in a 32-bit integer.
*/

class Solution {
public:
    int func(int tar, vector<int>& nums, vector<int>& dp){
        if(tar == 0) return 1;
        if(tar < 0) return 0;

        if(dp[tar] != -1) return dp[tar];

        int ways = 0;

        for(int val : nums){
            ways += func(tar-val, nums, dp);
        }

        return dp[tar] = ways;
    }
    int combinationSum4(vector<int>& nums, int tar) {
        int n = nums.size();
        vector<int> dp(tar+1, -1);
        return func(tar, nums, dp);
    }


                // TABULATION


    // int combinationSum4(vector<int>& nums, int tar){
    //     int n = nums.size();
    //     vector<unsigned int> dp(tar+1, 0);

    //     dp[0] = 1;

    //     for(int i = 1 ; i <= tar ; i++){
    //         for(int num : nums){
    //             if(i-num >= 0)
    //                 dp[i] += dp[i-num];
    //         }
    //     }

    //     return dp[tar];
    // }
};

int main(){
    /*
        Input: nums = [1,2,3], target = 4
        Output: 7
        Explanation:
        The possible combination ways are:
        (1, 1, 1, 1)
        (1, 1, 2)
        (1, 2, 1)
        (1, 3)
        (2, 1, 1)
        (2, 2)
        (3, 1)
    */

    return 0;
}