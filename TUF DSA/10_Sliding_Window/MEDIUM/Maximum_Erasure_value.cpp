#include<bits/stdc++.h>
using namespace std;

/*      LC = 1695
    You are given an array of positive integers nums and want to erase a subarray containing unique elements. The score you get by erasing the subarray is equal to the sum of its elements.

    Return the maximum score you can get by erasing exactly one subarray.

    An array b is called to be a subarray of a if it forms a contiguous subsequence of a, that is, if it is equal to a[l],a[l+1],...,a[r] for some (l,r).
*/

class Solution {
public:
    // TC is O(n) for "r", and the worst case scenario the inner loop will run n times, that too if the first repeating char will be at the last index, so it will be a O(n) + O(n) = O(n).
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = 0;

        vector<int> hash(1e4+1, -1);

        int sum = 0;
        int ans = 0;

        while(r < n){
            // the value at nums[r] has repeated.
            if(hash[nums[r]] != -1){
                if(hash[nums[r]] >= l){
                    while(l <= hash[nums[r]]){
                        sum -= nums[l];
                        l++;
                    }
                }
            }
            
            hash[nums[r]] = r;
            sum += nums[r];

            ans = max(ans, sum);
            r++;
        }

        return ans;
    }

                    // HIGHER COMPLEXITY.
            
    // int maximumUniqueSubarray(vector<int>& nums) {
    //     int n = nums.size();
    //     int start = 0, end = 0;
    //     int l = 0, r = 0;

    //     vector<int> hash(1e4+1, -1);
    //     int maxLen = 0;
    //     int ans = 0;

    //     while(r < n){
    //         // the value at nums[r] has repeated.
    //         if(hash[nums[r]] != -1){
    //             if(hash[nums[r]] >= l){
    //                 l = hash[nums[r]] + 1;
    //             }
    //         }
    //         hash[nums[r]] = r;
    //         int sum = 0;

    //         for(int i = l ; i <= r ; i++) sum += nums[i];

    //         ans = max(ans, sum);
    //         r++;
    //     }

    //     return ans;
    // }
    
};

int main(){
    /*
        Example 1:

        Input: nums = [4,2,4,5,6]
        Output: 17
        Explanation: The optimal subarray here is [2,4,5,6].

        
        Example 2:

        Input: nums = [5,2,1,2,5,2,1,2,5]
        Output: 8
        Explanation: The optimal subarray here is [5,2,1] or [1,2,5].
        

        Constraints:

        1 <= nums.length <= 105
        1 <= nums[i] <= 104
    */

    return 0;
}