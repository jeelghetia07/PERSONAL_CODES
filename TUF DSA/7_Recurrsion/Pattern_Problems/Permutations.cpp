#include<bits/stdc++.h>
using namespace std;

/*      LC = 46
    Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.
*/

class Solution {
public:
    void func(vector<int>& ds, vector<vector<int>>& ans, vector<int>& nums, vector<int>& freq){
        if(ds.size() == nums.size()){
            ans.push_back(ds);
            return ;
        }

        for(int i = 0 ; i < nums.size() ; i++){
            if(!freq[i]){
                ds.push_back(nums[i]);
                freq[i] = 1;
                func(ds, ans, nums, freq);
                freq[i] = 0;
                ds.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> ans;
        vector<int> ds, freq(n, 0);

        func(ds, ans, nums, freq);
        
        return ans;
    }
};

/*  The TC = O(n! * n*log(n!)) = O(n! * n2 * log(n)).
        here, n! is for generating all possiblities, n is comparing 2 arrays WC scenario in the set, log(n!)  for that WC all vector in set will be diff.

    SC = O(n * n!). cause n for vector ds, and n! for all the combination stored inside the set.
*/

int main(){
    vector<int> nums = {1,2,3};
    // Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
    Solution obj;

    vector<vector<int>> ans = obj.permute(nums);

    return 0;
}