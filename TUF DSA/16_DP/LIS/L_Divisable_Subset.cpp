#include<bits/stdc++.h>
using namespace std;

vector<int> LongDivisableSubset(vector<int>& arr){
    int n = arr.size();
    vector<int> dp(n, 1), hash(n);    // initially the longest incre subseq of a particular ele will be itself...so len = 1;
    int maxi = 1;
    int lastIndex = 0;
    sort(arr.begin(), arr.end());

    for(int i = 0 ; i < n ; i++){
        hash[i] = i;      // at start store the index itself.
        for(int prev = 0 ; prev < i ; prev++){
            if((arr[i] % arr[prev] == 0) && 1 + dp[prev] > dp[i]){      // The condition 1 + dp[prev] > dp[i] prevents shorter or equal chains from overwriting the best chain.
                dp[i] = max(dp[i], 1 + dp[prev]);
                hash[i] = prev;
            }
        }
        if(dp[i] > maxi){
            maxi = dp[i];   // saving the length.
            lastIndex = i;  // the final index at which the LIS ends.
        }
    }

    vector<int> temp;
    temp.push_back(arr[lastIndex]);
    while(hash[lastIndex] != lastIndex){
        lastIndex = hash[lastIndex];
        temp.push_back(arr[lastIndex]);
    }

    reverse(temp.begin(), temp.end());
    return temp;
}

int main(){
    vector<int> arr = {1,16,4,7,8};
    
    vector<int> ans = LongDivisableSubset(arr);
    for(auto it : ans){
        cout << it << " ";
    }
    return 0;
}