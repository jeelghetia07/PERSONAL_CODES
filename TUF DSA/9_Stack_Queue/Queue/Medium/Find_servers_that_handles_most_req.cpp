#include<bits/stdc++.h>
using namespace std;

/*      LC = 1606
    You have k servers numbered from 0 to k-1 that are being used to handle multiple requests simultaneously. Each server has infinite computational capacity but cannot handle more than one request at a time. The requests are assigned to servers according to a specific algorithm:

    The ith (0-indexed) request arrives.
    If all servers are busy, the request is dropped (not handled at all).
    If the (i % k)th server is available, assign the request to that server.
    Otherwise, assign the request to the next available server (wrapping around the list of servers and starting from 0 if necessary). For example, if the ith server is busy, try to assign the request to the (i+1)th server, then the (i+2)th server, and so on.
    You are given a strictly increasing array arrival of positive integers, where arrival[i] represents the arrival time of the ith request, and another array load, where load[i] represents the load of the ith request (the time it takes to complete). Your goal is to find the busiest server(s). A server is considered busiest if it handled the most number of requests successfully among all the servers.

    Return a list containing the IDs (0-indexed) of the busiest server(s). You may return the IDs in any order.
*/

class Solution {
    // TC = O(k*logk) + O(a*logk) = O((k+a)*logk).....SC = O(k).
public:
    int findServer(int ser, set<int> &available, int k){
        // if (i % k)th server is free, then assign it to the server.
        int target = ser % k;

        auto it = available.lower_bound(target);

        // Find the next available server >= target.
        if(it != available.end()){
            int server = *it;
            available.erase(it);
            return (server);
        }

        // Wrap around to the first available server.
        if(!available.empty()){
            int server = *available.begin();
            available.erase(available.begin());
            return server;
        }
        
        // No server
        return -1;
    }
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        int a = arrival.size();
        int l = load.size();

        // a min heap that stores the busy servers acc to their freetime.
        // {freetime, ser_id};
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > busy;

        // for finding available servers in O(1) efficiently.
        set<int> available;

        // counting the req served by each server.
        vector<int> freq(k, 0);

        for(int i = 0 ; i < k ; i++){
            available.insert(i);
        }

        int curr_time = 0;

        for(int i = 0 ; i < a ; i++){
            curr_time = max(curr_time, arrival[i]);

            // Free the servers which have completed their tasks.
            while(!busy.empty() && busy.top().first <= curr_time){
                auto it = busy.top();
                busy.pop();

                available.insert(it.second);
            }
            
            // find the best free server....read how we take the next server....its like consistent hashing.
            int free_server_id = findServer(i, available, k);
            if(free_server_id == -1) continue;

            busy.push({curr_time + load[i], free_server_id});
            freq[free_server_id]++;
        }

        int max_req = *max_element(freq.begin(), freq.end());

        vector<int> ans;

        for(int i = 0 ; i < k ; i++){
            if(freq[i] == max_req) ans.push_back(i);
        }

        return ans;
    }
};



/*
    Understand lower_bound() here

    Suppose:

    available = {0, 1, 3, 5, 7};
    target = 4;

    available.lower_bound(4) returns an iterator pointing to 5.

    If: target = 8;
    It returns available.end(), so we wrap around and select 0.
*/

int main(){
    /*
        Example 1:

        Input: k = 3, arrival = [1,2,3,4,5], load = [5,2,3,3,3] 
        Output: [1] 
        Explanation: 
        All of the servers start out available.
        The first 3 requests are handled by the first 3 servers in order.
        Request 3 comes in. Server 0 is busy, so it's assigned to the next available server, which is 1.
        Request 4 comes in. It cannot be handled since all servers are busy, so it is dropped.
        Servers 0 and 2 handled one request each, while server 1 handled two requests. Hence server 1 is the busiest server.


        Example 2:

        Input: k = 3, arrival = [1,2,3,4], load = [1,2,1,2]
        Output: [0]
        Explanation: 
        The first 3 requests are handled by first 3 servers.
        Request 3 comes in. It is handled by server 0 since the server is available.
        Server 0 handled two requests, while servers 1 and 2 handled one request each. Hence server 0 is the busiest server.

        
        Example 3:

        Input: k = 3, arrival = [1,2,3], load = [10,12,11]
        Output: [0,1,2]
        Explanation: Each server handles a single request, so they are all considered the busiest.
        

        Constraints:

        1 <= k <= 105
        1 <= arrival.length, load.length <= 105
        arrival.length == load.length
        1 <= arrival[i], load[i] <= 109
        arrival is strictly increasing.
    */

    return 0;
}