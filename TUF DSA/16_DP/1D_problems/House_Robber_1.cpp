#include<bits/stdc++.h>
using namespace std;

// int func(int ind, vector<int> &arr){
//     if(ind == 0) return arr[ind];
//     if(ind < 0) return 0;
//     int pick = arr[ind] + func(ind-2, arr);
//     int nonpick = 0 + func(ind-1, arr);
//     return max(pick, nonpick);
// }

// int func(int ind, vector<int> &nums, vector<int> &dp){       // MEMOIZATION    SC = O(n) + O(n).
//     if(ind == 0) return nums[ind];     // if we reach 0..that means we have reached ind-2....so by default...we have to take the element.
//     if(ind < 0) return 0;
//     if(dp[ind] != -1) return dp[ind];
//     int pick = nums[ind] + func(ind-2, nums, dp);    // becoz we cannot pick the adjecent element....so ind -> ind-2.
//     int notpick = 0 + func(ind-1, nums, dp);
//     return dp[ind] = max(pick, notpick);       // initialize the dp[index]...so that we dont perform nextime.
// }



// int func(vector<int> &nums, vector<int> &dp, int n){       //TABULATION (Bottom Up)....this reduces the SC to O(n).
//     dp[0] = nums[0];

//     for(int i = 1 ; i < n ; i++){
//         int take = nums[i];
//         if(i > 1) take += dp[i-2];     // if the i == 1...then it becomes invalid.
//         int nontake = 0 + dp[i-1];
//         dp[i] = max(take, nontake);
//     }
//     return dp[n-1];
// }


int func(vector<int> &nums, vector<int> &dp, int n){     // this is now space optimized.....O(1).
    int prev = nums[0];
    int prev2 = 0;
    int curri;

    for(int i = 1 ; i < n ; i++){
        int take = nums[i];
        if(i > 1) take += prev2;
        int nontake = 0 + prev;
        curri = max(take, nontake);
        prev2 = prev;
        prev = curri;
    }
    return prev;
}


int MaxNonAdjecentSum(vector<int> &nums){
    int n = nums.size();
    vector<int> dp(n,-1);
    // return func(n-1,nums,dp);
    return func(nums,dp,n);
}

int main(){
    vector<int> nums = {2,1,4,9};
    int sum = MaxNonAdjecentSum(nums);
    cout << "The max sum is : " << sum;
    return 0;
}