// Course_Schedule_1.cpp
#include<bits/stdc++.h>
using namespace std;

/*
    There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

    For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.

    Return true if you can finish all courses. Otherwise, return false.
*/

bool canFinish(int V, vector<vector<int>>& prerequisites) {
    vector<vector<int>> adj(V);
    for(auto &e : prerequisites){
        adj[e[1]].push_back(e[0]);      // according to the ques...read it....its said...to take course 0 we have to finish course 1...so we make a opposite directed edge.
    }

    vector<int> indegree(V, 0);

    for(int i = 0 ; i < V ; i++){
        for(auto it : adj[i]){
            indegree[it]++;
        }
    }

    queue<int> q;

    for(int i = 0 ; i < V ; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    int cnt = 0;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        cnt++; 

        for(auto it : adj[node]){
            indegree[it]--;
            if(indegree[it] == 0)q.push(it);
        }
    }

    if(cnt == V) return true;       // if cnt will be the total vertices...hence...there is no cycle in the graph...hence we can complete the courses.
    return false;
}

int main(){
    int numCourses = 2; 
    // vector<vector<int>> prerequisites = {{1,0},{0,1}};
    vector<vector<int>> prerequisites = {{1,0}};

    bool ans = canFinish(numCourses, prerequisites);
    if(ans) cout << "YES, can finish all courses.";
    else cout << "impossible";

    return 0;
}