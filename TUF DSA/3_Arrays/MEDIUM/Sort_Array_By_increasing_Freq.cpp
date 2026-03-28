#include<bits/stdc++.h>
using namespace std;

/*      LC = 1636
    Given an array of integers nums, sort the array in increasing order based on the frequency of the values. If multiple values have the same frequency, sort them in decreasing order.
    Return the sorted array.
*/

class Solution {
public:
    static bool cmp(pair<int,int>&a, pair<int,int>&b) {
        return  (a.second==b.second) ? a.first>b.first : a.second<b.second;
    }
    vector<int> frequencySort(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mpp;

        for(int i = 0 ; i < n ; i++){
            mpp[nums[i]]++;
        }

        vector<pair<int,int>> val_freq;

        for(auto m : mpp) {
            val_freq.push_back(m);
        }

        sort(val_freq.begin(),val_freq.end(),cmp);

        vector<int> result;

        for(auto v : val_freq) {
            for(int i=0;i<v.second;i++) {
                result.push_back(v.first);
            }
        }
        return result;
    }
};

int main(){
    /*
        Example 1:

        Input: nums = [1,1,2,2,2,3]
        Output: [3,1,1,2,2,2]
        Explanation: '3' has a frequency of 1, '1' has a frequency of 2, and '2' has a frequency of 3.


        Example 2:

        Input: nums = [2,3,1,3,2]
        Output: [1,3,3,2,2]
        Explanation: '2' and '3' both have a frequency of 2, so they are sorted in decreasing order.

        
        Example 3:

        Input: nums = [-1,1,-6,4,5,-6,1,4,1]
        Output: [5,-1,4,4,-6,-6,1,1,1]
    */

    return 0;
}