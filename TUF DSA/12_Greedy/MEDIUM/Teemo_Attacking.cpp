#include<bits/stdc++.h>
using namespace std;

/*      LC = 495.
    Our hero Teemo is attacking an enemy Ashe with poison attacks! When Teemo attacks Ashe, Ashe gets poisoned for a exactly duration seconds. More formally, an attack at second t will mean Ashe is poisoned during the inclusive time interval [t, t + duration - 1]. If Teemo attacks again before the poison effect ends, the timer for it is reset, and the poison effect will end duration seconds after the new attack.

    You are given a non-decreasing integer array timeSeries, where timeSeries[i] denotes that Teemo attacks Ashe at second timeSeries[i], and an integer duration.

    Return the total number of seconds that Ashe is poisoned.
*/

int findPoisonedDuration(vector<int>& arr, int duration) {
    int n = arr.size();
    if(n == 0) return 0;

    int totalTimePoisoned = 0;

    for(int i = 0 ; i <= n-2 ; i++){
        int currAttack = arr[i], nextAttack = arr[i+1];

        int gap = nextAttack - currAttack;

        if(gap >= duration) totalTimePoisoned += duration;
        else{
            totalTimePoisoned += gap;
        }
    }
    totalTimePoisoned += duration;

    return totalTimePoisoned;
}

int main(){
    vector<int> arr = {1,4};
    int dur = 2;    // try with dur = 3, 4;
    
    cout << "The total sec : " << findPoisonedDuration(arr, dur);
    return 0;
}