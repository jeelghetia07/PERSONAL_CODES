#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class solution{
public:
    void merge(vector<int>& arr,int low,int mid,int high){
        vector<int> temp;
        int left = low , right = mid+1;
        while(left <= mid && right <= high){
            if(arr[left] <= arr[right]){
                temp.push_back(arr[left++]);
            }
            else{
                temp.push_back(arr[right++]);
            }
        }
        while(left <= mid){
            temp.push_back(arr[left++]);
        }
        while(right <= high){
            temp.push_back(arr[right++]);
        }
        // for(int i = low ; i < temp.size() ; i++){
        //     arr[i] = temp[i-low];
        // }
        int index = 0;
        while(low <= high){
            arr[low++] = temp[index++];
        }
    }
    void sortArray(vector<int>& arr,int low,int high){
        if(low >= high) return ;
        int mid = (low+high)/2;
        
        sortArray(arr,low,mid);
        sortArray(arr,mid+1,high);
        merge(arr,low,mid,high);
    
    }
};

int main(){
    vector<int> arr = {3,2,4,1,5,21,7,0};
    solution s;
    int n = arr.size();
    int low = 0 , high = n-1;
    for(int i : arr){
        cout << i << " ";
    }
    s.sortArray(arr,low,high);
    cout << endl;
    for(int i : arr){
        cout << i << " ";
    }

}