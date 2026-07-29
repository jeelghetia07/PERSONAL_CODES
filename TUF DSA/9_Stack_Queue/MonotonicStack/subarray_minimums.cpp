#include<bits/stdc++.h>
using namespace std;

/*      LC = 907
    Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. Since the answer may be large, return the answer modulo 109 + 7.
*/

class Solution {
public:
    vector<int> findNSE(vector<int>& arr){
        int n = arr.size();
        vector<int> nse(n);
        stack<int> st;

        for(int i = n-1 ; i >= 0 ; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        return nse;
    }

    vector<int> findPSE(vector<int>& arr){
        int n = arr.size();
        stack<int> st;
        vector<int> pse(n);

        for(int i = 0 ; i < n ; i++){
            while(!st.empty() && arr[st.top()] > arr[i]) st.pop();
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        return pse;
    }

    int sumSubarrayMins(vector<int>& arr) {
        long long sum = 0, n = arr.size();
        const int mod = 1e9+7;
        
        vector<int> nse = findNSE(arr);
        vector<int> pse = findPSE(arr);

        for(int i = 0 ; i < n ; i++){
            int left = i - pse[i];
            int right = nse[i] - i;

            sum = (sum + (1LL * right * left % mod) * arr[i]) % mod;
        }
        return sum;
    }
};

int main(){
    /*
        Example 1:

        Input: arr = [3,1,2,4]
        Output: 17
        Explanation: 
        Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
        Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
        Sum is 17.

        
        Example 2:

        Input: arr = [11,81,94,43,3]
        Output: 444
        

        Constraints:

        1 <= arr.length <= 3 * 104
        1 <= arr[i] <= 3 * 104
    */

    return 0;
}