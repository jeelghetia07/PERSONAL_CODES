#include<bits/stdc++.h>
using namespace std;

/*      LC = 
    
*/

string convert2Binary(int n){
    string res = "";
    while(n > 0){       // TC = O(logn).    SC = O(logn)
        if(n%2 == 1) res += '1';
        else res += '0';

        n /= 2;
    }
    reverse(res.begin(), res.end());
    return res;
}

int BinaryToDecimal(string s){
    int len = s.size();
    int p2 = 1, num = 0;
    for(int i = len-1 ; i >= 0 ; i--){
        if(s[i] == '1'){
            num += (p2);
        }
        p2 *= 2;
    }
    return num;
}

int main(){
    int n = 13;
    cout << "The ans is " << convert2Binary(n) << endl;
    string s = "1101";
    cout << "The ans is " << BinaryToDecimal(s) << endl;

    return 0;
}