#include<bits/stdc++.h>
using namespace std;

/*      LC = 321
    You are given two integer arrays nums1 and nums2 of lengths m and n respectively. nums1 and nums2 represent the digits of two numbers. You are also given an integer k.

    Create the maximum number of length k <= m + n from digits of the two numbers. 
    This is the main line ---->  "The relative order of the digits from the same array must be preserved.""

    Return an array of the k digits representing the answer.
*/

class Solution {
public:

    // Compare remaining part of a and b
    bool greater(vector<int>& a, int i, vector<int>& b, int j) {
        while(i < a.size() && j < b.size()) {

            if(a[i] > b[j])
                return true;

            if(a[i] < b[j])
                return false;

            i++;
            j++;
        }

        return i < a.size();
    }


    vector<int> merge(vector<int>& v1, vector<int>& v2) {

        vector<int> ans;

        int i = 0;
        int j = 0;

        while(i < v1.size() && j < v2.size()) {

            if(v1[i] > v2[j]) {
                ans.push_back(v1[i]);
                i++;
            }
            else if(v1[i] < v2[j]) {
                ans.push_back(v2[j]);
                j++;
            }
            else {

                // Current elements are equal,
                // so compare the remaining sequences.
                if(greater(v1, i, v2, j)) {
                    ans.push_back(v1[i]);
                    i++;
                }
                else {
                    ans.push_back(v2[j]);
                    j++;
                }
            }
        }

        while(i < v1.size()) {
            ans.push_back(v1[i]);
            i++;
        }

        while(j < v2.size()) {
            ans.push_back(v2[j]);
            j++;
        }

        return ans;
    }


    vector<int> maxNumber(vector<int>& arr1, vector<int>& arr2, int k) {

        int n = arr1.size();
        int m = arr2.size();

        vector<int> maxi;

        for(int take1 = 0; take1 <= n; take1++) {
            int take2 = k - take1;

            // Both take1 and take2 must be valid.
            if(take2 < 0 || take2 > m)
                continue;

            int removed1 = n - take1;
            stack<int> s1;

            for(int x : arr1) {
                while(!s1.empty() && x > s1.top() && removed1 > 0) {
                    s1.pop();
                    removed1--;
                }
                s1.push(x);
            }

            // If removals are still left,
            // remove elements from the end.
            while(removed1 > 0) {
                s1.pop();
                removed1--;
            }

            vector<int> v1(s1.size());
            for(int i = s1.size() - 1; i >= 0; i--) {
                v1[i] = s1.top();
                s1.pop();
            }

            int removed2 = m - take2;
            stack<int> s2;

            for(int x : arr2) {
                while(!s2.empty() && x > s2.top() && removed2 > 0) {
                    s2.pop();
                    removed2--;
                }
                s2.push(x);
            }

            // Remove leftover elements from the end.
            while(removed2 > 0) {
                s2.pop();
                removed2--;
            }

            // Convert stack into vector in original order.
            vector<int> v2(s2.size());

            for(int i = s2.size() - 1; i >= 0; i--) {
                v2[i] = s2.top();
                s2.pop();
            }

            vector<int> candidate = merge(v1, v2);

            // Compare vectors lexicographically using our
            // own greater() function.
            if(maxi.empty() || greater(candidate, 0, maxi, 0)) {
                maxi = candidate;
            }
        }

        return maxi;
    }
};

int main(){
    /*
        Example 1:

        Input: nums1 = [3,4,6,5], nums2 = [9,1,2,5,8,3], k = 5
        Output: [9,8,6,5,3]


        Example 2:

        Input: nums1 = [6,7], nums2 = [6,0,4], k = 5
        Output: [6,7,6,0,4]

        
        Example 3:

        Input: nums1 = [3,9], nums2 = [8,9], k = 3
        Output: [9,8,9]
        

        Constraints:

        m == nums1.length
        n == nums2.length
        1 <= m, n <= 500
        0 <= nums1[i], nums2[i] <= 9
        1 <= k <= m + n
        nums1 and nums2 do not have leading zeros.
    */

    return 0;
}