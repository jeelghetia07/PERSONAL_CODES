#include<bits/stdc++.h>
using namespace std;

/*      LC = 1235       (hard)
    We have n jobs, where every job is scheduled to be done from startTime[i] to endTime[i], obtaining a profit of profit[i].

    You're given the startTime, endTime and profit arrays, return the maximum profit you can take such that there are no two jobs in the subset with overlapping time range.

    If you choose a job that ends at time X you will be able to start another job that starts at time X.
*/

class Solution {
public:

                        // MEMOIZATION APPROACH

    // int func(int ind, vector<vector<int>>& jobs, vector<int>& starts, vector<int>& dp){
    //     if(ind >= jobs.size()){
    //         return 0;
    //     }

    //     if(dp[ind] != -1) return dp[ind];

    //     int start = jobs[ind][0];
    //     int end = jobs[ind][1];
    //     int profit = jobs[ind][2];

    //     int notpick = 0 + func(ind+1, jobs, starts, dp);
    //     int pick = INT_MIN;
    //     int nextValidJob = lower_bound(starts.begin(), starts.end(), end) - starts.begin();
    //     // int nextValidJob = ind+1;        
    //     // while(nextValidJob < jobs.size() && jobs[nextValidJob][0] < end){            // this takes a O(n) TC so we better use the binary search.
    //     //     nextValidJob++;
    //     // }
    //     pick = profit + func(nextValidJob, jobs,starts, dp);
        

    //     return dp[ind] = max(pick, notpick);
    // }

    // int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
    //     int n = profit.size();
    //     vector<vector<int>> jobs;

    //     for(int i = 0 ; i < n ; i++){
    //         jobs.push_back({startTime[i], endTime[i], profit[i]});
    //     }
    //     sort(jobs.begin(), jobs.end());

    //     vector<int> starts;
    //     for(auto &job : jobs){
    //         starts.push_back(job[0]);       // this array simply stores the start time....so that in future we can find the compatible job in logn time rather than O(n).
    //     }

    //     vector<int> dp(n, -1);

    //     return func(0, jobs, starts, dp);
    // }



                // TABULATION APPROACH


    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit){
        int n = profit.size();
        vector<vector<int>> jobs;

        for(int i = 0 ; i < n ; i++){
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }
        sort(jobs.begin(), jobs.end());

        vector<int> starts;
        for(auto &job : jobs){
            starts.push_back(job[0]);       // this array simply stores the start time....so that in future we can find the compatible job in logn time rather than O(n).
        }

        vector<int> dp(n+1, 0);

        for(int ind = n-1 ; ind >= 0 ; ind--){
            int start = jobs[ind][0];
            int end = jobs[ind][1];
            int profit = jobs[ind][2];

            int notpick = 0 + dp[ind+1];
            int pick = INT_MIN;
            int nextValidJob = lower_bound(starts.begin(), starts.end(), end) - starts.begin();
            // int nextValidJob = ind+1;        
            // while(nextValidJob < jobs.size() && jobs[nextValidJob][0] < end){            // this takes a O(n) TC so we better use the binary search.
            //     nextValidJob++;
            // }
            pick = profit + dp[nextValidJob];
            

            dp[ind] = max(pick, notpick);
        }
        return dp[0];
    }
};

int main(){
    vector<int> startTime = {1,2,3,3}, endTime = {3,4,5,6}, profit = {50,10,4,70};      // ans is 120
    vector<int> startTime1 = {1,2,3,4,6}, endTime1 = {3,5,10,6,9},  profit1 = {20,20,100,70,60};        // ans is 150

    return 0;
}