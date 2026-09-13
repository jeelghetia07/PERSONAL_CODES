#include<bits/stdc++.h>
using namespace std;

/*      LC = 96
    Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes of unique values from 1 to n.
*/

    /*
        The idea of this is :
            The intuition is: for every possible BST, we can choose one node as the root. Once the root is fixed, all smaller values must go into the left subtree and all larger values into the right subtree. So, if the root leaves "L" nodes on the left and "R" nodes on the right, the number of BSTs for that root is "solve(L) × solve(R)", because every possible left subtree can be combined with every possible right subtree. We try every possible root and add these combinations together. Thus, the problem reduces to recursively finding the number of BSTs possible with smaller numbers of nodes.
    */

class Solution {
public:
    int numTrees(int n){
        vector<int> dp(n+1, 0);
        dp[0] = 1, dp[1] = 1;

        // the upper loop and tries that all the nodes become roots for once.
        for(int i = 2 ; i <= n; i++){
            // this tries that it seperates inner subtrees. ( the other for loop wrote in the memoized sol ).
            for(int j = 1 ; j <= i ; j++){
                dp[i] += dp[j-1] * dp[i-j];
            }
        }

        return dp[n];
    }





    // // number of structurally unique BST that can be made using n nodes.
    // int func(int n, vector<int>& dp){
    //     if(n <= 1) return 1;

    //     if(dp[n] != -1) return dp[n];

    //     int ans = 0;

    //     for(int root = 1 ; root <= n ; root++){
    //         int trees_formed_on_leftside = func(root-1, dp);
    //         int trees_formed_on_rightside = func(n-root, dp);

    //         ans += (trees_formed_on_leftside * trees_formed_on_rightside);          // this is that each combination of left will attach the right part, try doing it with n = 3, and u will understand properly.
    //     }

    //     return dp[n] = ans;
    // }
    // int numTrees(int n) {
    //     vector<int> dp(n+1, -1);

    //     return func(n, dp);
    // }
};

int main(){
    /*
        Example 1:
            Input: n = 3
            Output: 5

        Example 2:
            Input: n = 1
            Output: 1

        Constraints:
            1 <= n <= 19

    */

    return 0;
}