#include<bits/stdc++.h>
using namespace std;

/*      LC = 1707
    You are given an array nums consisting of non-negative integers. You are also given a queries array, where queries[i] = [xi, mi].

    The answer to the ith query is the maximum bitwise XOR value of xi and any element of nums that does not exceed mi. In other words, the answer is max(nums[j] XOR xi) for all j such that nums[j] <= mi. If all elements in nums are larger than mi, then the answer is -1.

    Return an integer array answer where answer.length == queries.length and answer[i] is the answer to the ith query.
*/

struct Node{
    Node* links[2];

    bool containsKey(int bit){
        return (links[bit] != NULL);
    }

    void put(int bit, Node* node){
        links[bit] = node;
    }

    Node* next(int bit){
        return links[bit];
    }
};

class Trie{
    Node* root;
public:
    Trie(){
        root = new Node();
    }

    void insert(int num){
        Node* node = root;
        
        for(int i = 31 ; i >= 0 ; i--){
            int bit = (num >> i) & 1;       // this will tell the value of bit at moment.
            if(!node->containsKey(bit)){
                node->put(bit, new Node());
            }
            node = node->next(bit);
        }
    }

    int getMax(int num){
        Node* node = root;
        int maxNum = 0;

        for(int i = 31 ; i >= 0 ; i--){
            int bit = (num >> i) & 1;
            if(node->containsKey(1-bit)){
                maxNum = maxNum | (1 << i);
                node = node->next(1-bit);
            }
            else{
                node = node->next(bit);
            }
        }

        return maxNum;
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& arr, vector<vector<int>>& queries) {
        sort(arr.begin(), arr.end());

        Trie trie;

        vector<pair<int, pair<int, int>>> OQ;      // offline queries.
        int q = queries.size();

        for(int i = 0 ; i < q ; i++){
            OQ.push_back({queries[i][1], {queries[i][0], i}});        // this stores the queries as the lowest starting first.
        }

        sort(OQ.begin(), OQ.end());
        vector<int> ans(q, 0);

        int ind = 0;
        for(int i = 0 ; i < q ; i++){
            int ai = OQ[i].first;
            int xi = OQ[i].second.first;
            int qIND = OQ[i].second.second;

            while(ind < arr.size() && arr[ind] <= ai){
                trie.insert(arr[ind]);
                ind++;
            }
            
            if(ind == 0) ans[qIND] = -1;
            else{
                int xorValue = trie.getMax(xi);
                ans[qIND] = xorValue;
            }
        }

        return ans;
    }
};

int main(){


    return 0;
}