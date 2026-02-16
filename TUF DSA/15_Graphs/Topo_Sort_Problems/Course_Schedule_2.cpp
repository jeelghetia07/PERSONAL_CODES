// Course_Schedule_2.cpp
#include<bits/stdc++.h>
using namespace std;

/*
    There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

    For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
    
    Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.
*/

vector<int> findOrder(int V, vector<vector<int>>& prerequisites) {
    vector<vector<int>> adj(V);
    for(auto &e : prerequisites){
        adj[e[1]].push_back(e[0]);
    }

    vector<int> indegree(V, 0);

    for(int i = 0 ; i < V ; i++){
        for(auto it : adj[i]){
            indegree[it]++;
        }
    }

    queue<int> q;
    vector<int> ans;

    for(int i = 0 ; i < V ; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    
    while(!q.empty()){
        int node = q.front();
        q.pop();
        ans.push_back(node);

        for(auto it : adj[node]){
            indegree[it]--;
            if(indegree[it] == 0){
                q.push(it);
            }
        }
    }
    if(ans.size() == V) return ans;
    return {};
}

int main(){
    int numCourses = 4;
    vector<vector<int>> prerequisites = {{1,0},{2,0},{3,1},{3,2}};

    vector<int> ans = findOrder(numCourses, prerequisites);

    for(auto it : ans){     // So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3].
        cout << it << " ";
    }
    return 0;
}