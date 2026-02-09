// Partition_Array_MaxSum.cpp
#include<bits/stdc++.h>
using namespace std;


            // MEMOIZATION APPROACH....TC = O(n2)...SC = O(n)+O(N);

// int func(int ind, vector<int>& arr, int k, vector<int>& dp){
//     int n = arr.size();
//     if(ind == n) return 0;
//     if(dp[ind] != -1) return dp[ind];
//     int len = 0, maxi = INT_MIN, maxAns = INT_MIN;

//     for(int j = ind ;j < min(ind+k, n) ; j++){
//         len++;
//         maxi = max(maxi, arr[j]);
//         int sum = (len*maxi) + func(j+1, arr, k);
//         maxAns = max(maxAns, sum);
//     }
//     return dp[ind] = maxAns;
// }

// int maximumSubarray(vector<int>& arr, int k){
//     int n = arr.size();
//     vector<int> dp(n, -1);
//     return func(0, arr, k, dp);
// }




             // TABULATION APPROACH

int maximumSubarray(vector<int>& arr, int k){
    int n = arr.size();
    vector<int> dp(n+1, 0);

    for(int ind = n-1 ; ind >= 0 ; ind--){
        int len = 0, maxi = INT_MIN, maxAns = INT_MIN;
        for(int j = ind ;j < min(ind+k, n) ; j++){
            len++;
            maxi = max(maxi, arr[j]);
            int sum = (len*maxi) + dp[j+1];
            maxAns = max(maxAns, sum);
        }
        dp[ind] = maxAns;
    }
    return dp[0];
}

int main(){
    vector<int> arr = {1, 15, 7, 9, 2, 5, 10};
    int k = 3;

    cout << "The max ans is : " << maximumSubarray(arr, k);

    return 0;
}