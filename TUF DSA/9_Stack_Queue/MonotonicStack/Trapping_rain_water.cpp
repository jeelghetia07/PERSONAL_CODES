#include<bits/stdc++.h>
using namespace std;

/*      LC = 42
    Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.
*/

class Solution {
public:
    int trap(vector<int>& arr) {
        int n = arr.size();

        // to see the largest building on the sides so that water can be filled in between.
        int leftmax = 0, rightmax = 0, total = 0;     
        
        // traversing pointers
        int l = 0, r = n-1;    

        while(l < r){
            int left = arr[l];
            int right = arr[r];

            if(left < right){
                if(leftmax > left)
                    total += (leftmax - left);
                else
                    leftmax = left;
                l++;
            }
            // if left is bigger, check the largest building to the right, if we can fill water between left "right" rightmax. or not.
            else if(left > right){
                if(rightmax > right)
                    total += (rightmax - right);
                else
                    rightmax = right;
                r--;
            }
            // if both buildings are equal in size we cannot fill water.
            else{
                leftmax = max(left, leftmax);
                l++;   
            }
        }

        return total;
    }
};

int main(){
    /*
        Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
        Output: 6
        Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
        

        Input: height = [4,2,0,3,2,5]
        Output: 9
    */

    return 0;
}