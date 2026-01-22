#include<bits/stdc++.h>
using namespace std;

int func(vector<int> &arr){
    sort(arr.begin(), arr.end());
    int t = 0, wt = 0;
    for(int i = 0 ; i < arr.size() ; i++){
        wt += t;
        t += arr[i];
    }
    return (wt/ arr.size());
}

int main(){
    vector<int> arr = {4,3,7,1,2};
    cout << "The avg time for CPU scheduling is : " << func(arr);
    return 0;
}