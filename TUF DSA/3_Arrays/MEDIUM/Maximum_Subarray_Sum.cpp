#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;

class MAXIMUM_SUM{
public:
    int maxSumValue(vector<int>& arr){
        int n = arr.size();
        int sum = 0, maxi = INT_MIN;
        int srt , ansSrt, ansEnd;           // if asked to find the length or the pos of the maxsum then we can find with the help of these variables...but if not told,,...then no need.

        for(int i = 0 ; i < n ; i++){
            sum += arr[i];
            if(sum == 0) srt = i;            // this shows the starting index of the sum.
            if(sum > maxi){                  
                maxi = sum;
                ansSrt= srt;
                ansEnd = i;
            }
            if(sum < 0) sum = 0;
        }
        return maxi;
    }
};

int main(){
    vector<int> arr = {-2,1,-3,4,-1,2,1,-5,4};
    MAXIMUM_SUM m;
    int ans = m.maxSumValue(arr);
    cout << "The max sum in the array is : " << ans << endl;
    return 0;
}