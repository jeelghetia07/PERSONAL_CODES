#include<bits/stdc++.h>
using namespace std;

// PROBLEM : A line of N kids is standing there. The rating values listed in the integer array ratings are assigned to each kid. These kids are receiving candy according to the following criteria:There must be at least one candy for every child.Kids whose scores are higher than their neighbours receive more candies than their neighbours.Return the minimum number of candies needed to distribute among children.

// int func(vector<int>& rating){     // TC = O(3N)    SC = O(2N)
//     int n = rating.size();

//     vector<int> left(n), right(n);
//     left[0] = 1, right[n-1] = 1;

//     for(int i = 1 ; i < n ; i++){
//         if(rating[i] > rating[i-1]){
//             left[i] = left[i-1] + 1;
//         }
//         else{
//             left[i] = 1;
//         }
//     }
//     for(int i = n-2 ; i >= 0 ; i--){
//         if(rating[i] > rating[i+1]){
//             right[i] = right[i+1] + 1;
//         }
//         else{
//             right[i] = 1;
//         }
//     }

//     int sum = 0;
//     for(int i = 0 ; i < n ; i++){
//         sum += max(left[i], right[i]);
//     }
//     return sum;
// }

int func(vector<int>& rating){
    int n = rating.size();

    vector<int> left(n);
    left[0] = 1;

    for(int i = 1 ; i < n ; i++){
        if(rating[i] > rating[i-1]){
            left[i] = left[i-1] + 1;
        }
        else{
            left[i] = 1;
        }
    }
    int curr = 1, right = 1, sum = left[n-1];
    for(int i = n-2 ; i >= 0 ; i--){
        if(rating[i] > rating[i+1]){
            curr = right + 1;
            right = curr;
        }
        else{
            curr = 1;
            right = 1;
        }
        sum = sum + max(left[i], curr);
    }
    return sum;
}

int main(){
    vector<int> rating = {0,2,4,3,2,1,1,3,5,6,4,0,0};
    cout << "The sum is : " << func(rating);
    return 0;
}