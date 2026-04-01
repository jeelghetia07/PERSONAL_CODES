#include<bits/stdc++.h>
using namespace std;

/*      GFG
    Given an array arr[]  and a positive integer k, find the first negative integer for each and every window(contiguous subarray) of size k.

    Note: If a window does not contain a negative integer, then return 0 for that window.
*/

class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {      // TC = O(n), SC = O(k).
        int n = arr.size();
        queue<int> q;
        vector<int> ans;
        
        for(int i = 0 ; i < k ; i++){
            if(arr[i] < 0){
                q.push(i);
            }
        }
        
        if(!q.empty()) ans.push_back(arr[q.front()]);
        else ans.push_back(0);
        
        for(int i = k ; i < n ; i++){
            while(!q.empty() && q.front() < i-k+1){
                q.pop();
            }
            if(arr[i] < 0) q.push(i);
            if(!q.empty()) ans.push_back(arr[q.front()]);
            else{
                ans.push_back(0);
            }
        }
        
        return ans;
    }
};

int main(){
    /*
        Input: arr[] = [-8, 2, 3, -6, 10] , k = 2
        Output: [-8, 0, -6, -6]
    
        Input: arr[] = [12, -1, -7, 8, -15, 30, 16, 28] , k = 3
        Output: [-1, -1, -7, -15, -15, 0] 
        
        Input: arr[] = [12, 1, 3, 5] , k = 3
        Output: [0, 0] 
        
    */

    return 0;
}