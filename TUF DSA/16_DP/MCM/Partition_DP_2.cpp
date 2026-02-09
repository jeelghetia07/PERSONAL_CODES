// Partition_DP_2.cpp
#include<bits/stdc++.h>
using namespace std;

/*
    Problem Description: Given a string s, partition s such that every substring of the partition is a palindrome. Return the minimum cuts needed for a palindrome partitioning of s.
*/


                // MEMOIZATION APPROACH

// bool isPalindrome(int i, int j, string &s){
//     while(i < j){
//         if(s[i] != s[j]){
//             return false;
//         }
//         i++;
//         j--;
//     }
//     return true;
// }
// int func(int i, int n, string& s, vector<int>& dp){
//     if(i == n) return 0;
//     if(dp[i] != -1) return dp[i];
//     string temp = "";
//     int MinCost = INT_MAX;
//     for(int j = i ; j < n ; j++){
//         temp += s[j];
//         if(isPalindrome(i, j, s)){
//             int cost = 1 + func(j+1, n, s, dp);
//             MinCost = min(MinCost, cost);
//         }
//     }
//     return dp[i] = MinCost;
// }
// int minCut(string s) {
//     int n = s.size();
//     vector<int> dp(n, -1);
//     return func(0, n, s, dp)-1;
// }



                // TABULATION

bool isPalindrome(int i, int j, string &s){
    while(i < j){
        if(s[i] != s[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int minCut(string s) {
    int n = s.size();
    vector<int> dp(n+1, 0);

    dp[n] = 0;

    for(int i = n-1 ; i >= 0 ; i--){
        string temp = "";
        int MinCost = INT_MAX;
        for(int j = i ; j < n ; j++){
            temp += s[j];
            if(isPalindrome(i, j, s)){
                int cost = 1 + dp[j+1];
                MinCost = min(MinCost, cost);
            }
        }
        dp[i] = MinCost;
    }
    return dp[0]-1;
}

int main(){
    string s = "abbadef";
    cout << "The mini partitions to make all substrings palidrome : " << minCut(s);

    return 0;
}