#include<bits/stdc++.h>
using namespace std;

/*      LC = 1004
    Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's
*/

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {     // the question can be changed to, maxLen subarray containing atmost k zeros.
        int n = nums.size();

        int l = 0, r = 0;
        int maxLen = 0;
        int zeros = 0;

        while(r < n){
            if(nums[r] == 0) zeros++;

            while(zeros > k){       // if there are more than k zeros, plz reduce till one zero and maintain len.
                if(nums[l] == 0) zeros--;
                l++;
            }
            maxLen = max(maxLen, r-l+1);
            r++;
        }
        return maxLen;
    }
};

int main(){
    /*
        Example 1:

        Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
        Output: 6
        Explanation: [1,1,1,0,0,1,1,1,1,1,1]
        Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.


        Example 2:

        Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
        Output: 10
        Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
        Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
    */

    return 0;
}