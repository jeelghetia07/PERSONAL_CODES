#include<bits/stdc++.h>
using namespace std;

/*      GFG
    Given an array arr[] consisting of n integers, find all the array elements which occurs more than floor(n/3) times. Return the resulting array in strictly increasing order. If no such elements exist, return an empty array.
*/

        // the hashmap version is easy, but it takes a SC of O(n), and here we have to do with a smaller complexity O(1).

class Solution {
  public:
  
                // BOYER - MOORE ALGO
  
    vector<int> findMajority(vector<int>& arr) {
        // code here
        int n = arr.size();
        
        int cand1 = 0, cand2 = 0;
        int cnt1 = 0, cnt2 = 0;
        
        for(int x : arr){
            if(x == cand1) cnt1++;
            else if(x == cand2) cnt2++;
            else if(cnt1 == 0){
                cand1 = x;
                cnt1++;
            }
            else if(cnt2 == 0){
                cand2 = x;
                cnt2++;
            }
            else{
                cnt1--, cnt2--;
            }
        }
        
        // Now verify the candidates.
        cnt1 = 0, cnt2 = 0;
        
        for(int x : arr){
            if(x == cand1) cnt1++;
            else if(x == cand2) cnt2++;
        }
        
        vector<int> ans;
        
        if(cnt1 > floor(n/3)) ans.push_back(cand1);
        if(cnt2 > floor(n/3)) ans.push_back(cand2);
        
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};

int main(){
    /*
        Input: arr[] = [2, 2, 3, 1, 3, 2, 1, 1]
        Output: [1, 2]
        Explanation: The frequency of 1 and 2 is 3, which is more than floor n/3 (8/3 = 2).


        Input:  arr[] = [-5, 3, -5]
        Output: [-5]
        Explanation: The frequency of -5 is 2, which is more than floor n/3 (3/3 = 1).


        Input:  arr[] = [3, 2, 2, 4, 1, 4]
        Output: []
        Explanation: There is no majority element.


        Constraint:
        1 ≤ arr.size() ≤ 106
        -105 ≤ arr[i] ≤ 105

    */

    return 0;
}