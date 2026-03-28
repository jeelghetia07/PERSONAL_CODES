#include<bits/stdc++.h>
using namespace std;

/*      GFG
    Given a binary string s of length n. We need to make this string a sequence of alternate characters by flipping some of the bits, our goal is to minimize the number of bits to be flipped.
*/

class Solution {
  public:
    int minFlips(string& s) {
        int n = s.size(), flips1 = 0, flips2 = 0;
        
        for(int i = 0 ; i < n ; i++){
            if(s[i] != (i%2 == 0 ? '0' : '1')) flips1++;        // for forming the patter 01010101....
            
            if(s[i] != (i%2 == 0 ? '1' : '0')) flips2++;        // for forming the patter 1010101....whcih ever returns the mini flips is the ans.
        }
        
        // try this que with 100 / 111
        return min(flips1, flips2);       // the min flips decide that which pattern would be easier to form....if flips1 > flips2...means to form 10101 would be easier rather than forming 010101.
    }
};


int main(){
    /*
        Input: s = "001"
        Output: 1
        Explanation: We can flip the 0th bit to 1 to have "101".


        Input: s = "0001010111" 
        Output: 2
        Explanation: We can flip the 1st and 8th bit. After this we have "0101010101"
    */

    return 0;
}