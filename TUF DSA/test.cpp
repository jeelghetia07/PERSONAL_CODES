#include<bits/stdc++.h>
using namespace std;


int func(int ind, int ANDans, int prevVal, vector<int>& arr){
    int n = arr.size();
    if(ind == n) return 0;

    int nontake = 0 + func(ind+1, ANDans, prevVal, arr);
    int take = 0;
    if(prevVal <= arr[ind] || prevVal == -1 ){
        int newAND;
        if(ANDans == -1){
            newAND = arr[ind];
        }
        else{
            newAND = ANDans & arr[ind];
        }
        if(newAND != 0){
            take = 1 + func(ind+1, newAND, arr[ind], arr);
        }
    }
    return max(nontake, take);
}
int longestSubsequence(vector<int>& arr) {
    return func(0, -1, -1, arr);
}

int main(){
    vector<int> arr = {5,4,7};
    cout << longestSubsequence(arr);
}