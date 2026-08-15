#include<bits/stdc++.h>
using namespace std;

/*      LC = 1140
    Alice and Bob continue their games with piles of stones. There are a number of piles arranged in a row, and each pile has a positive integer number of stones piles[i]. The objective of the game is to end with the most stones.

    Alice and Bob take turns, with Alice starting first.

    On each player's turn, that player can take all the stones in the first X remaining piles, where 1 <= X <= 2M. Then, we set M = max(M, X). Initially, M = 1.

    The game continues until all the stones have been taken.

    Assuming Alice and Bob play optimally, return the maximum number of stones Alice can get.
*/

class Solution {
public:
    int func(int ind, int m, vector<int>& suff, vector<vector<int>>& dp){
        if(ind >= suff.size()) return 0;

        // this means, i can reach till the last index and even further, so i can take it all, so just return the suffix.
        if(2*m >= suff.size()-ind){
            return suff[ind];
        }

        if(dp[ind][m] != -1) return dp[ind][m];

        int ans = 0;
        for(int x = 1 ; x <= min(2*m, (int)suff.size()) ; x++){
            ans = max(ans, suff[ind] - func(ind+x, max(x, m), suff, dp));
        }

        return dp[ind][m] = ans;
    }
    int stoneGameII(vector<int>& arr) {
        int n = arr.size();

        int m = 1;
        vector<int> suffix(n);
        suffix[n-1] = arr[n-1];
        for(int i = n-2 ; i >= 0 ; i--){
            suffix[i] = suffix[i+1] + arr[i];
        }

        vector<vector<int>> dp(n+1, vector<int>(100, -1));

        return func(0, 1, suffix, dp);
    }
};

int main(){
    /*
        Example 1:
        Input: piles = [2,7,9,4,4]
        Output: 10
        Explanation:

        If Alice takes one pile at the beginning, Bob takes two piles, then Alice takes 2 piles again. Alice can get 2 + 4 + 4 = 10 stones in total.
        If Alice takes two piles at the beginning, then Bob can take all three piles left. In this case, Alice get 2 + 7 = 9 stones in total.
        So we return 10 since it's larger.


        Example 2:
        Input: piles = [1,2,3,4,5,100]
        Output: 104
        

        Constraints:

        1 <= piles.length <= 100
        1 <= piles[i] <= 104
    */

    return 0;
}