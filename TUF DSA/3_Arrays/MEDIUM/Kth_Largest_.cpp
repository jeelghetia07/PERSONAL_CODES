#include<bits/stdc++.h>
using namespace std;

/*      LC = 215
    Given an integer array nums and an integer k, return the kth largest element in the array.
    Note that it is the kth largest element in the sorted order, not the kth distinct element.
    Can you solve it without sorting?
    
*/

class Solution {
public:
    int findKthLargest(vector<int>& arr, int k) {       // TC = O(n* logk).
        int n = arr.size();

        priority_queue<int, vector<int>, greater<int>> pq;

        for(int i = 0 ; i < k ; i++){
            pq.push(arr[i]);
        }

        for(int i = k ; i < n ; i++){
            if(pq.top() < arr[i]){
                pq.pop();
                pq.push(arr[i]);
            }
        }

        return pq.top();
    }
};

int main(){
    /*
        Example 1:

        Input: nums = [3,2,1,5,6,4], k = 2
        Output: 5


        
        Example 2:

        Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
        Output: 4
    */

    return 0;
}