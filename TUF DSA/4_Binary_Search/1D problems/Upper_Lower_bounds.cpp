#include<bits/stdc++.h>
using namespace std;

int LowerBound(vector<int>& arr, int n, int x){     // the arr[ind] > x
    int low = 0, high = n-1;
    int ans = n;

    while(low <= high){
        int mid = (low + high)/2;
        if(arr[mid] >= x){
            ans = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return ans;
}

int UpperBound(vector<int>& arr, int n, int x){     // the arr[ind] >= x
    int low = 0, high = n-1;
    int ans = n;

    while(low <= high){
        int mid = (low + high)/2;
        if(arr[mid] > x){
            ans = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {1,2,3,3,5,8,8,10,10,11};
    int n = arr.size();

    cout << "The Lower bound : " << LowerBound(arr, n, 9) << endl;
    cout << "The Upper bound : " << UpperBound(arr, n, 6) << endl;

    // this is the shortcut for CP.

    int x = 9;
    int lb = lower_bound(arr.begin(), arr.end(),x)-arr.begin();
    cout << lb;
}