#include<bits/stdc++.h>
using namespace std;

/*      GFG
    Given an array arr[] that contains positive and negative integers (may contain 0 as well). Find the maximum product that we can get in a subarray of arr[].

    Note: It is guaranteed that the answer fits in a 32-bit integer.    
*/

class Solution {
  public:
    int maxProduct(vector<int> &arr) {
        int n = arr.size();
        int maxPro = arr[0];
        int minPro = arr[0];
        
        int maxi = arr[0];
        
        for(int i = 1 ; i < n ; i++){
            int prevMax = maxPro;
            int prevMin = minPro;
            
            maxPro = max({arr[i], arr[i]*prevMax, arr[i]*prevMin});
            minPro = min({arr[i], arr[i]*prevMax, arr[i]*prevMin});
            
            maxi = max({maxi, maxPro, minPro});
        }
        
        return maxi;
    }
};

int main(){
    /*
        Input: arr[] = [-2, 6, -3, -10, 0, 2]
        Output: 180
        Explanation: The subarray with maximum product is [6, -3, -10] with product = 6 * (-3) * (-10) = 180.

        Input: arr[] = [-1, -3, -10, 0, 6]
        Output: 30
        Explanation: The subarray with maximum product is [-3, -10] with product = (-3) * (-10) = 30.

        Input: arr[] = [2, 3, 4] 
        Output: 24 
        Explanation: For an array with all positive elements, the result is product of all elements. 
    */

    return 0;
}