#include<bits/stdc++.h>
using namespace std;

/*      LC = 556
    Given a positive integer n, find the smallest integer which has exactly the same digits existing in the integer n and is greater in value than n. If no such positive integer exists, return -1.

    Note that the returned integer should fit in 32-bit integer, if there is a valid answer but it does not fit in 32-bit integer, return -1.
*/

class Solution {
public:
    // THe logic is almost same as NEXT permutation.
    int nextGreaterElement(int n) {
        string temp = to_string(n);
        int sz = temp.size();

        int pivot = -1;
        for(int i = sz-1 ; i > 0 ; i--){
            if(temp[i] > temp[i-1]){
                pivot = i-1;
                break;
            }
        }

        if(pivot == -1) return -1;

        for(int i = sz-1 ; i >= 0 ; i--){
            if(temp[i] > temp[pivot]){
                swap(temp[i], temp[pivot]);
                break;
            }
        }

        int i = pivot+1, j = sz-1;
        while(i < j){
            swap(temp[i], temp[j]);
            i++, j--;
        }

        // if the val exceeds this, we have to use stoll.
        long long ans = stoll(temp);
        return (ans > INT_MAX) ? -1 : (int)ans;
    }
};

int main(){
    /*
        Example 1:

        Input: n = 12
        Output: 21

        
        Example 2:

        Input: n = 21
        Output: -1
        

        Constraints:

        1 <= n <= 231 - 1
    */

    return 0;
}