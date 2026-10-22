#include<bits/stdc++.h>
using namespace std;

/*      LC = 3942
    You are given an integer array nums of length n, where nums is a permutation of the integers from 0 to n - 1.

    You may perform only the following operations:

    Reverse the entire array.
    Rotate Left by One: Move the first element to the end of the array, and rest elements to left by one position.
    Return an integer denoting the minimum number of operations required to sort the array in increasing order. If it is not possible to sort the array using only the given operations, return -1.
*/

class Solution {
public:
    int solve(vector<int>& nums){
        int n = nums.size();

        // creating a concatenated array, having a copy of itself beside.
        vector<int> vec = nums;
        for(int i : nums){
            vec.push_back(i);
        }

        int v = vec.size();

        int cnt = 1;
        
        // increasing sorted check
        for(int i = 1 ; i < v ; i++){
            if(vec[i] > vec[i-1]){
                cnt++;

                if(cnt == n){
                    return i+1-n;
                }
            }
            else{ 
                cnt = 1;
            }
        }

        cnt = 1;

        // decreasing sorted check
        for(int i = 1 ; i < v ; i++){
            if(vec[i] < vec[i-1]){
                cnt++;

                if(cnt == n){
                    return i+2-n;
                }
            }
            else{ 
                cnt = 1;
            }
        }

        return 1e9;
    }
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return 0;

        int ans = solve(nums);

        reverse(nums.begin(), nums.end());
        ans = min(ans, solve(nums)+1);
    
        return ans == 1e9 ? -1 : ans;
    }
};

int main(){
    /*
        Example 1:

        Input: nums = [0,2,1]

        Output: 2

        Explanation:

        Rotate Left by one: [2, 1, 0]
        Reverse the array: [0, 1, 2]
        The array becomes sorted in 2 operations, which is minimal

        Example 2:

        Input: nums = [1,0,2]

        Output: 2

        Explanation:

        Reverse the array: [2, 0, 1]
        Rotate Left by one: [0, 1, 2]
        The array becomes sorted in 2 operations, which is minimal.

        Example 3:

        Input: nums = [2,0,1,3]

        Output: -1

        Explanation:

        It is impossible to reach [2, 0, 1, 3]. Thus, the answer is -1.

        

        Constraints:

        1 <= n == nums.length <= 105
        0 <= nums[i] <= n - 1
        nums is a permutation of integers from 0 to n - 1.
    */

    return 0;
}