#include<bits/stdc++.h>
using namespace std;

//  

int MaxProfit(vector<int>& prices){
    int buy = prices [0];
    int profit = 0;
    int n = prices.size();

    for(int i = 1 ; i < n ; i++){
        int cost = prices[i] - buy;
        profit = max(profit, cost);
        buy = min(buy, prices[i]);
    }
    return profit;
}

int main(){
    vector<int> prices = {7,1,5,3,6,4};
    cout << "The max profit is : " << MaxProfit(prices);
    return 0;
}