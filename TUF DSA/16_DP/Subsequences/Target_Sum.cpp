#include<bits/stdc++.h>
using namespace std;

// PROBLEM :
/*  
    You are given an integer array nums and an integer target.
    You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

    For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
    Return the number of different expressions that you can build, which evaluates to target.

    1 <= nums.length <= 20
    0 <= nums[i] <= 1000
    0 <= sum(nums[i]) <= 1000
    -1000 <= target <= 1000
*/

int FindWays(vector<int>& arr, int n, int k){
    vector<vector<int>> dp(n, vector<int>(k+1, 0));
    if(arr[0] == 0) dp[0][0] = 2;
    else dp[0][0] = 1;
    if(arr[0] != 0 && k >= arr[0]) dp[0][arr[0]] = 1;

    for(int ind = 1 ; ind < n ; ind++){
        for(int tar = 0 ; tar <= k ; tar++){
            int nonpick = dp[ind-1][tar];
            int pick = 0;
            if(tar >= arr[ind]) pick = dp[ind-1][tar-arr[ind]];
            dp[ind][tar] = pick + nonpick;
        }
    }
    return dp[n-1][k];
}

int countPartitions(int n, int d, vector<int>& arr){
    int totSum = 0;
    for(int i = 0 ; i < n ; i++){
        totSum += arr[i];
    }

    if((totSum-d) < 0 || (totSum-d) % 2 != 0) return false;
    return FindWays(arr, n, (totSum-d)/2);
}

int main(){
    vector<int> arr = {1,2,3,1};
    int n = arr.size();
    int d = 3;

    cout << "The no is : " << countPartitions(n,d, arr);
    return 0;
}