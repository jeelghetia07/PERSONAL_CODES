#include<bits/stdc++.h>
using namespace std;

/*      LC = 50
    Implement pow(x, n), which calculates x raised to the power n (i.e., xn).
*/

using ll = long long;
class Solution {
public:
    double myPow(double x, int n) {     // completes in O(logn) TC
        ll m = n;           // using the ll because...in the case on INT_MIN....it will overflow....
        if(m < 0){
            m = -1*m;
        }
        double ans = 1;

        while(m > 0){
            if(m % 2 == 1){
                ans = ans * x;
                m = m-1;
            }
            else{
                m = m/2;
                x = x*x;
            }
        }

        if(n < 0) return 1.0/ans;
        return ans;
    }
};

int main(){
    double x = 2;
    int n = 11;
    Solution obj;

    double ans = obj.myPow(x,n);
    cout << "The ans is : " << ans;

    return 0;
}