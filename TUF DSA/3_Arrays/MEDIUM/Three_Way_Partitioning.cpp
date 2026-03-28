#include<bits/stdc++.h>
using namespace std;

/*      GFG
    Given an array and a range a, b. The task is to partition the array around the range such that the array is divided into three parts.
    1) All elements smaller than a come first.
    2) All elements in range a to b come next.
    3) All elements greater than b appear in the end.
    The individual elements of three sets can appear in any order. You are required to return the modified array.

    Note: The generated output is true if you modify the given array successfully. Otherwise false.

    Geeky Challenge: Solve this problem in O(n) time complexity.
*/

class Solution {
  public:
    void threeWayPartition(vector<int>& arr, int a, int b) {
        // code here
        int n = arr.size();             // DUTCH NATIONAL FLAG algorithm
        int low = 0, mid = 0, high = n-1;
        
        while(mid <= high){
            if(arr[mid] < a){
                swap(arr[mid], arr[low]);
                low++, mid++;
            }
            else if(arr[mid] > b){
                swap(arr[high], arr[mid]);
                high--;
            }
            else{
                mid++;
            }
        }
    }
};

int main(){
    /*
        Input: arr[] = [1, 2, 3, 3, 4], a = 1, b = 2
        Output: true
        Explanation: One possible arrangement is: {1, 2, 3, 3, 4}. If you return a valid arrangement, output will be true.

        
        Input: arr[] = [1, 4, 3, 6, 2, 1], a = 1, b = 3
        Output: true
        Explanation: One possible arrangement is: {1, 3, 2, 1, 4, 6}. If you return a valid arrangement, output will be true.
    */

    return 0;
}