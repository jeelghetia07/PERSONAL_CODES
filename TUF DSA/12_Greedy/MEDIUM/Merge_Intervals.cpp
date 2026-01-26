#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& arr){
    vector<vector<int>> mergedIntervals;
    if(arr.size() == 0){
        return mergedIntervals;
    }

    sort(arr.begin(), arr.end());
    vector<int> tempInt = arr[0];

    for(auto it : arr){
        if(it[0] <= tempInt[1]){
            tempInt[1] = max(it[1], tempInt[1]);
        }
        else{
            mergedIntervals.push_back(tempInt);
            tempInt = it;
        }
    }
    mergedIntervals.push_back(tempInt);
    return mergedIntervals;
}

int main(){
    vector<vector<int>> arr = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> ans = merge(arr);

    for(auto it : ans){
        cout << "[ " ;
        for(auto i : it){
            cout << i << " ";
        }
        cout << "]";
    }
    return 0;
}