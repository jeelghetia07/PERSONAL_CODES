#include<bits/stdc++.h>
using namespace std;

/*      LC = 2050
    You are given an integer n, which indicates that there are n courses labeled from 1 to n. You are also given a 2D integer array relations where relations[j] = [prevCoursej, nextCoursej] denotes that course prevCoursej has to be completed before course nextCoursej (prerequisite relationship). Furthermore, you are given a 0-indexed integer array time where time[i] denotes how many months it takes to complete the (i+1)th course.

    You must find the minimum number of months needed to complete all the courses following these rules:

    You may start taking a course at any time if the prerequisites are met.
    Any number of courses can be taken at the same time.
    Return the minimum number of months needed to complete all the courses.

    Note: The test cases are generated such that it is possible to complete every course (i.e., the graph is a directed acyclic graph).
*/

class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> adj(n+1);
        vector<int> indegree(n+1, 0);

        // created the graph, and the indegree too.
        for(auto it : relations){
            adj[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }

        // earliest completion time of course i among all the paths...early means not as per value...from all paths i have to match all the prerequisites and then update the value.
        vector<int> dp(n+1, 0);
        queue<int> q;

        for(int i = 1 ; i <= n ; i++){
            if(indegree[i] == 0){
                q.push(i);
                dp[i] = time[i-1];
            }
        }

        int ans = 0;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            // the last node having the highest indegree will have to final value updated.
            ans = max(ans, dp[node]);

            for(auto it : adj[node]){
                dp[it] = max(dp[it], dp[node] + time[it-1]);

                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        
        return ans;
    }
};

int main(){
    /*
        
    */

    return 0;
}