#include<bits/stdc++.h>
using namespace std;

/*      LC = 40
    Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

    Each number in candidates may only be used once in the combination.

    Note: The solution set must not contain duplicate combinations.
*/

class Solution {
public:
    void func(int ind, int tar, vector<int>& temp, vector<int>& arr, vector<vector<int>>& ans){
        if(tar == 0){
            ans.push_back(temp);
            return;
        }

        for(int i = ind ; i < arr.size() ; i++){
            if(i > ind && arr[i] == arr[i-1]) continue;
            if(arr[i] > tar) break;
            temp.push_back(arr[i]);
            func(i+1, tar-arr[i], temp, arr, ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target){
        int n = candidates.size();
        sort(candidates.begin(), candidates.end());

        vector<int>temp;
        vector<vector<int>> ans;

        func(0, target, temp, candidates, ans);
        return ans;
    }


    // void func(int ind, vector<int>& temp, int tar, vector<int>& arr, set<vector<int>>& ans){
    //     if(ind == arr.size()){
    //         if(tar == 0) ans.insert(temp);
    //         return;
    //     }

    //     if(arr[ind] <= tar){
    //         temp.push_back(arr[ind]);
    //         func(ind+1, temp, tar-arr[ind], arr, ans);
    //         temp.pop_back();
    //     }
    //     func(ind+1, temp, tar, arr, ans);
    // }

    // vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // int n = candidates.size();
        // sort(candidates.begin(), candidates.end());\

        // vector<int>temp;
        // set<vector<int>> ans;

        // func(0, temp, target, candidates, ans);
        // vector<vector<int>> res;
        // for(auto it : ans){
        //     res.push_back(it);
        // }
        // return res;
    // }
};

int main(){
    vector<int> candidates = {10,1,2,7,6,1,5};
    int target = 8;

    Solution obj;
    vector<vector<int>> ans = obj.combinationSum2(candidates, target);

    return 0;
}