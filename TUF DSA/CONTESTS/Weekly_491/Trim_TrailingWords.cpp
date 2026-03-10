#include<bits/stdc++.h>
using namespace std;

/*      LC = 3856
    You are given a string s that consists of lowercase English letters.
    Return the string obtained by removing all trailing vowels from s.
    The vowels consist of the characters 'a', 'e', 'i', 'o', and 'u'.
*/

bool checkVowel(char s){
    return (s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u');
}
string trimTrailingVowels(string s) {
    int n = s.size();
    int i = n-1;
    string ans;

    while(i >= 0 && checkVowel(s[i])){
        i--;
    }

    for(int k = 0 ; k <= i ; k++){
        ans.push_back(s[k]);
    }
    return ans;
}

int main(){
    string s1 = "idea", s2 = "day", s3 = "bdaiytaioe";      // only remove last continue vowels.
    string ans = trimTrailingVowels(s3);
    return 0;
}