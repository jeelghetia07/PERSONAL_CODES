#include<bits/stdc++.h>
using namespace std;

/*      LC = 421
    Given an integer array nums, return the maximum result of nums[i] XOR nums[j], where 0 <= i <= j < n.
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
    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size();
        Trie trie;

        for(auto it : nums){
            trie.insert(it);
        }

        int maxi = 0;

        for(auto it : nums){
            maxi = max(maxi, trie.getMax(it));
        }

        return maxi;
    }
};

int main(){
    /*
        Example 1:
            Input: nums = [3,10,5,25,2,8]
            Output: 28
            Explanation: The maximum result is 5 XOR 25 = 28.

        Example 2:
            Input: nums = [14,70,53,83,49,91,36,80,92,51,66,70]
            Output: 127
        
        Constraints:
            1 <= nums.length <= 2 * 105
            0 <= nums[i] <= 231 - 1
    */

    return 0;
}