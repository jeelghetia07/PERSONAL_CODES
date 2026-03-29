#include<bits/stdc++.h>
using namespace std;

/*      GFG
    Given an array arr[ ] of positive elements. Consider the array as a circular array, meaning the element after the last element is the first element of the array. The task is to find the maximum sum of the absolute differences between consecutive elements with shuffling of array elements allowed i.e. shuffle the array elements and make [a1..an] such order that  |a1 – a2| + |a2 – a3| + …… + |an-1 – an| + |an – a1| is maximized.
*/

class Solution {
  public:
    long long maxSum(vector<int>& arr) {        // here the main obseration is to keep the smallest with the largest again smaller with larger.....
        int n = arr.size();
        sort(arr.begin(), arr.end());
        
        int i = 0, j = n-1;
        vector<int> ans;
        
        while(i < j){                   // this make the order,  small, large, small, large, small, large......this is the only way to maximize the ans.
            ans.push_back(arr[i++]);
            ans.push_back(arr[j--]);
        }
        
        if(i == j) ans.push_back(arr[i]);
        
        long long sum = 0;
        for(int i = 0 ; i < n-1 ; i++){
            sum += abs(ans[i] - ans[i+1]);
        }
        sum += abs(ans[n-1] - ans[0]);
        return sum;
    }
};


int main(){
    /*
        Input: arr[] = [4, 2, 1, 8]
        Output: 18
        Explanation: After Shuffling, we get [1, 8, 2, 4]. Sum of absolute difference between consecutive elements after rearrangement = |1 - 8| + |8 - 2| + |2 - 4| + |4 - 1| = 7 + 6 + 2 + 3 = 18.

        
        Input: arr[] = [10, 12]
        Output: 4
        Explanation: No need of rearrangement. Sum of absolute difference between consecutive elements = |10 - 12| + |12 - 10| = 2 + 2 = 4.
    */

    return 0;
}