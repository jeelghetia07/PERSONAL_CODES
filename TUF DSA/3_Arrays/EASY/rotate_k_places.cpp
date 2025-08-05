#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Rotate{
public:
    void rotate_k_step(vector<int>& arr , int k){
        int n = arr.size();
        k = k % n;
        reverse(arr,0,n-1);
        reverse(arr,0,k-1);
        reverse(arr,k,n-1);
    }
    void reverse(vector<int>& arr,int srt, int end){
        int left = srt , right = end;
        while(left <= right){
            swap(arr[left],arr[right]);
            left++,right--;
        }
    }
};

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    int k;
    cin >> k;
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }
    Rotate r1;
    r1.rotate_k_step(arr,k);
    for(int i = 0 ; i < n ; i++){
        cout << arr[i] << " ";
    }
}