#include<bits/stdc++.h>
using namespace std;

bool f(int ind, int n, string &s, int cnt){
    if(cnt < 0) return false;
    if(ind == n){
        return (cnt == 0);
    }
    if(s[ind] == '('){
        return f(ind+1, n, s, cnt+1);
    }
    if(s[ind] == ')'){
        return f(ind+1, n, s, cnt-1);
    }
    return f(ind+1, n, s, cnt+1) || f(ind+1, n, s, cnt-1) || f(ind+1, n, s, cnt);
}

bool calc(int ind, int n, string &s, int cnt){
    return f(ind, n, s, cnt);
}

int main(){
    string s = "(*()(";
    int n = s.length();
    int cnt = 0;
    cout << calc(0, n, s, cnt);
    // cout << n;
}