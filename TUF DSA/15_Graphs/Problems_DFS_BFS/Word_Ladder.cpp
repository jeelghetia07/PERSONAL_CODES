#include<bits/stdc++.h>
using namespace std;

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    queue<pair<string, int>> q;
    q.push({beginWord, 1});     // 1 here is number of steps.

    unordered_set<string> st(wordList.begin(), wordList.end());     // copying the elements so that in future we can remove those.
    st.erase(beginWord);      // this erase is showing that we have visited that particular word.

    while(!q.empty()){
        string word = q.front().first;
        int steps = q.front().second;
        q.pop();
        if(word == endWord) return steps;
        for(int i = 0 ; i < word.size() ; i++){
            char original = word[i];
            for(char ch = 'a' ; ch <= 'z' ; ch++){
                word[i] = ch;
                if(st.find(word) != st.end()){
                    st.erase(word);
                    q.push({word, steps+1});
                }
            }
            word[i] = original;
        }
    }
    return 0;
}

int main(){
    string beginWord = "hit", endWord = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};

    cout << "The min steps to convert is : " << ladderLength(beginWord, endWord, wordList);
    return 0;
}