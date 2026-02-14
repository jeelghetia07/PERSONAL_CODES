#include<bits/stdc++.h>
using namespace std;

/*
    Problem Statement: Given are the two distinct words startWord and targetWord, and a list denoting wordList of unique words of equal lengths. Find the length of the shortest transformation sequence from startWord to targetWord..

    In this problem statement, we need to keep the following conditions in mind:

    A word can only consist of lowercase characters.
    Only one letter can be changed in each transformation.
    Each transformed word must exist in the wordList including the targetWord.
    startWord may or may not be part of the wordList
    Note:  If there’s no possible way to transform the sequence from startWord to targetWord return 0.
*/

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
        for(int i = 0 ; i < word.size() ; i++){     // checking each char of the word with all alphabets.
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