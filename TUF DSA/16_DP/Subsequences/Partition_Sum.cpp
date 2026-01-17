#include<bits/stdc++.h>
using namespace std;

bool SubsetSumToK(int n, int k, vector<int>& arr){
    vector<bool> prev(k+1, 0), curr(k+1, 0);    // this tar+1...means create cols...0 to tar.so we do tar+1...
    prev[0] = curr[0] = true;
    if(arr[0] >= k) prev[arr[0]] = true;

    for(int ind = 1 ; ind < n ; ind++){
        for(int tar = 1 ; tar <= k ; tar++){
            bool nontake = prev[tar];
            bool take = false;
            if(tar >= arr[ind]) take = prev[tar-arr[ind]];
            curr[tar] = take | nontake;
        }
        prev = curr;
    }
    return prev[k];
}

bool PartitionSum(vector<int> &arr, int n){
    int totSum = 0;
    for(int i = 0 ; i < n ; i++){
        totSum += arr[i];
    }
    if(totSum % 2 != 0) return false;

    int target = totSum / 2;

    return (SubsetSumToK(n, target, arr));
}

int main(){
    vector<int> arr = {1, 5, 11, 5};
    int n = arr.size();
    bool ans = PartitionSum(arr, n);

    cout << "The ans is : " << ans;
    return 0;
}