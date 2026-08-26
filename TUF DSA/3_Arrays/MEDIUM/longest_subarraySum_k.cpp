#include<iostream>
#include<algorithm>
#include<vector>
#include <climits>
#include <unordered_map>
using namespace std;

        // simple SWP for the +ve and 0s , it wont work for the -ve numbers.

/*

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int func(vector<int>& arr, int k){
    int n = arr.size();
    vector<int> pref(n, 0);
    pref[0] = arr[0];

    for(int i = 1 ; i < n ; i++){
        pref[i] = pref[i-1] + arr[i];
    }

    int l = 0, r = 0;
    int sum = 0;
    int maxi = INT_MIN;

    while(r < n){
        sum += arr[r];

        if(sum > k){
            sum -= arr[l];
            l++;
        }
        if(sum == k)
            maxi = max(r-l+1, maxi);
        r++;
    }

    return maxi;
}

int main() {
    vector<int> arr = {1,2,3,1,0,0,0,4,2,3};

    int ans = func(arr, 6);
    cout << ans;

    return 0;
}
*/

class Two_Sum{
public:
    int longestSubarray(vector<int>& arr, int tar){           // we can use the two pointer approach but in case of +ves only.
        int n = arr.size();
        unordered_map<int,int> preSumMpp;
        int maxLen = 0;
        int sum = 0;
        for(int i = 0 ; i < n ; i++){
            sum += arr[i];
            if(sum == tar){
                maxLen = max(maxLen,i+1);
            }
            int rem = sum - tar;
            if(preSumMpp.find(rem) != preSumMpp.end()){       
                int len = i - preSumMpp[rem];
                maxLen = max(maxLen, len);
            }
            if(preSumMpp.find(sum) == preSumMpp.end()){         // in the case of 0...if the sum already exists then donot add it again.
                preSumMpp[sum] = i;
            }
        }
        return maxLen;



                        // BRUTE FORCE SOLUTION //


        // int len = 0;

        // for(int i = 0 ; i < n ; i++){
        //     for(int j = i ; j < n ; j++){
        //         int sum = 0;
        //         for(int k = i ; k <= j ; k++){
        //             sum += arr[k];
        //         }
        //         if(sum == tar){
        //         len = max(len,j-i+1);
        //         }
        //     }
        // }
        // return len;
    }
};

int main(){
    vector<int> arr = {1,2,3,1,1,1,2,4,2,3};
    int tar;
    cout << "Tell the target : "; 
    cin >> tar;
    Two_Sum s;
    int ans = s.longestSubarray(arr,tar);

    cout << "The max len of subarray is : " << ans << endl;
    return 0;
}