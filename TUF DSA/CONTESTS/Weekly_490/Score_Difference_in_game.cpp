#include<bits/stdc++.h>
using namespace std;

/*
    You are given an integer array nums, where nums[i] represents the points scored in the ith game.

    There are exactly two players. Initially, the first player is active and the second player is inactive.

    The following rules apply sequentially for each game i:

    If nums[i] is odd, the active and inactive players swap roles.
    In every 6th game (that is, game indices 5, 11, 17, ...), the active and inactive players swap roles.
    The active player plays the ith game and gains nums[i] points.
    Return the score difference, defined as the first player's total score minus the second player's total score.

*/

int scoreDifference(vector<int>& nums) {
    int n = nums.size();
    
    int score1 = 0;
    int score2 = 0;

    int active = 0;     // 0 -> active... 1 -> inactive

    for(int i = 0 ; i < n ; i++){
        if(nums[i] % 2 != 0){
            active ^= 1;
        }
        if(i % 6 == 5){
            active ^= 1;
        }

        if(active == 0) score1 += nums[i];
        else score2 += nums[i];
    }
    return score1-score2;
}

int main(){
    vector<int> nums = {2,4,2,1,2,1};   // ans is 4;
    cout << "The score diff is : " << scoreDifference(nums);
    return 0;
}

