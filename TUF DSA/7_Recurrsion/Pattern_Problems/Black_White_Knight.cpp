#include<bits/stdc++.h>
using namespace std;

/*      GFG
    Given the chessboard dimensions. Find out the number of ways we can place a black and a white Knight on this chessboard such that they cannot attack each other.
*/

// The que says that, for each cell i place a black knight, then how many safe places are there to keep the white knight, by that, we can find the attacking positions of the black knight, and subtract them from the total we get the safe places, and the +1 represents the cell where the black knight is standing.

using ll = long long;
const long long MOD = 1e9 + 7;

bool isValid(int nr, int nc, int n, int m){
    return (nr >= 0 && nr < n && nc >= 0 && nc < m);
}

long long numOfWays(int n, int m) {
    // write code here
    ll totalSafePos = 0, totalCells = n*m;
    
    int delrow[] = {-2, -1, 1, 2, 2, 1, -1, -2};
    int delcol[] = {-1, -2, -2, -1, 1, 2, 2, 1};
    
    for(int row = 0 ; row < n ; row++){
        for(int col = 0 ; col < m ; col++){
            ll attackingPos = 0;
            for(int i = 0 ; i < 8 ; i++){
                int nr = row + delrow[i];
                int nc = col + delcol[i];
                
                if(isValid(nr, nc, n, m)) attackingPos++;
            }
            
            totalSafePos += (totalCells - (attackingPos+1));
        }
    }
    return (totalSafePos) % MOD;
}

int main(){
    int n = 2, m = 3;
    ll ans = numOfWays(n,m);    // ans = 26
    cout << ans;
    return 0;
}