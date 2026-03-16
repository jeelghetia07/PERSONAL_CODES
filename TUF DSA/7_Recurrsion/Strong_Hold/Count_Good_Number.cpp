#include<bits/stdc++.h>
using namespace std;

/*      LC = 1922
    A digit string is good if the digits (0-indexed) at even indices are even and the digits at odd indices are prime (2, 3, 5, or 7).

    For example, "2582" is good because the digits (2 and 8) at even positions are even and the digits (5 and 2) at odd positions are prime. However, "3245" is not good because 3 is at an even index but is not even.
    Given an integer n, return the total number of good digit strings of length n. Since the answer may be large, return it modulo 109 + 7.

    A digit string is a string consisting of digits 0 through 9 that may contain leading zeros.
*/

using ll = long long;
class Solution {
public:
    const int mod = 1e9 + 7;
    ll POW(ll x, ll n){
        ll res = 1;
        while(n > 0){
            if(n % 2 == 1){
                res = (res*x) % mod;
                n = n-1;
            }
            else{
                x = (x*x) % mod;
                n /= 2;
            }
        }
        return res;
    }

    // n = 4...we have 0 1 2 3....here there are 2 odd and 2 even index...that are calc by the formula.
    int countGoodNumbers(long long n) {
        ll even_pos = (n+1)/2;     // for any n sized number.....there are indexes 0 1 2 3 4....
        ll odd_pos = (n)/2;

        return (POW(5, even_pos) * POW(4, odd_pos)) % mod;
    }
};

int main(){
    ll n = 4;
    Solution obj;

    cout << obj.countGoodNumbers(n);

    return 0;
}