#include<bits/stdc++.h>
using namespace std;

/*      LC = 131
    Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.
*/

class Solution {
public:
    bool isPalindrome(int i, int j, string s){
        while(i < j){
            if(s[i] != s[j]) return false;
            i++, j--;
        }
        return true;
    }
    void func(int ind, string& s, int n, vector<string>& path, vector<vector<string>>& ans){
        if(ind == n){
            ans.push_back(path);
            return;
        }
        string temp = "";
        for(int j = ind ; j < n ; j++){
            temp += s[j];
            if(isPalindrome(ind, j, s)){
                path.push_back(temp);
                func(j+1, s, n, path, ans);
                path.pop_back();
            }
        }
        return;
    }
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<string> path;
        vector<vector<string>> ans;
        func(0, s, n, path, ans);
        return ans;
    }
};

int main(){
    string s = "aab";
    Solution obj;

    vector<vector<string>> ans = obj.partition(s);      //  [["a","a","b"],["aa","b"]]

    return 0;
}