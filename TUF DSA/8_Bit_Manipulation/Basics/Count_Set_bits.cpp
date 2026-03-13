#include<bits/stdc++.h>
using namespace std;

/*      GFG
    count set bits in number
*/

int countSETBits(int n){
    int cnt = 0;

    while(n > 0){
        if(n & 1){
            cnt++;
        }
        n = n >> 1;
    }
    return cnt;
}

int main(){
    int n = 6;
    cout << countSETBits(n) << endl;

    return 0;
}