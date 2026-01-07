#include<bits/stdc++.h>
using namespace std;

int func(vector<int> &arr){         // optimized code from house robber 1
    int prev = arr[0];
    int prev2 = 0;
    int curri;
    int n = arr.size();
    
    for(int i = 1 ; i < n ; i++){
        int take = arr[i];
        if(i > 1) take += prev2;
        int nontake = 0 + prev;
        curri = max(take, nontake);
        prev2 = prev;
        prev = curri;
    }
    return prev;
}
int rob(vector<int>& nums) {
    int n = nums.size();
    if(n == 1) return nums[0];
    vector<int> temp1, temp2;
    for(int i = 0 ; i < n ; i++){
        if(i != 0) temp1.push_back(nums[i]);
        if(i != n-1) temp2.push_back(nums[i]);
    }
    return max(func(temp1), func(temp2));
}

int main(){
    vector<int> nums = {3,1,8,7,6};
    int sum = rob(nums);
    cout << "The max sum is : " << sum;
    return 0;
}