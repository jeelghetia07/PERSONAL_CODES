#include<bits/stdc++.h>
using namespace std;

/*      LC = 3702
    You are given an integer array nums.

    Return the length of the longest subsequence in nums whose bitwise XOR is non-zero. If no such subsequence exists, return 0.
*/

class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();

        // for the case where all the array elements are 0.
        bool hasNonZero = false;
        for(int x : nums){
            if(x != 0) hasNonZero = true;
        }

        int total = 0;
        for(int i = 0 ; i < n ; i++){
            total ^= nums[i];
        }

        if(total == 0 && !hasNonZero) return 0;
        
        if(total == 0) return n-1;
        else if(total > 0) return n;
        return 0;
    }
};

int main(){
    /*
        Example 1:

        Input: nums = [1,2,3]
        Output: 2
        Explanation:
        One longest subsequence is [2, 3]. The bitwise XOR is computed as 2 XOR 3 = 1, which is non-zero.


        Example 2:
        Input: nums = [2,3,4]
        Output: 3
        Explanation:
        The longest subsequence is [2, 3, 4]. The bitwise XOR is computed as 2 XOR 3 XOR 4 = 5, which is non-zero.

        Constraints:

        1 <= nums.length <= 105
        0 <= nums[i] <= 109
    */

    return 0;
}