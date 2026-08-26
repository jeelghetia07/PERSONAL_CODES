#include<bits/stdc++.h>
using namespace std;

/*      GFG 
    Given an array of integers of size N and a number K., You must modify array arr[] exactly K number of times. Here modify array means in each operation you can replace any array element either arr[i] by -arr[i] or -arr[i] by arr[i]. You need to perform this operation in such a way that after K operations, the sum of the array must be maximum.
*/

class Solution {
  public:
    long long int maximizeSum(long long int arr[], int n, int k) {
        // Your code goes here
        long long int sum = 0;
        
        sort(arr, arr+n);
        
        for(int i = 0 ; i < n && k > 0 && arr[i] <= 0 ; i++){
            arr[i] *= -1;
            k--;
        }
        
        k = k % 2;      // if even chances left we can repeatedly make any number + -> - and - -> +..this is even.
        
        for(int i = 0 ; i < n ; i++){
            sum += arr[i];
        }
        
        if(k == 0) return sum;
        
        int minIdx = 0;
        
        for(int i = 1 ; i < n ; i++){
            if(arr[i] < arr[minIdx]) minIdx = i;
        }
        
        return sum - 2LL*arr[minIdx];           // here after making a (+ve) ele / (-ve) ele, it means, we reduced that ele from the sum 2 times.
    }
};

int main(){
    /*
        Example 1:

        Input:
        N = 5, K = 1
        arr[] = {1, 2, -3, 4, 5}
        Output:
        15
        Explanation:
        We have k=1 so we can change -3 to 3 and
        sum all the elements to produce 15 as output.


        Example 2:

        Input:
        N = 10, K = 5
        arr[] = {5, -2, 5, -4, 5, -12, 5, 5, 5, 20}
        Output:
        68
        Explanation:
        Here  we have k=5 so we turn -2, -4, -12 to
        2, 4, and 12 respectively. Since we have
        performed 3 operations so k is now 2. To get
        maximum sum of array we can turn positive
        turned 2 into negative and then positive
        again so k is 0. Now sum is
        5+5+4+5+12+5+5+5+20+2 = 68
            
        */

    return 0;
}