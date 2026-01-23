#include<bits/stdc++.h>
using namespace std;


                // RECURRSIIVE METHOD....TC = O(3n) EXPONANTIAL

// bool f(int ind, int n, string &s, int cnt){
//     if(cnt < 0) return false;
//     if(ind == n){
//         return (cnt == 0);
//     }
//     if(s[ind] == '('){
//         return f(ind+1, n, s, cnt+1);
//     }
//     if(s[ind] == ')'){
//         return f(ind+1, n, s, cnt-1);
//     }
//     return f(ind+1, n, s, cnt+1) || f(ind+1, n, s, cnt-1) || f(ind+1, n, s, cnt);
// }

// bool calc(int ind, int n, string &s, int cnt){
//     return f(ind, n, s, cnt);
// }


bool calc(int n, string s){
    int min = 0, max = 0;
    for(int i = 0 ; i < n ; i++){
        if(s[i] == '('){
            min++;
            max++;
        }
        else if(s[i] == ')'){
            min--;
            max--;
        }
        else{
            min--;
            max++;
        }
        if(min < 0) min = 0;
        if(max < 0) return false;
    }
    return (min == 0);
}

int main(){
    string s = "(*()(";
    int n = s.length();
    int cnt = 0;
    cout << calc(n, s);
    // cout << n;
}