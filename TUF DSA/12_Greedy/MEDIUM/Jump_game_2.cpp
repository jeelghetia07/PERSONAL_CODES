#include<bits/stdc++.h>
using namespace std;

// PROBLEM : You are given a 0-indexed array of integers nums of length n. You are initially positioned at index 0.Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at index i, you can jump to any index (i + j) where:   0 <= j <= nums[i] and i + j < n . Return the minimum number of jumps to reach index n - 1. The test cases are generated such that you can reach index n - 1.

// int minJUMPS(int ind, int jumps, vector<int>& arr){
//     int n = arr.size();
//     int mini = INT_MAX;
//     if(ind >= n-1) return jumps;
//     for(int i = 1 ; i <= arr[ind] ; i++){
//         mini = min(mini, minJUMPS(ind+i, jumps+1, arr));
//     }
//     return mini;
// }

int jump(vector<int>& arr){
    int n = arr.size(); 
    int jumps = 0, l = 0, r = 0;

    while(r < n-1){
        int farthest = 0;
        for(int i = l ; i <= r ; i++){
            farthest = max(farthest, i+arr[i]);
        }
        l = r+1;
        r = farthest;
        jumps++;
    }
    return jumps;
}

int main(){
    vector<int> arr = {2,3,1,1,4};
    // cout << "The minimum steps to reach end are : " << minJUMPS(0,0,arr);
    cout << "The minimum steps to reach end are : " << jump(arr);
    return 0;
}