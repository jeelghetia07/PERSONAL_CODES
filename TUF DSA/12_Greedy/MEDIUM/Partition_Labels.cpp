#include<bits/stdc++.h>
using namespace std;

/*
    You are given a string s. We want to partition the string into as many parts as possible so that each letter appears in at most one part. For example, the string "ababcc" can be partitioned into ["abab", "cc"], but partitions such as ["aba", "bcc"] or ["ab", "ab", "cc"] are invalid.
    Note that the partition is done so that after concatenating all the parts in order, the resultant string should be s.

    Return a list of integers representing the size of these parts.
*/

vector<int> partitionLabels(string s) {
    vector<int> ans;
    unordered_map<char, int> mpp;

    int n = s.size();

    for(int i = 0 ; i < n ; i++){
        mpp[s[i]] = i;
    }

    int start = 0, end = -1e9;
    for(int i = 0 ; i < s.size() ; i++){
        end = max(end, mpp[s[i]]);
        if(i == end){
            ans.push_back(end-start+1);
            start = end+1;
            end = -1e9;
        }
    }
    return ans;
}

int main(){
    string s1 = "ababcbacadefegdehijhklij", s2 = "abaccbdeffed";

    vector<int> ans = partitionLabels(s1);      // ans :- [9,7,8], [6,6].
    cout << "The partitions are : ";
}