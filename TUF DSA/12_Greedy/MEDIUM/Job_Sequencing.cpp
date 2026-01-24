#include<bits/stdc++.h>
using namespace std;



struct Job{
    int id;
    int deadline;
    int profit;
};

bool comp(const Job &val1, const Job &val2){
    return val1.profit > val2.profit;
}

pair<int, int> JobScheduling(vector<Job> &jobs, int n){       // TC = O(nlogn) + O(N x maxDeadline).      SC = O(maxDeadline).
    sort(jobs.begin(), jobs.end(), comp);           // TC = O(nlogn).
    int totProfit = 0, cnt = 0, maxDeadline = -1;
    for(int i = 0 ; i < n ; i++){
        maxDeadline = max(maxDeadline , jobs[i].deadline);
    } 
    vector<int> hash(maxDeadline+1, -1);

    for(int i = 0 ; i < n ; i++){      // sees all the elements in the array.  TC = O(n)
        for(int j = jobs[i].deadline ; j > 0 ; j--){   // sees all the empty(before) deadline days for eg...dl = 6 then if 6 is full it goes to 5 and then it performs the job there.
            if(hash[j] == -1){                        // inner for loop TC = O(maxDeadline)
                cnt++;
                hash[j] = jobs[i].id;
                totProfit += jobs[i].profit;
                break;
            }
        }
    }
    return make_pair(cnt, totProfit);
}

int main(){
    vector<int> id = {1,2,3,4,5,6,7,8};
    vector<int> deadline = {4,5,6,6,4,2,2,2};
    vector<int> profit = {20,60,70,65,25,80,10,22};

    vector<Job> jobs;

    for(int i = 0 ; i < id.size() ; i++){
        jobs.push_back({id[i], deadline[i], profit[i]});
    }

    pair<int, int> ans = JobScheduling(jobs, id.size());
    cout << "The count : " << ans.first << " Total profit : " << ans.second << endl;
    return 0;
}