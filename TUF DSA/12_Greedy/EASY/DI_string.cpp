#include<bits/stdc++.h>
using namespace std;

/*      LC = 942
    A permutation perm of n + 1 integers of all the integers in the range [0, n] can be represented as a string s of length n where:

    s[i] == 'I' if perm[i] < perm[i + 1], and
    s[i] == 'D' if perm[i] > perm[i + 1].
    Given a string s, reconstruct the permutation perm and return it. If there are multiple valid permutations perm, return any of them.
*/

/*
    Input: s = "IDID"
    Output: [0,4,1,3,2]

    Input: s = "III"
    Output: [0,1,2,3]

    Input: s = "DDI"
    Output: [3,2,0,1]
*/

vector<int> diStringMatch(string s){
    int n = s.size();

    vector<int> arr(n+1);
    for(int i = 0 ; i <= n ; i++){
        arr[i] = i;
    }

    int l = 0, r = n, k = 0;
    vector<int> ans;

    while(l <= r && k < n){
        if(s[k] == 'I'){
            ans.push_back(arr[l]);
            l++;
        }
        else{
            ans.push_back(arr[r]);
            r--;
        }
        k++;
    }
    ans.push_back(arr[l]);
    return ans;
}

int main(){
    string s = "IDID";
}