#include<bits/stdc++.h>
using namespace std;

/*      LC = 2104
    You are given an integer array nums. The range of a subarray of nums is the difference between the largest and smallest element in the subarray.

    Return the sum of all subarray ranges of nums.

    A subarray is a contiguous non-empty sequence of elements within an array.
*/

using ll = long long;
class Solution {
    vector<ll> findNSE(vector<int>& arr, int n){
        vector<ll> nse(n);
        stack<ll> st;

        for(int i = n-1 ; i >= 0 ; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            nse[i] = (st.empty()) ? n : st.top();
            st.push(i);
        }

        return nse;
    }

    vector<ll> findPSE(vector<int>& arr, int n){
        vector<ll> pse(n);
        stack<ll> st;

        for(int i = 0 ; i <= n-1 ; i++){
            while(!st.empty() && arr[st.top()] > arr[i]) st.pop();
            pse[i] = (st.empty()) ? -1 : st.top();
            st.push(i);
        }

        return pse;
    }

    vector<ll> findNGE(vector<int>& arr, int n){
        vector<ll> nge(n);
        stack<ll> st;

        for(int i = n-1 ; i >= 0 ; i--){
            while(!st.empty() && arr[st.top()] <= arr[i]) st.pop();
            nge[i] = (st.empty()) ? n : st.top();
            st.push(i);
        }

        return nge;
    }

    vector<ll> findPGE(vector<int>& arr, int n){
        vector<ll> pge(n);
        stack<ll> st;

        for(int i = 0 ; i <= n-1 ; i++){
            while(!st.empty() && arr[st.top()] < arr[i]) st.pop();
            pge[i] = (st.empty()) ? -1 : st.top();
            st.push(i);
        }

        return pge;
    }

public:
    ll sumMax(vector<int>& arr, int n){
        vector<ll> nge = findNGE(arr, n);
        vector<ll> pge = findPGE(arr, n);

        ll sum = 0;

        for(int i = 0 ; i < n ; i++){
            ll left = i - pge[i];
            ll right = nge[i] - i;

            sum += (right*left*arr[i]);
        }

        return sum;
    }
    ll sumMin(vector<int>& arr, int n){
        vector<ll> nse = findNSE(arr, n);
        vector<ll> pse = findPSE(arr, n);

        ll sum = 0;

        for(int i = 0 ; i < n ; i++){
            ll left = i - pse[i];
            ll right = nse[i] - i;

            sum += (right*left*arr[i]);
        }

        return sum;
    }
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();

        return sumMax(nums, n) - sumMin(nums, n);
    }
};

int main(){
    /*
        Example 1:

        Input: nums = [1,2,3]
        Output: 4
        Explanation: The 6 subarrays of nums are the following:
        [1], range = largest - smallest = 1 - 1 = 0 
        [2], range = 2 - 2 = 0
        [3], range = 3 - 3 = 0
        [1,2], range = 2 - 1 = 1
        [2,3], range = 3 - 2 = 1
        [1,2,3], range = 3 - 1 = 2
        So the sum of all ranges is 0 + 0 + 0 + 1 + 1 + 2 = 4.
        Example 2:

        Input: nums = [1,3,3]
        Output: 4
        Explanation: The 6 subarrays of nums are the following:
        [1], range = largest - smallest = 1 - 1 = 0
        [3], range = 3 - 3 = 0
        [3], range = 3 - 3 = 0
        [1,3], range = 3 - 1 = 2
        [3,3], range = 3 - 3 = 0
        [1,3,3], range = 3 - 1 = 2
        So the sum of all ranges is 0 + 0 + 0 + 2 + 0 + 2 = 4.
        Example 3:

        Input: nums = [4,-2,-3,4,1]
        Output: 59
        Explanation: The sum of all subarray ranges of nums is 59.
        

        Constraints:

        1 <= nums.length <= 1000
        -109 <= nums[i] <= 109
    */

    return 0;
}