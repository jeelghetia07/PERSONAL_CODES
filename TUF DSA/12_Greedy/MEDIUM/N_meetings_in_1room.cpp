#include<bits/stdc++.h>
using namespace std;

// PROBLEM : There is one meeting room in a firm. You are given two arrays, start and end each of size N. For an index ‘i’, start[i] denotes the starting time of the ith meeting while end[i] will denote the ending time of the ith meeting. Find the maximum number of meetings that can be accommodated if only one meeting can happen in the room at a particular time. Print the order in which these meetings will be performed

int maxMeetings(vector<int>& start, vector<int>& end){
    int n = start.size();

    vector<pair<int, int>> meetings;

    for(int i = 0 ; i < n ; i++){
        meetings.push_back({end[i], start[i]});
    }

    sort(meetings.begin(), meetings.end());

    int cnt = 1;                            // we picked up first meeting.
    int freetime = meetings[0].first;     // first meeting's end time.

    for(int i = 0 ; i < n ; i++){
        if(meetings[i].second > freetime){
            cnt++;
            freetime = meetings[i].first;
        }
    }
    return cnt;
}

int main(){
    vector<int> start = {0,3,1,5,5,8};
    vector<int> end   = {5,4,2,9,7,9};
    
    cout << maxMeetings(start, end);
    return 0;
}