#include<bits/stdc++.h>
using namespace std;

/*      LC = 216
    Find all valid combinations of k numbers that sum up to n such that the following conditions are true:

    Only numbers 1 through 9 are used.
    Each number is used at most once.
    Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.
*/

class Solution {
public:
    void func(int ind, int tar, int len, vector<int>& temp, set<vector<int>>& st, vector<int>& arr, int n){
        if(ind > n) return;
        if(tar == 0 && len == 0){
            st.insert(temp);
            return;
        }
        else if(tar == 0 && len != 0) return;
        else if(tar != 0 && len == 0) return;

        for(int i = ind ; i < n ; i++){
            if(arr[i] > tar) break;

            temp.push_back(arr[i]);
            func(i+1, tar-arr[i], len-1, temp, st, arr, n);
            temp.pop_back();
        }
        func(ind+1, tar, len, temp, st, arr, n);
    }
    vector<vector<int>> combinationSum3(int k, int target) {
        vector<int> arr = {1,2,3,4,5,6,7,8,9};
        int n = arr.size();

        set<vector<int>> st;
        vector<int> temp;

        func(0, target, k, temp, st, arr, n);

        vector<vector<int>> res;
        for(auto &it : st){
            res.push_back(it);
        }
        return res;
    }
};

int main(){
    Solution obj;

    vector<vector<int>> ans1 = obj.combinationSum3(3, 9);   // [[1,2,6],[1,3,5],[2,3,4]]
    vector<vector<int>> ans2 = obj.combinationSum3(9, 45);     // [[1,2,3,4,5,6,7,8,9]]

    return 0;
}