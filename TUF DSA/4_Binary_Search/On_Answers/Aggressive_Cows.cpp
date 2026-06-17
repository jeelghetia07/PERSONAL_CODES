#include<bits/stdc++.h>
using namespace std;

/*      LC = GFG
    You are given an array with unique elements of stalls[], which denote the positions of stalls. You are also given an integer k which denotes the number of aggressive cows. The task is to assign stalls to k cows such that the minimum distance between any two of them is the maximum possible.
*/

class Solution {
  public:
    bool canWePlace(int cows, vector<int>& stalls, int minDis){
        int cntCows = 1, lastPos = stalls[0];       // this means we placed 1 cow greedly already and now the pos of the last cow is the arr[0].
        
        for(int i = 1 ; i < stalls.size() ; i++){
            if(stalls[i] - lastPos >= minDis){
                cntCows++;
                lastPos = stalls[i];
            }
        }
        if(cntCows >= cows) return true;
        return false;
    }
    int aggressiveCows(vector<int> &stalls, int cows) {     // TC = O(nlogn) + (O(log(max-min))*O(n))
        // code here
        int n = stalls.size();
        
        sort(stalls.begin(), stalls.end());
        
        int low = 1, high = stalls[n-1] - stalls[0];
        
        while(low <= high){
            int minDis = (low + high)/2;
            
            if(canWePlace(cows, stalls, minDis)){
                low = minDis+1;
            }
            else{
                high = minDis-1;
            }
        }
        
        return high;
    }
};

int main(){
    /*
        Input: stalls[] = [1, 2, 4, 8, 9], k = 3
        Output: 3
        Explanation: The first cow can be placed at stalls[0], 
        the second cow can be placed at stalls[2] and 
        the third cow can be placed at stalls[3]. 
        The minimum distance between cows in this case is 3, which is the largest among all possible ways.

        Input: stalls[] = [10, 1, 2, 7, 5], k = 3
        Output: 4
        Explanation: The first cow can be placed at stalls[0],
        the second cow can be placed at stalls[1] and
        the third cow can be placed at stalls[4].
        The minimum distance between cows in this case is 4, which is the largest among all possible ways.

        Input: stalls[] = [2, 12, 11, 3, 26, 7], k = 5
        Output: 1
        Explanation: There are 6 stalls and only 5 cows, we try to place the cows such that the minimum distance between any two cows is as large as possible.
        The minimum distance between cows in this case is 1, which is the largest among all possible ways.
    */

    return 0;
}