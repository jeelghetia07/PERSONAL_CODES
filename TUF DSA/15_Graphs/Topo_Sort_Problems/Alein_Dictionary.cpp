// Alein_Dictionary.cpp
#include<bits/stdc++.h>
using namespace std;

// VERY HARD QUES

/*
    A new alien language uses the English alphabet, but the order of letters is unknown. You are given a list of words[] from the alien language’s dictionary, where the words are claimed to be sorted lexicographically according to the language’s rules.

    Your task is to determine the correct order of letters in this alien language based on the given words. If the order is valid, return a string containing the unique letters in lexicographically increasing order as per the new language's rules. If there are multiple valid orders, return any one of them.

    However, if the given arrangement of words is inconsistent with any possible letter ordering, return an empty string ("").

    A string a is lexicographically smaller than a string b if, at the first position where they differ, the character in a appears earlier in the alien language than the corresponding character in b. If all characters in the shorter word match the beginning of the longer word, the shorter word is considered smaller.
*/

vector<int> toposort(vector<vector<int>>& adj, vector<bool>& present){
    vector<int> indegree(26, 0);
    
    for(int i = 0 ; i < 26 ; i++){
        for(auto it : adj[i]){
            indegree[it]++;
        }
    }
    
    queue<int> q;
    vector<int> topo;
    
    for(int i = 0 ; i < 26 ; i++){
        if(present[i] && indegree[i] == 0) q.push(i);
    }
    
    while(!q.empty()){
        int node = q.front();
        q.pop();
        topo.push_back(node);
        
        for(auto it : adj[node]){
            indegree[it]--;     // removing the neighbour nodes.
            if(indegree[it] == 0) q.push(it);
        }
    }
    
    return topo;
}

string findOrder(vector<string> &words) {
    int n = words.size();
    
    vector<vector<int>> adj(26);
    vector<bool> present(26, false);    // this will check which words are presnt in the whole code.
    
    for(auto &w : words){       // this marks all present characters in the dictionary.
        for(char ch : w){
            present[ch - 'a'] = true;
        }
    }
    
    for(int i = 0 ; i < n-1 ; i++){
        string s1 = words[i];
        string s2 = words[i+1];
        
        if(s1.size() > s2.size() && s1.substr(0, s2.size()) == s2){
            return "";
        }
        
        int len = min(s1.size(), s2.size());
        
        for(int ptr = 0 ; ptr < len ; ptr++){
            if(s1[ptr] != s2[ptr]){
                adj[s1[ptr]-'a'].push_back(s2[ptr]-'a');
                break;      // to stop the loop and do the same for the next 2 words.
            }
        }
    }
    
    vector<int> topo = toposort(adj, present);
    
    int cnt = 0;
    for(int i = 0 ; i < 26 ; i++){
        if(present[i]) cnt++;
    }
    
    if(topo.size() != cnt) return "";
    
    string ans;
    
    for(auto it : topo){
        ans += char(it + 'a');
    }
    return ans;
}

int main(){

    vector<vector<string>> testCases = {
        // 1️ Normal valid case
        {"baa","abcd","abca","cab","cad"},

        // 2️ Prefix invalid case
        {"abc","ab"},

        // 3️ Cycle case
        {"ab","bc","ca"},

        // 4️ Single word
        {"abc"},

        // 5️ Simple valid ordering
        {"caa","aaa","aab"},

        // 6️ Disconnected characters
        {"z","x"}
    };

    for(int t = 0; t < testCases.size(); t++){

        cout << "Test Case " << t+1 << ":\n";

        vector<string> words = testCases[t];

        cout << "Input: ";
        for(auto &w : words){
            cout << w << " ";
        }
        cout << "\n";

        string result = findOrder(words);

        if(result == ""){
            cout << "Output: \"\" (Invalid Dictionary)\n";
        } else {
            cout << "Output: " << result << "\n";
        }

        cout << "--------------------------\n";
    }

    return 0;
}
