#include<bits/stdc++.h>
using namespace std;

/*      LC = 930
    Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.

    A subarray is a contiguous part of the array.
*/

class Solution {
public:
    int func(vector<int>& arr, int goal, int n){
        if(goal < 0) return 0;

        int l = 0, cnt = 0, sum = 0;

        for(int r = 0 ; r < n ;r++){
            sum += arr[r];
            while(sum > goal){      // if the sum is grater then only pull left. otherwise keep moving right.
                sum -= arr[l];
                l++;
            }
            cnt += (r-l+1);     //the subsets will be the length of the subarray cause the individual ele is also a subarray.
        }

        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        /* The goal here is to find all the subsets which are <= goal for a func 
            hence here for (<= 2) - (<= 1) = (== 2). MATHEMATICS.
            for example 1 :- (14)-(10) = 4;
        */
        return func(nums, goal, n) - func(nums, goal-1, n);
    }
};

int main(){
    /*
        Example 1:

        Input: nums = [1,0,1,0,1], goal = 2
        Output: 4
        Explanation: The 4 subarrays are bolded and underlined below:
        [1,0,1,0,1]
        [1,0,1,0,1]
        [1,0,1,0,1]
        [1,0,1,0,1]
        Example 2:

        Input: nums = [0,0,0,0,0], goal = 0
        Output: 15
    */

    return 0;
}