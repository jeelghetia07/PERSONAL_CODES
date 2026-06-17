#include<bits/stdc++.h>
using namespace std;

/*      LC = 2045
    A city is represented as a bi-directional connected graph with n vertices where each vertex is labeled from 1 to n (inclusive). The edges in the graph are represented as a 2D integer array edges, where each edges[i] = [ui, vi] denotes a bi-directional edge between vertex ui and vertex vi. Every vertex pair is connected by at most one edge, and no vertex has an edge to itself. The time taken to traverse any edge is time minutes.

    Each vertex has a traffic signal which changes its color from green to red and vice versa every change minutes. All signals change at the same time. You can enter a vertex at any time, but can leave a vertex only when the signal is green. You cannot wait at a vertex if the signal is green.

    The second minimum value is defined as the smallest value strictly larger than the minimum value.

    For example the second minimum value of [2, 3, 4] is 3, and the second minimum value of [2, 2, 4] is 4.
    Given n, edges, time, and change, return the second minimum time it will take to go from vertex 1 to vertex n.

    Notes:

    You can go through any vertex any number of times, including 1 and n.
    You can assume that when the journey starts, all signals have just turned green.
*/

class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> adj(n+1);

        for(auto &e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<vector<int>> dist(n+1, vector<int>(2, INT_MAX));
        dist[1][0] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 1});        // time 0, node 1.

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();

            int timeSoFar = it.first;
            int node = it.second;

            if(timeSoFar > dist[node][1]) continue;

            for(auto ver : adj[node]){
                int currentTime = timeSoFar;

                if((currentTime / change) % 2 == 1){        // total time after standing at the signal.
                    currentTime = (currentTime/change + 1) * change;
                }
                int newTime = currentTime + time;

                if(newTime < dist[ver][0]){
                    dist[ver][1] = dist[ver][0];
                    dist[ver][0] = newTime;

                    pq.push({newTime, ver});
                }
                else if(newTime > dist[ver][0] && newTime < dist[ver][1]){
                    dist[ver][1] = newTime;

                    pq.push({newTime, ver});
                }
            }
        }
        return dist[n][1];
    }
};

int main(){
    /*
        Example 1:
     
            Input: n = 5, edges = [[1,2],[1,3],[1,4],[3,4],[4,5]], time = 3, change = 5
            Output: 13
            Explanation:
            The figure on the left shows the given graph.
            The blue path in the figure on the right is the minimum time path.
            The time taken is:
            - Start at 1, time elapsed=0
            - 1 -> 4: 3 minutes, time elapsed=3
            - 4 -> 5: 3 minutes, time elapsed=6
            Hence the minimum time needed is 6 minutes.

            The red path shows the path to get the second minimum time.
            - Start at 1, time elapsed=0
            - 1 -> 3: 3 minutes, time elapsed=3
            - 3 -> 4: 3 minutes, time elapsed=6
            - Wait at 4 for 4 minutes, time elapsed=10
            - 4 -> 5: 3 minutes, time elapsed=13
            Hence the second minimum time is 13 minutes.      


        Example 2:


        Input: n = 2, edges = [[1,2]], time = 3, change = 2
        Output: 11
        Explanation:
        The minimum time path is 1 -> 2 with time = 3 minutes.
        The second minimum time path is 1 -> 2 -> 1 -> 2 with time = 11 minutes.
    */

    return 0;
}