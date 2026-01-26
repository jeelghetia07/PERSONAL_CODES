#include<bits/stdc++.h>
using namespace std;

int eraseOverlapping(vector<vector<int>>& arr){
    int n = arr.size();
    
    sort(arr.begin(), arr.end(), [](auto& a, auto& b){
        return a[1] < b[1];
    });

    int cnt = 1;

    int prevEND = arr[0][1];

    for(int i = 1 ; i < n ; i++){
        if(arr[i][0] >= prevEND){
            cnt++;
            prevEND = arr[i][1];
        }
    }
    return n-cnt;       // we return the values we throw away to form the non overlapping .
}

int main(){
    vector<vector<int>> intervals = {{1,2},{2,3},{3,4},{1,3}};      
    cout << "Minimum intervals to remove : " << eraseOverlapping(intervals) << endl;
    return 0;
}