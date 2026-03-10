#include<bits/stdc++.h>
using namespace std;

/*      LC = 
    You are given three integers l, r, and k.

    Consider all possible integers consisting of exactly k digits, where each digit is chosen independently from the integer range [l, r] (inclusive). If 0 is included in the range, leading zeros are allowed.

    Return an integer representing the sum of all such numbers.​​​​​​​ Since the answer may be very large, return it modulo 109 + 7.
*/

int sumOfNumbers(int l, int r, int k) {
        
}

int main(){
    int l1 = 1, r1 = 2, k1 = 2; // ans = 66
    //All numbers formed using k = 2 digits in the range [1, 2] are 11, 12, 21, 22.
    // The total sum is 11 + 12 + 21 + 22 = 66.


    int l2 = 0, r2 = 1, k2 = 3; // ans = 444
    //All numbers formed using k = 3 digits in the range [0, 1] are 000, 001, 010, 011, 100, 101, 110, 111​​​​​​​.
    // These numbers without leading zeros are 0, 1, 10, 11, 100, 101, 110, 111.
    // The total sum is 444.

    int l3 = 5, r3 = 5, k3= 10;     // ans = 555555520
    // 5555555555 is the only valid number consisting of k = 10 digits in the range [5, 5].
    // The total sum is 5555555555 % (109 + 7) = 555555520.

    return 0;
}