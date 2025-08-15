#include<iostream>
#include<algorithm>
#include<vector>
#include <climits>
#include <unordered_map>
using namespace std;

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