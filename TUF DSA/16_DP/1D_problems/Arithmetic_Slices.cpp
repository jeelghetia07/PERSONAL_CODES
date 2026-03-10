#include<bits/stdc++.h>
using namespace std;

/*      LC = 413
    An integer array is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.

    For example, [1,3,5,7,9], [7,7,7,7], and [3,-1,-5,-9] are arithmetic sequences.
    Given an integer array nums, return the number of arithmetic subarrays of nums.

    A subarray is a contiguous subsequence of the array.
*/


            // MEMOIZATION

// int func(int ind, vector<int>& a, vector<int>& dp){
//     if(ind < 2) return 0;

//     if(dp[ind] != -1) return dp[ind];

//     if(a[ind]-a[ind-1] == a[ind-1]-a[ind-2]){
//         return dp[ind] = func(ind-1, a, dp) + 1;
//     }
//     else{
//         return dp[ind] = 0;
//     }
// }
// int numberOfArithmeticSlices(vector<int>& nums) {
//     int n = nums.size();
//     int total = 0;

//     vector<int> dp(n,-1);

//     for(int i = 2 ; i < n ; i++){
//         total += func(i, nums, dp);
//     }

//     return total;
// }



                // TABULATION

// int numberOfArithmeticSlices(vector<int>& nums) {
//     int n = nums.size();
//     int total = 0;

//     vector<int> dp(n, 0);

//     for(int ind = 2 ; ind < n ; ind++){
//         if(nums[ind]-nums[ind-1] == nums[ind-1]-nums[ind-2]){
//             dp[ind] = dp[ind-1] + 1;
//         }
//         else{
//             dp[ind] = 0;
//         }
//         total += dp[ind];
//     }

//     return total;
// }




                // Space optimized


int numberOfArithmeticSlices(vector<int>& nums) {
    int n = nums.size();
    int total = 0, prev = 0, curr = 0;

    for(int ind = 2 ; ind < n ; ind++){
        if(nums[ind]-nums[ind-1] == nums[ind-1]-nums[ind-2]){
            curr = prev + 1;
        }
        else{
            curr = 0;
        }
        total += curr;
        prev = curr;
    }

    return total;
}

int main(){
    vector<int> nums = {1,2,3,4,5};     // ans is 6.....[123, 234, 345, 1234, 2345, 12345].
    int ans = numberOfArithmeticSlices(nums);

    return 0;
}