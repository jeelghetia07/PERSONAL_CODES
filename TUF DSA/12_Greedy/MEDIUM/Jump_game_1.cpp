#include<bits/stdc++.h>
using namespace std;

// PROBLEM : Given an array where each element represents the maximum number of steps you can jump forward from that element, return true if we can reach the last index starting from the first index. Otherwise, return false.

bool findOut(vector<int>& arr){
    int n = arr.size();
    int maxInd = 0;

    for(int i = 0 ; i < n ; i++){
        if(i > maxInd) return false;
        maxInd = max(maxInd, i+arr[i]);
    }
    return true;
}

int main(){
    vector<int> arr = {1,2,3,1,1,0,2,5};
    if(findOut(arr)) cout << "Yes we can reach at last.";
    else cout << "its impossible.";
    return 0;
}