#include<bits/stdc++.h>
using namespace std;

void find(int ind, int tar, vector<int>& arr, vector<vector<int>>&ans, vector<int> &ds){
    if(ind == arr.size()){
        if(tar == 0){
            ans.push_back(ds);
        }
        return;
    }

    // pick up the element.
    if(arr[ind] <= tar){
        ds.push_back(arr[ind]);
        find(ind, tar-arr[ind], arr, ans, ds);
        ds.pop_back();
    }

    find(ind+1, tar, arr, ans, ds);
}

vector<vector<int>> combinationSum(vector<int>& candidates, int tar){
    vector<vector<int>> ans;
    vector<int> ds;
    find(0, tar, candidates, ans, ds);
    return ans;
}

int main(){
    vector<int> candidates = {2,3,6,7};
    int tar = 7;
    vector<vector<int>> ans = combinationSum(candidates, tar);
    for(auto it : ans){
        cout << "[";
        for(auto it1 : it){
            cout << it1 << ", ";
        }
        cout << "]";
    }
}