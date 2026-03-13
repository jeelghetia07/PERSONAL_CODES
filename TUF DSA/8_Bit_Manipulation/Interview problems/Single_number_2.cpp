#include<bits/stdc++.h>
using namespace std;

/*      LC = 137
    Given an integer array nums where every element appears three times except for one, which appears exactly once. Find the single element and return it.

    You must implement a solution with a linear runtime complexity and use only constant extra space.
*/

int singleNumber(vector<int>& nums) {
    int n = nums.size();

    int ones = 0, twos = 0;

    for(int i = 0 ; i < n ; i++){
        ones = (ones ^ nums[i]) & ~(twos);
        twos = (twos ^ nums[i]) & ~(ones);
    }

    return ones;


    // sort(nums.begin(), nums.end());    //O(nlogn)

    // for(int i = 1 ; i < n ; i += 3){
    //     if(nums[i] != nums[i-1]) return nums[i-1];
    // }
    // return nums[n-1];
}

int main(){
    

    return 0;
}