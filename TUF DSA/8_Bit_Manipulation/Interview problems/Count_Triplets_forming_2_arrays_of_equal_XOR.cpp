#include<bits/stdc++.h>
using namespace std;

/*      LC = 1442
    Given an array of integers arr.

    We want to select three indices i, j and k where (0 <= i < j <= k < arr.length).

    Let's define a and b as follows:

    a = arr[i] ^ arr[i + 1] ^ ... ^ arr[j - 1]
    b = arr[j] ^ arr[j + 1] ^ ... ^ arr[k]
    Note that ^ denotes the bitwise-xor operation.

    Return the number of triplets (i, j and k) Where a == b.
*/



// in the que...its said that a and b should be equal and that means the a^b == 0....so we iterate in the loop and find the range in which the xor of x^y=z and y^z = x....this will give the range.
int simpleMethod(int n, vector<int>& arr){      // TC = O(n2).
    int ans = 0;
    for(int i = 0 ; i < n ; i++){
        int tempXOR = 0;
        for(int k = i ; k < n ; k++){
            tempXOR ^= arr[k];
            if(tempXOR == 0){
                ans += (k-i);
            }
        }
    }
    return ans;
}

int countTriplets(vector<int>& arr) {
    int ans = 0, n = arr.size();
    return simpleMethod(n, arr);
}

int main(){
    vector<int> arr = {2,3,1,6,7};  // ans is 4
    return 0;
}