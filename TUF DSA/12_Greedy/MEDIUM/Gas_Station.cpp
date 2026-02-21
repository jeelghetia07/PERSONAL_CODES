#include<bits/stdc++.h>
using namespace std;

/*  LC = 134
    There are n gas stations along a circular route, where the amount of gas at the ith station is gas[i].

    You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from the ith station to its next (i + 1)th station. You begin the journey with an empty tank at one of the gas stations.

    Given two integer arrays gas and cost, return the starting gas station's index if you can travel around the circuit once in the clockwise direction, otherwise return -1. If there exists a solution, it is guaranteed to be unique.
*/

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int n = gas.size();

    vector<int> net(n);

    for(int i = 0 ; i < n ; i++){
        net[i] = gas[i] - cost[i];
    }

    int tank = 0, total = 0, start = 0;

    for(int i = 0 ; i < n ; i++){
        total += net[i];
        tank += net[i];

        if(tank < 0){
            start = i+1;
            tank = 0;
        }
    }
    if(total < 0) return -1;
    return start;



    // for(int start = 0 ; start < n ; start++){        // this takes too much time.
    //     int tank = 0;
    //     int count = 0;

    //     while(count < n){
    //         int idx = (start + count) % n;
    //         tank += gas[idx];
    //         tank -= cost[idx];

    //         if(tank < 0) break;
    //         count++;
    //     }
    //     if(count == n) return start;
    // }
    // return -1;
}

int main(){
    vector<int> gas = {1,2,3,4,5}, cost = {3,4,5,1,2};  // ans = 3;
    int ans = canCompleteCircuit(gas,cost);

    cout << "The start index is : " << ans;
    return 0;
}