#include<bits/stdc++.h>
using namespace std;

vector<int> primeFactors(int n){
    vector<int> ans;

    for(int i = 2 ; i <= sqrt(n) ; i++){
        if(n % i == 0){
            ans.push_back(i);
            while(n % i == 0) n /= i;
        }
    }
    if(n != 1) ans.push_back(n);


    // for(int i = 2 ; i <= n ; i++){
    //     if(n % i == 0){
    //         ans.push_back(i);
    //         while(n % i == 0){
    //             n = n / i;
    //         }
    //     }
    // }
    return ans;
}

int main(){
    int n = 780;
    vector<int> ans = primeFactors(n);

    for(auto it : ans){
        cout << it << " ";
    }

    return 0;
}