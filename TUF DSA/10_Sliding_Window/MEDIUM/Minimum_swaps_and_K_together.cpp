#include<bits/stdc++.h>
using namespace std;

/*      LC = GFG
    Given an array arr and a number k. One can apply a swap operation on the array any number of times, i.e choose any two index i and j (i < j) and swap arr[i] , arr[j] . Find the minimum number of swaps required to bring all the numbers less than or equal to k together, i.e. make them a contiguous subarray.
*/

// Final function implementation
class Solution {
  public:
    int minSwap(vector<int>& arr, int k) {
        int n = arr.size();
        
        int good = 0;       // ele that must be ended up togther.
        
        // count good elements.
        for(int i = 0 ; i < n ; i++){       
            if(arr[i] <= k) good++;
        }
        
        // count bad ele in the first window.
        int bad = 0;
        for(int i = 0 ; i < good ; i++){
            if(arr[i] > k) bad++;
        }
        
        int ans = bad;      // this will be the num of swaps req to bring all good ele in the first window.
        
        // making a good ele size window cause, we have to bring all of them together.
        int l = 0, r = good;        // here we kept r pointer one index ahead so the window size will be good+1. and then we check.
        
        while(r < n){
            // remove left ele.
            if(arr[l] > k) bad--;
            
            // add right ele.
            if(arr[r] > k) bad++;
            
            ans = min(ans, bad);
            l++, r++;
        }
        
        return ans;
        
    }
};


int main(){
    /*
        Input: arr[] = [2, 1, 5, 6, 3], k = 3
        Output: 1
        Explanation: To bring elements 2, 1, 3 together, swap index 2 with 4 (0-based indexing), i.e. element arr[2] = 5 with arr[4] = 3 such that final array will be- arr[] = [2, 1, 3, 6, 5]

        
        Input: arr[] = [2, 7, 9, 5, 8, 7, 4], k = 6 
        Output: 2 
        Explanation: To bring elements 2, 5, 4 together, swap index 0 with 2 (0-based indexing) and index 4 with 6 (0-based indexing) such that final array will be- arr[] = [9, 7, 2, 5, 4, 7, 8]


        Input: arr[] = [2, 4, 5, 3, 6, 1, 8], k = 6 
        Output: 0
    */

    return 0;
}