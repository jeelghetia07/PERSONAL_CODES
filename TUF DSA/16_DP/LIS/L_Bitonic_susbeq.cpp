// L_Bitonic_susbeq.cpp
#include<bits/stdc++.h>
using namespace std;

/*
    Problem Statement: Given an array arr of n integers, the task is to find the length of the longest bitonic sequence. A sequence is considered bitonic if it first increases, then decreases. The sequence does not have to be contiguous.

    bitonic string means 1 10 5 4 3....increasing then decreasing....
    either it can also be increasing only and it can be decreasing only....

*/

int LongestBitonic(vector<int>& arr){
    int n = arr.size();
    vector<int> dp1(n, 1);    // initially the longest incre subseq of a particular ele will be itself...so len = 1;
    vector<int> dp2(n, 1);    
    int maxi = 1;

    for(int i = 0 ; i < n ; i++){
        for(int prev = 0 ; prev < i ; prev++){
            if(arr[prev] < arr[i] && 1 + dp1[prev] > dp1[i]){
                dp1[i] = 1 + dp1[prev];
            }
        }
    }
    
    for(int i = n-1 ; i >= 0 ; i--){
        for(int prev = n-1 ; prev > i ; prev--){
            if(arr[prev] < arr[i] && 1 + dp2[prev] > dp2[i]){
                dp2[i] = 1 + dp2[prev];
            }
        }
        maxi = max(maxi, dp1[i]+dp2[i]-1);      // here we are subtracting 1 becoz....one element will be common in both the dp arrays... so subtract it one.
    }
    return maxi;
}

int main(){
    vector<int> arr = {1, 11, 2, 10, 4, 5, 2, 1};
    cout << "The length os the Longest Bitonic string is : " << LongestBitonic(arr);
    return 0;
}