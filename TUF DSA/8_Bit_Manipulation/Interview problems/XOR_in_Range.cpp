#include<bits/stdc++.h>
using namespace std;

int func(int n){
    if(n % 4 == 1) return 1;
    else if(n % 4 == 2) return n+1;
    else if(n % 4 == 3) return 0;
    else{
        return n;
    }
}

int range(int l, int r){        // this means 4^5^6^7
    return func(l-1) ^ func(r);
}

int main(){
    int n1 = 5;
    int n2 = 7;

    cout << func(n1) << " " << func(n2) << endl;

    cout << "The range xor is : " << range(n1, n2);

    return 0;
}