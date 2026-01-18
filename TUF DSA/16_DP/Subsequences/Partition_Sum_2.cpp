// THIS IS TUF THAN THE SIMPLE VERISON.
#include<bits/stdc++.h>
using namespace std;

// Problem Description: Given an array of n integers, partition the array into two subsets such that the absolute difference between their sums is minimized.

int minimumDifference(vector<int>& nums) {
    int n = nums.size();
    int totSum = 0;
    for(int i = 0 ; i < n ; i++){
        totSum += nums[i];
    }

    int target = totSum;

    // vector<vector<bool>> dp(n, vector<bool>(target+1, 0));     // initialized the matrix with false;
    vector<bool> prev(target+1, 0), curr(target+1, 0);
    prev[0] = curr[0] = true;
    if(nums[0] <= target) prev[nums[0]] = true;

    for(int ind = 1 ; ind < n ; ind++){
        for(int tar = 1 ; tar <= target ; tar++){
            bool nontake = prev[tar];
            bool take = false;
            if(nums[ind] <= tar) take = prev[tar-nums[ind]];
            curr[tar] = take | nontake;
        }
        prev = curr;
    }

    int mini = 1e9;
    for(int tar = 0 ; tar <= target/2 ; tar++){        // no need for the full target...becoz at the middle point the order will start to be reversed....s1 = 0, s2 = 12...then s1 = 12, s2 = 0.....thats why.
        if(prev[tar] == true){
            int s1 = tar;
            int s2 = target - tar;
            mini = min(mini, abs(s1-s2));
        }
    }
    return mini;
}

int main(){
    vector<int> arr = {3,2,7};
    int n = arr.size();

    int ans = minimumDifference(arr);
    cout << "The min diff is : " << ans  << endl;
    return 0;
}