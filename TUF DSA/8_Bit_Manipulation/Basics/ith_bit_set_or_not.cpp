#include<bits/stdc++.h>
using namespace std;

int hammingWeight(int n) {
    int cnt = 0;

    while(n != 0){
        n = n & (n-1);
        cnt++;
    }
    return cnt;

    // while(n > 1){
    //     if(n&1) cnt++;
    //     n = (n >> 1);
    // }
    // if(n == 1) cnt++;
    // return cnt;
}

int main(){
    int n = 13, i = 2;  // in 13 check if the 2nd bit is set or not.
    if((n & (1 << i)) != 0) cout << "Yes its set.";
    else cout << "No" << endl;

    return 0;
}