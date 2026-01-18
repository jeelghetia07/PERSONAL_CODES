#include<bits/stdc++.h>
using namespace std;

// constriants :-  0 <= nums[i] <= 1000.

int f(int ind, int tar, vector<int>& arr, vector<vector<int>>& dp){
    if(ind == 0){
        if(tar == 0 && arr[ind] == 0)  return 2;   // this is becoz....if the ele is 0 and sum to be achieved is also 0...then we have 2 options...pick and non pick...so return 2;
        else if(tar == 0 || arr[ind] == tar) return 1;     // if arr[ind] = 5..and sum = 5...then only 1 choice..take...
        return 0;
    }

    if(dp[ind][tar] != -1) return dp[ind][tar];

    int nonpick = f(ind-1, tar, arr, dp);
    int pick = 0;
    if(tar >= arr[ind]) pick = f(ind-1, tar-arr[ind], arr, dp);

    return dp[ind][tar] = pick + nonpick;
}

int CountSubsets(vector<int>& arr, int n, int tar){
    vector<vector<int>> dp(n, vector<int>(tar+1, -1));   // dp of the same size.
    return f(n-1, tar, arr, dp);
}

int main(){
    vector<int> arr = {0,0,1};
    int n = arr.size();
    int tar = 1;

    cout << "The count is : " << CountSubsets(arr,n,tar);   // {0,1}, {0,1}, {0,0,1}, {1};
    return 0;
}