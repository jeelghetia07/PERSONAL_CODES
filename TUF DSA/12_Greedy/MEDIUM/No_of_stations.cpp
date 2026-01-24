#include<bits/stdc++.h>
using namespace std;

// PROBLEM :  We are given two arrays that represent the arrival and departure times of trains that stop at the platform. We need to find the minimum number of platforms needed at the railway station so that no train has to wait.


                    // BRUTE FORCE APPROACH      TC = O(N2)

// int func(vector<int>& arr, vector<int>& dep){ 
//     int maxCNT = 0;
//     int n = arr.size();
//     for(int i = 0 ; i < n ; i++){
//         int cnt = 1;
//         for(int j = i+1 ; j < n ; j++){
//             if((arr[i] >= arr[j] && arr[i] <= dep[j]) ||(arr[j] >= arr[i] && arr[j] <= dep[i])) cnt++;
//             maxCNT = max(maxCNT, cnt);
//         }
//     }
//     return maxCNT;
// }


                    // OPTIMAL APPROACH.      TC = O(2nlogn) + O(2n)

int func(vector<int>& arr, vector<int>& dep){
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());

    int n = arr.size();

    int i = 0;      // for the arriving time array
    int j = 0;      // for the departing time array
    int cnt = 0, maxCNT = 0;

    while(i < n){
        if(arr[i] <= dep[j]){
            cnt++;
            i++;
        }
        else{
            cnt--;
            j++;
        }
        maxCNT = max(maxCNT, cnt);
    }
    return maxCNT;
}


int main(){
    vector<int> arr = {900, 945, 955, 1100, 1500, 1800};
    vector<int> dep = {920, 1200, 1130, 1150, 1900, 2000};

    cout << "The min stations required are : " << func(arr,dep);
    return 0;
}