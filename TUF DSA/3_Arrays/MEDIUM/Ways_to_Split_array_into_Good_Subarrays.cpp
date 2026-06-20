#include<bits/stdc++.h>
using namespace std;

/*      LC = 2750
    You are given a binary array nums.

    A subarray of an array is good if it contains exactly one element with the value 1.

    Return an integer denoting the number of ways to split the array nums into good subarrays. As the number may be too large, return it modulo 109 + 7.

    A subarray is a contiguous non-empty sequence of elements within an array.
*/

class Solution {
public:
    const int mod = 1e9+7;
    int numberOfGoodSubarraySplits(vector<int>& nums) {     // we just have to see the zeros between 2 ones and cut them.
        int n = nums.size();

        long long l = 0, r = 0, ans = 1, cnt = 0;
        while(r < n && nums[r] == 0) ++r;       // skiping all prior 0s
        if(r >= n) return 0;        // if array contains only 0s then return 0;

        long long prevPos = r, currPos = r+1;       // now here we placed the 1st pointer and 1st 1, and second now to move ahead.

        while(currPos < n){
            if(nums[currPos] == 0) currPos++;   
            else{           // if found another 1.
                ans = (ans * (currPos-prevPos)) % mod;      // find the ways.
                prevPos = currPos;          // change the pointer
                currPos++;
            }
        }

        return ans;
    }
};

int main(){
    /*
        Example 1:

        Input: nums = [0,1,0,0,1]
        Output: 3
        Explanation: There are 3 ways to split nums into good subarrays:
        - [0,1] [0,0,1]
        - [0,1,0] [0,1]
        - [0,1,0,0] [1]


        Example 2:

        Input: nums = [0,1,0]
        Output: 1
        Explanation: There is 1 way to split nums into good subarrays:
        - [0,1,0]
 
    */

    return 0;
}