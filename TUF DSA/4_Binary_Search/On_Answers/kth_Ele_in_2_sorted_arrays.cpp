#include<bits/stdc++.h>
using namespace std;

/*      GFG
    
*/

class Solution {
  public:
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        // code here
        int n1 = a.size(), n2 = b.size();
        if(n1 > n2) return kthElement(b, a, k);
        
        int low = max(0, k-n2), high = min(k, n1);     // if the n1 == 6, then why will i pick 6 elements, i will better only pick k element
        int left = k;     // this is means the number of elements i have to take on the left side.
        int n = n1+n2;
        
        while(low <= high){
            int mid1 = (low+high) >> 1;
            int mid2 = left - mid1;
            
            int l1 = INT_MIN;
            int r1 = INT_MAX;
            int l2 = INT_MIN;
            int r2 = INT_MAX;
            
            if(mid1 < n1) r1 = a[mid1];
            if(mid2 < n2) r2 = b[mid2];
            
            if(mid1-1 >= 0) l1 = a[mid1-1];     // is this valid or  not, thats why we kept this if condition.
            if(mid2-1 >= 0) l2 = b[mid2-1];
            
            if(l1 <= r2 && l2 <= r1){
                return max(l1,l2);
            }
            else if(l1 > r2) high = mid1-1;
            else low = mid1+1;
        }
        
        return 0;
    }
};

int main(){
    /*
        Input: a[] = [2, 3, 6, 7, 9], b[] = [1, 4, 8, 10], k = 5
        Output: 6
        Explanation: The final combined sorted array would be [1, 2, 3, 4, 6, 7, 8, 9, 10]. The 5th element of this array is 6.
        Input: a[] = [1, 4, 8, 10, 12], b[] = [5, 7, 11, 15, 17], k = 6
        Output: 10
        Explanation: Combined sorted array is [1, 4, 5, 7, 8, 10, 11, 12, 15, 17]. The 6th element of this array is 10.
    */

    return 0;
}