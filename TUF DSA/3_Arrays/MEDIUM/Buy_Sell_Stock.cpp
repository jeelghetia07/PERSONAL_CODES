#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxProfit = 0;
        int buy = prices[0];

        for(int i = 1 ; i < n ; i++){
            if(prices[i] > buy){
                maxProfit = max(maxProfit , prices[i]-buy);
            }
            buy = min(buy, prices[i]);
        }
        return maxProfit;
    }
};