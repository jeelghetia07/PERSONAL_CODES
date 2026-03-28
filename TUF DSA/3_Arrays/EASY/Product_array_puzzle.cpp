#include<bits/stdc++.h>
using namespace std;

/*      GFG
    Given an array, arr[] construct a product array, res[] where each element in res[i] is the product of all elements in arr[] except arr[i]. Return this resultant array, res[].Note: Each element is res[] lies inside the 32-bit integer range.
*/

class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& arr){
        int n = arr.size();
        
        int zeros = 0, TotProduct = 1, idx = -1;
        
        for(int i = 0 ; i < n ; i++){
            if(arr[i] == 0){
                zeros++;
                idx = i;
            }
            else{
                TotProduct *= arr[i];
            }
        }
        
        vector<int> res(n, 0);
        
        if(zeros == 0){
            for(int i = 0 ; i < n ; i++){
                res[i] = TotProduct / arr[i];
            }
            return res;
        }
        
        else if(zeros == 1){
            res[idx] = TotProduct;
        }
        return res;   
    }
  
  
    // vector<int> productExceptSelf(vector<int>& arr) {
        // code here
        // int n = arr.size();
        // vector<int> prefix(n);
        // vector<int> suffix(n);
        
        // prefix[0] = 1;
        
        // for(int i = 1 ; i < n ; i++){
        //     prefix[i] = arr[i-1] * prefix[i-1];
        // }
        
        // suffix[n-1] = 1;
        
        // for(int i = n-2 ; i >= 0 ; i--){
        //     suffix[i] = suffix[i+1] * arr[i+1];
        // }
        
        // vector<int> ans(n);
        
        // for(int i = 0 ; i < n ; i++){
        //     ans[i] = prefix[i] * suffix[i];
        // }
        
        // return ans;
    // }
};


int main(){
    /*
        Input: arr[] = [10, 3, 5, 6, 2]
        Output: [180, 600, 360, 300, 900]
        Explanation: For i=0, res[i] = 3 * 5 * 6 * 2 is 180.
        For i = 1, res[i] = 10 * 5 * 6 * 2 is 600.
        For i = 2, res[i] = 10 * 3 * 6 * 2 is 360.
        For i = 3, res[i] = 10 * 3 * 5 * 2 is 300.
        For i = 4, res[i] = 10 * 3 * 5 * 6 is 900.

        
        Input: arr[] = [12, 0]
        Output: [0, 12]
        Explanation: For i = 0, res[i] is 0.
        For i = 1, res[i] is 12.
    */

    return 0;
}