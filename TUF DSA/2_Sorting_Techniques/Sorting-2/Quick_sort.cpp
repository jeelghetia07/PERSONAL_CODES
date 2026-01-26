#include<bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int low, int high){
    int pivot = arr[low];
    int i = low, j = high;
    while(i < j){
        while(arr[i] <= pivot && i <= high-1) i++;
        while(arr[j] > pivot && j >= low+1) j--;
        if(i < j){
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[low], arr[j]);
    return j;
}

void qs(vector<int>& arr, int low, int high){
    if(low < high){
        int pIdx = partition(arr, low, high);
        qs(arr, low, pIdx-1);
        qs(arr, pIdx+1, high);
    }
}

vector<int> quickSort(vector<int>& arr){
    int n = arr.size();
    qs(arr, 0, n-1);
    return arr;
}

int main(){
    vector<int> arr = {4,6,7,2,8,1,3};
    vector<int> ans = quickSort(arr);

    for(int i = 0 ; i < ans.size() ; i++){
        cout << ans[i] << " ";
    }
    return 0;
}