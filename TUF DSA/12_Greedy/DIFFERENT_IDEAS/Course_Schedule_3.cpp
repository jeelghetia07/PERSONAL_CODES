#include<bits/stdc++.h>
using namespace std;

/*      LC = 630
    There are n different online courses numbered from 1 to n. You are given an array courses where courses[i] = [durationi, lastDayi] indicate that the ith course should be taken continuously for durationi days and must be finished before or on lastDayi.

    You will start on the 1st day and you cannot take two or more courses simultaneously.

    Return the maximum number of courses that you can take.
*/

class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b){
        return a[1] < b[1];
    }
    int scheduleCourse(vector<vector<int>>& courses) {
        int n = courses.size();
        sort(courses.begin(), courses.end(), comp);

        int totalTimeWorking = 0;
        priority_queue<int> pq;

        for(auto course : courses){
            int duration = course[0];
            int deadline = course[1];

            if(totalTimeWorking + duration <= deadline){
                totalTimeWorking += duration;
                pq.push(duration);
            }
            else if(!pq.empty() && pq.top() >= duration){
                int prevTimeTakingWork = pq.top();
                pq.pop();

                totalTimeWorking = totalTimeWorking - prevTimeTakingWork + duration;
                pq.push(duration);
            }
        }

        return pq.size();
    }
};

int main(){
    /*
        courses = [[100,200],[200,1300],[1000,1250],[2000,3200]];      ans = 3;
        courses = [[5,5],[4,6],[2,6]];    ans = 2;
    */

    return 0;
}