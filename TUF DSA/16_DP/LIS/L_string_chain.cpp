#include<bits/stdc++.h>
using namespace std;

/*
    Problem Statement: Given an array of strings words[], the task is to return the longest string chain. A string chain is defined as a sequence of words where:

    Each word (except the first) can be formed by inserting exactly one character into the previous word.
    The first word of the chain can be any word from the words[] array.
    The task is to determine the length of the longest chain.
*/

bool checkPossible(string& s1, string& s2){
    if(s1.size() != s2.size()+1) return false;
    int first = 0, second = 0;

    while(first < s1.size()){     // till the ahead(bigger) string 
        if(second < s2.size() && s1[first] == s2[second]){
            first++;
            second++;
        }
        else{
            first++;
        }
    }
    if(first == s1.size() && second == s2.size()) return true;
    return false;
}

static bool comp(string& s1, string& s2){
    return s1.size() < s2.size();
}

int longestStrChain(vector<string>& arr) {
    int n = arr.size();
    sort(arr.begin(), arr.end(), comp);     // sorting (wrt size) to take as max possible elements.
    vector<int> dp(n, 1);
    int maxi = 1;
    
    for(int i = 1 ; i < n ; i++){
        for(int prev = 0 ; prev < i ; prev++){
            if(checkPossible(arr[i], arr[prev]) && 1+dp[prev] > dp[i]){
                dp[i] = 1+dp[prev];
            }
        }
        maxi = max(maxi, dp[i]);
    }
    return maxi;
}

int main(){
    vector<string> arr = {"xb", "pcxbcf", "cxbc", "pcxbc","xbc"};
    cout << "The longest string chain is : " << longestStrChain(arr);
    return 0;
}