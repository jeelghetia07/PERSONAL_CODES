#include<bits/stdc++.h>
using namespace std;

/*      LC = 875
    Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

    Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

    Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

    Return the minimum integer k such that she can eat all the bananas within h hours.
*/

class Solution {
public:
    int findmaxEle(vector<int>& arr){
        int n = arr.size();
        int maxi = INT_MIN;
        for(int i = 0 ; i < n ; i++){
            maxi = max(maxi,arr[i]);
        }
        return maxi;
    }

    long long findtotalhrs(vector<int>& arr,int hourly){
        long long totalhrs = 0;
        int n = arr.size();
        for(int i = 0 ; i < n ; i++){
            totalhrs += (long long)ceil((double)arr[i] / (double)hourly);
        }
        return totalhrs;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1, high = findmaxEle(piles);

        while(low <= high){
            int mid = low +(high-low)/2;
            long long totalH = findtotalhrs(piles,mid);   // here mid is the number of bananas koko can eat per hour....so at first he can eat 6..then 3 ...like that.
            if(totalH <= h){
                high = mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};

int main(){
    /*
        Example 1:
            Input: piles = [3,6,7,11], h = 8
            Output: 4

        Example 2:
            Input: piles = [30,11,23,4,20], h = 5
            Output: 30

        Example 3:
            Input: piles = [30,11,23,4,20], h = 6
            Output: 23
    */

    return 0;
}