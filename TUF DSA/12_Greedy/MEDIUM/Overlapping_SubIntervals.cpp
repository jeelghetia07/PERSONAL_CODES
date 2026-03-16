#include<bits/stdc++.h>
using namespace std;

/*      GFG
    Given an array of Intervals arr[][], where arr[i] = [starti, endi]. The task is to merge all of the overlapping Intervals.
*/

class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        // Code here
        sort(arr.begin(), arr.end());
        int n = arr.size();
        
        vector<vector<int>> ans;
        
        int srt = arr[0][0];
        int end = arr[0][1];
        
        for(int i = 1 ; i < n ; i++){
            int begin = arr[i][0];
            int finish = arr[i][1];
            if(begin <= end){
                if(finish > end){
                    end = finish;
                }
                else continue;
            }
            else{
                ans.push_back({srt, end});
                srt = begin;
                end = finish;
            }
        }
        ans.push_back({srt, end});
        return ans;
    }
};

int main(){
    vector<vector<int>> arr = [[1, 3], [2, 4], [6, 8], [9, 10]];        // ans [[1, 4], [6, 8], [9, 10]]

    return 0;
}