#include<bits/stdc++.h>
using namespace std;

/*      LC = 2281
    As the ruler of a kingdom, you have an army of wizards at your command.

    You are given a 0-indexed integer array strength, where strength[i] denotes the strength of the ith wizard. For a contiguous group of wizards (i.e. the wizards' strengths form a subarray of strength), the total strength is defined as the product of the following two values:

    The strength of the weakest wizard in the group.
    The total of all the individual strengths of the wizards in the group.
    Return the sum of the total strengths of all contiguous groups of wizards. Since the answer may be very large, return it modulo 109 + 7.

    A subarray is a contiguous non-empty sequence of elements within an array.
*/

using ll = long long;
class Solution {
    vector<int> pse, nse;
public:
    const ll mod = 1e9+7;
    void findBoth_PSE_NSE(vector<int>& arr){
        int n = arr.size();
        pse.resize(n);
        nse.resize(n);

        stack<int> st;

        for(int i = 0 ; i < n ; i++){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                int ele = st.top();
                st.pop();
                nse[ele] = i;
                pse[ele] = (st.empty()) ? -1 : st.top();
            }
            st.push(i);
        }

        while(!st.empty()){
            int ele = st.top();
            st.pop();
            nse[ele] = n;
            pse[ele] = (st.empty()) ? -1 : st.top();
        }

        return;
    }
    int totalStrength(vector<int>& arr) {
        int n = arr.size();

        vector<ll> pref(n+1, 0);

        for(int i = 0 ; i < n ; i++){
            pref[i+1] = (pref[i] + arr[i]) % mod;
        }

        findBoth_PSE_NSE(arr);

        // Prefix sum of Prefix sum.
        vector<ll> pp(n + 2, 0);

        for (int i = 0; i <= n; i++) {
            pp[i + 1] = (pp[i] + pref[i]) % mod;
        }

        ll ans = 0;

        for(int i = 0 ; i < n ; i++){
            ll L = pse[i];
            ll R = nse[i];

            ll leftCnt = i-L;
            ll rightCnt = R-i;

            // Sum of pref[i+1].....pref[R].
            ll rightSum = (pp[R+1]-pp[i+1] + mod) % mod;

            // sum of pref[l+1].....pref[i].
            ll leftSum = (pp[i+1]-pp[L+1] + mod) % mod;

            ll total = (leftCnt*rightSum % mod - rightCnt*leftSum % mod + mod) % mod;

            ll contri = total * arr[i] % mod;

            ans = (ans + contri) % mod;
        }

        return ans;
    }
};

int main(){
    /*
        Example 1:

        Input: strength = [1,3,1,2]
        Output: 44
        Explanation: The following are all the contiguous groups of wizards:
        - [1] from [1,3,1,2] has a total strength of min([1]) * sum([1]) = 1 * 1 = 1
        - [3] from [1,3,1,2] has a total strength of min([3]) * sum([3]) = 3 * 3 = 9
        - [1] from [1,3,1,2] has a total strength of min([1]) * sum([1]) = 1 * 1 = 1
        - [2] from [1,3,1,2] has a total strength of min([2]) * sum([2]) = 2 * 2 = 4
        - [1,3] from [1,3,1,2] has a total strength of min([1,3]) * sum([1,3]) = 1 * 4 = 4
        - [3,1] from [1,3,1,2] has a total strength of min([3,1]) * sum([3,1]) = 1 * 4 = 4
        - [1,2] from [1,3,1,2] has a total strength of min([1,2]) * sum([1,2]) = 1 * 3 = 3
        - [1,3,1] from [1,3,1,2] has a total strength of min([1,3,1]) * sum([1,3,1]) = 1 * 5 = 5
        - [3,1,2] from [1,3,1,2] has a total strength of min([3,1,2]) * sum([3,1,2]) = 1 * 6 = 6
        - [1,3,1,2] from [1,3,1,2] has a total strength of min([1,3,1,2]) * sum([1,3,1,2]) = 1 * 7 = 7
        The sum of all the total strengths is 1 + 9 + 1 + 4 + 4 + 4 + 3 + 5 + 6 + 7 = 44.


        Example 2:

        Input: strength = [5,4,6]
        Output: 213
        Explanation: The following are all the contiguous groups of wizards: 
        - [5] from [5,4,6] has a total strength of min([5]) * sum([5]) = 5 * 5 = 25
        - [4] from [5,4,6] has a total strength of min([4]) * sum([4]) = 4 * 4 = 16
        - [6] from [5,4,6] has a total strength of min([6]) * sum([6]) = 6 * 6 = 36
        - [5,4] from [5,4,6] has a total strength of min([5,4]) * sum([5,4]) = 4 * 9 = 36
        - [4,6] from [5,4,6] has a total strength of min([4,6]) * sum([4,6]) = 4 * 10 = 40
        - [5,4,6] from [5,4,6] has a total strength of min([5,4,6]) * sum([5,4,6]) = 4 * 15 = 60
        The sum of all the total strengths is 25 + 16 + 36 + 36 + 40 + 60 = 213.
        

        Constraints:

        1 <= strength.length <= 105
        1 <= strength[i] <= 109
    */

    return 0;
}