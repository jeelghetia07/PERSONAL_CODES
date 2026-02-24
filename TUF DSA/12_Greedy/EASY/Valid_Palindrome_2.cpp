#include<bits/stdc++.h>
using namespace std;

/*      LC 680
    Given a string s, return true if the s can be palindrome after deleting at most one character from it.
*/

bool isPalindrome(int i, int j, string& s){
    while(i <= j){
        if(s[i] == s[j]){
            i++, j--;
        }
        else{
            return false;
        }
    }
    return true;
}
bool validPalindrome(string s) {        // TC = O(n)...sc = O(1).
    int n = s.size();
    int l = 0, r = n-1;
    while(l <= r){
        if(s[l] == s[r]){
            l++, r--;
        }
        else{
            return isPalindrome(l+1, r, s) || isPalindrome(l, r-1, s);
        }
    }
    return true;
}

int main(){
    string s = "abcda";     // try    abda....abbca
}