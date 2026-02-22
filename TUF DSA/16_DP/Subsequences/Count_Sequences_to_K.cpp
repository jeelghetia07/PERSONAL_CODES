#include<bits/stdc++.h>
using namespace std;

int func(int ind, long long num, long long den, long long k, vector<int>& nums){
    if(ind < 0){
        if(num == k*den) return 1;
        else return 0;
    }  
    return (func(ind-1, num*nums[ind], den, k, nums) + func(ind-1, num, den*nums[ind], k, nums) + func(ind-1, num, den, k, nums));
}
int countSequences(vector<int>& nums, long long k) {
    int n = nums.size();
    int num = 1, den = 1;
    // vector<vector<vector<int>>> dp(n, vec)
    return func(n-1, num, den, k, nums);
}

int main(){
    // vector<int> nums = {2,3,2};
    // int k = 6;
    // vector<int> nums = {1,5};
    // int k = 1;
    vector<int> nums = {4,6,3};
    int k = 2;

    cout << countSequences(nums,k);
    return 0;
}