#include<bits/stdc++.h>
using namespace std;

/*      LC = GFG
    Given an array arr[] of distinct integers and a value sum, find the count of triplets (i, j, k), having (i<j<k) with the sum of (arr[i] + arr[j] + arr[k]) smaller than the given value sum.
*/

class Solution {
  public:
    int countTriplets(int sum, vector<int>& arr) {
        int n = arr.size();
        int left , right, cnt = 0;

        sort(arr.begin(), arr.end());       
        
        for(int i = 0 ; i <= n-3 ; i++){        // i moves till the last 3rd pos.
            left = i+1, right = n-1;
            while(left < right){          
                if(sum <= (arr[i] + arr[left] + arr[right])){           // unitl the sum is greater, keep reducing the right pointer as the array is sorted.
                    right--;
                }
                else{       // if the right is fininshed, then try moving left and repeat.
                    cnt += right-left;
                    left++;
                }
            }
        }
        
        return cnt;
    }
};

int main(){
    /*
        Input: sum = 2, arr[] = [-2, 0, 1, 3]
        Output:  2
        Explanation: Triplets with sum less than 2 are (-2, 0, 1) and (-2, 0, 3). 

        Input: sum = 12, arr[] = [5, 1, 3, 4, 7]
        Output: 4
        Explanation: Triplets with sum less than 12 are (1, 3, 4), (5, 1, 3), (1, 3, 7) and (5, 1, 4).
    */

    return 0;
}