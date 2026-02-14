#include<bits/stdc++.h>
using namespace std;

//  EXTREMELY HARD QUESTION. 

/*
    A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words
    beginWord -> s1 -> s2 -> ... -> sk such that:

    Every adjacent pair of words differs by a single letter.
    Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
    sk == endWord
    Given two words, beginWord and endWord, and a dictionary wordList, return all the shortest transformation sequences from beginWord to endWord, or an empty list if no such sequence exists. Each sequence should be returned as a list of the words [beginWord, s1, s2, ..., sk].
*/

unordered_map<string, int> mpp;
vector<vector<string>> ans;
string b;

void dfs(string word, vector<string>& seq){
    if(word == b){
        reverse(seq.begin(), seq.end());
        ans.push_back(seq);
        reverse(seq.begin(), seq.end());
        return;
    }
    int steps = mpp[word];
    for(int i = 0 ; i < word.size() ; i++){
        char original = word[i];
        for(char ch = 'a' ; ch <= 'z' ; ch++){
            word[i] = ch;
            if(mpp.find(word) != mpp.end() && mpp[word]+1 == steps){
                seq.push_back(word);
                dfs(word, seq);
                seq.pop_back();
            }
        }
        word[i] = original;
    }
}

vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        queue<string> q;
        q.push({beginWord});
        mpp[beginWord] = 1;
        b = beginWord;
        int sz = beginWord.size();

        unordered_set<string> st(wordList.begin(), wordList.end());
        st.erase(beginWord);

        while(!q.empty()){
            string word = q.front();
            int steps = mpp[word];
            q.pop();
            if(word == endWord) break;
            for(int i = 0 ; i < sz ; i++){
                char original = word[i];
                for(char ch = 'a' ; ch <= 'z' ; ch++){
                    word[i] = ch;
                    if(st.find(word) != st.end()){
                        q.push({word});
                        st.erase(word);
                        mpp[word] = steps+1;
                    }
                }
                word[i] = original;
            }
        }
        if(mpp.find(endWord) != mpp.end()){
            vector<string> seq;
            seq.push_back(endWord);
            dfs(endWord, seq);
        }
        return ans;
}

int main(){
    string beginWord = "hit", endWord = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};

     vector<vector<string>> result = findLadders(beginWord, endWord, wordList);

    for(auto &path : result){
        for(auto &word : path){
            cout << word << " ";
        }
        cout << endl;
    }
}