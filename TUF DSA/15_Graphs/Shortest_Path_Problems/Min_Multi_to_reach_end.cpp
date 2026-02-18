#include<bits/stdc++.h>
using namespace std;

/*
    Given start, end and an array arr of n numbers. At each step, start is multiplied with any number in the array and then mod operation with 100000 is done to get the new start.

    Your task is to find the minimum steps in which end can be achieved starting from start. If it is not possible to reach end, then return -1.
*/

int minimumMultiplications(vector<int>& arr, int start, int end) {
    if(start == end) return 0;
    
    vector<int> dist(100000, 1e9);
    dist[start] = 0;
    
    queue<pair<int, int>> q;
    q.push({start, 0});
    
    int mod = 100000;
    
    while(!q.empty()){
        int node = q.front().first;
        int steps = q.front().second;
        q.pop();
        
        for(auto it : arr){
            int ver = (node * it) % mod;
            
            if(steps + 1 < dist[ver]){
                dist[ver] = steps+1;
                if(ver == end) return steps+1;
                q.push({ver, dist[ver]});
            }
        }
    }
    return -1;
}

int main(){
    vector<int> arr = {3, 4, 65};
    int start = 7, end = 66175;

    cout << "the min multiplications req are : " << minimumMultiplications(arr, start, end);
    return 0;
}