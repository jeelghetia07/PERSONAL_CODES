// Generate_Parenthisis.cpp
#include<bits/stdc++.h>
using namespace std;

// vector<string> func(int open, int close, int n, string& str, vector<string>& ans){
//     if(open == n && close == n) ans.push_back(str);
//     if(open < n){
//         str.push_back('(');
//         func(open+1, close, n, str, ans);
//         str.pop_back();
//     }
//     if(close < open){
//         str.push_back(')');
//         func(open, close+1, n, str, ans);
//         str.pop_back();
//     }
//     return ans;
// }

// vector<string> generateParenthesis(int n){
//     int open = 0, close = 0;
//     string str = "";
//     vector<string> ans;
//     return func(open, close, n, str, ans);
// }


vector<string> func(int open, int close, int n, string& str, vector<string>& ans){
    if(open == n && close == n) ans.push_back(str);
    if(open < n){
        str.push_back('(');
        func(open+1, close, n, str, ans);
        str.pop_back();
    }
    if(close < open){
        str.push_back(')');
        func(open, close+1, n, str, ans);
        str.pop_back();
    }
    return ans;
}

vector<string> generateParenthesis(int n){
    vector<string> ans;
    queue<pair<string, pair<int, int>>> q;

    q.push({"(",{1,0}});
    while(q.size()){
        auto temp = q.front();
        q.pop();
        string s = temp.first;
        int open = temp.second.first;
        int close = temp.second.second;

        if(s.length() == 2*n){
            ans.push_back(s);
            continue;
        }

        if(open < n) q.push({s+'(', {open+1, close}});
        if(close < open) q.push({s+')', {open, close+1}});
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<string> ans = generateParenthesis(n);

    for(auto it : ans){
        cout << it << " , ";
    }
    return 0;
}