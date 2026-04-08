#include<bits/stdc++.h>
using namespace std;

/*      GFG (Very Hard Que)
    Given a fence with n posts and k colours, find out the number of ways of painting the fence so that not more than two consecutive posts have the same colours.
    Answers are guaranteed to be fit into a 32 bit integer.
*/

class Solution {
  public:
    int func(int ind, int state, int n, int k, vector<vector<int>>& dp){
        if(ind == n) return 1;        // if we have filled all posts.
        
        if(dp[ind][state] != -1) return dp[ind][state];
        
        if(state == 1){     // if the last 2 posts are same coloured.
            return dp[ind][state] = (k-1) * func(ind+1, 0, n, k, dp);
        }
        else{       // last 2 posts have diff colours.
            return dp[ind][state] = (1 * func(ind+1, 1, n, k, dp)) + ((k-1) * func(ind+1, 0, n, k, dp));
        }
    }
    int countWays(int n, int k) {
        if(n == 1) return k;        // if we have only one post, we can colour in all k ways.
        
        vector<vector<int>> dp(n, vector<int>(2, -1));
        
        int same = k;   // for any k to make the 2 posts same, we have k choices, .... k = 3, RR / BB / GG.
        int diff = k * (k-1);       // do a dry run of k = 3, ab/ba/bc/cb/ac/ca.
        
        int ans = same * func(2, 1, n, k, dp)
                + diff * func(2, 0, n, k, dp);
                
        return ans;
    }
};

int main(){
    /*
        Input: n = 3, k = 2 
        Output: 6
        Explanation: Let the 2 colours be 'R' and 'B'. We have following possible combinations:
            1. RRB
            2. RBR
            3. RBB
            4. BRR
            5. BRB
            6. BBR


        Input: n = 2, k = 4 
        Output: 16
        Explanation: After coloring first post with 4 possible combinations, you can still color next posts with all 4 colors. Total possible combinations will be 4x4=16
    */

    return 0;
}