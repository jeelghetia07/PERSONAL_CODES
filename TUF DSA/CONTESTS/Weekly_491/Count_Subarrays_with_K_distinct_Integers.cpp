#include<bits/stdc++.h>
using namespace std;

/*      LC = 3859
    You are given an integer array nums and two integers k and m.

    Return an integer denoting the count of subarrays of nums such that:

    The subarray contains exactly k distinct integers.
    Within the subarray, each distinct integer appears at least m times.
*/

// failing some test cases.

long long countSubarrays(vector<int>& nums, int k, int m) {
    int n = nums.size();
    long long ans = 0;
    int good = 0;         // this keeps track of the distinct digits.
    int left = 0;

    unordered_map<int, int> freq;

    for(int right = 0 ; right < n ; right++){
        freq[nums[right]]++;

        if(freq[nums[right]] == m) good++;

        while(freq.size() > k){

            if(freq[nums[left]] == m){
                good--;
            }

            freq[nums[left]]--;

            if(freq[nums[left]] == 0){
                freq.erase(nums[left]);
            }
            left++;
        }

        if(freq.size() == k && good == k){
            ans++;
        }
    }
    return ans;
}

int main(){
    vector<int> nums = {1,2,1,2,2};     // this has 2 subarray...[1,2,1,2]  and [1,2,1,2,2]....has 2 distinct number and freq...>= m.
    int k = 2, m = 2;

    vector<int> nums1 = {3,1,2,4};     // this has 3 subarray...[3,1]  and [1,2] and [2,4]....has 2 distinct number and freq...>= 1...here [3,4] is not allowed becoz it will make a subsequence.
    int k1 = 2, m1 = 1;

    return 0;
}