#include<bits/stdc++.h>
using namespace std;



int main(){
    vector<vector<int>> grid = {{2, 1, 1}, 
                          {1, 1, 0}, 
                          {0, 1, 1}};

    int ans = orangesRottenTime(grid);
    cout << "The number of provinces are  : " << ans;
}