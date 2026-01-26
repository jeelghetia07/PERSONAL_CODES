#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> func(vector<vector<int>>& arr, vector<int>& newInt){
    vector<vector<int>> ans; 
    int i = 0, n = arr.size();

    while(i < n && arr[i][1] < newInt[0]){
        ans.push_back(arr[i]);
        i++;
    }
    while(i < n && arr[i][0] <= newInt[1]){
        newInt[0] = min(newInt[0], arr[i][0]);
        newInt[1] = max(newInt[1], arr[i][1]);
        i++;
    }
    ans.push_back(newInt);
    while(i < n){
        ans.push_back(arr[i]);
        i++;
    }
    return ans;
}

int main(){
    vector<vector<int>> arr = {{1,3},{6,9}};
    vector<int> newInt = {2,5};

    vector<vector<int>> ans = func(arr, newInt);
    
    for(int i = 0 ; i < ans.size() ; i++){
        cout << "[";
        for(int j = 0 ; j < ans[0].size() ; j++){
            cout << ans[i][j];
        }
        cout << "]";
    }
    return 0;
}