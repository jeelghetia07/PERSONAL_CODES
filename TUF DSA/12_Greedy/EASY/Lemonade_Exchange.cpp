#include<bits/stdc++.h>
using namespace std;

// PROBLEM :

bool func(vector<int>& bills){
    int five = 0, ten = 0;
    for(int i = 0 ; i < bills.size() ; i++){
        if(bills[i] == 5){
            five++;
        }
        else if(bills[i] == 10){
            if(five > 0){
                five--;
                ten++;
            }
            else return false;
        }
        else{
            if(ten > 0 && five > 0){
                five--;
                ten--;
            }
            else if(five >= 3){
                five -= 3;
            }
            else return false;
        }
    }
    return true;
}

int main(){
    vector<int> bills = {5,5,5,10,20};      // here we are given N = bills.size() lemonades (here 5 lemonade)...we have to sell them for 5 each.
    if(func(bills) == 1){
        cout << "Yes, Can sell all lemonades.";
    }
    else cout << "Cannot sell lemonades." ;

    return 0;
}