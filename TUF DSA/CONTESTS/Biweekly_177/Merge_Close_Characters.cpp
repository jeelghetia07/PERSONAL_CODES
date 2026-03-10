#include<bits/stdc++.h>
using namespace std;

/*      LC = 
    You are given a string s consisting of lowercase English letters and an integer k.

    Two equal characters in the current string s are considered close if the distance between their indices is at most k.

    When two characters are close, the right one merges into the left. Merges happen one at a time, and after each merge, the string updates until no more merges are possible.

    Return the resulting string after performing all possible merges.

    Note: If multiple merges are possible, always merge the pair with the smallest left index. If multiple pairs share the smallest left index, choose the pair with the smallest right index.
*/

string mergeCharacters(string s, int k) {
    string ans = "";

    for(auto c : s){
        bool match = false;

        for(int j = max(0, (int)ans.size()-k) ; j < ans.size() ; j++){
            if(ans[j] == c){
                match = true;
                break;
            }
        }
        if(!match) ans.push_back(c);
    }
    return ans;
}

int main(){
    string s1 = "abca"; 
    string s2 = "aabca";
    string s3 = "yybyzybz";

    int k1 = 3, k2 = 2, k3 = 2;
    
    return 0;
}