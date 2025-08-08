#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;  

class Shift{
public:
    void zerotoend(vector<int>& arr){
        int n = arr.size();
        int nonzero = 0;
        int left = 0 , right = n-1;

        while(left <= right){
            if(arr[left] == 0) left++;
            else if(arr[left] != 0){
                arr[nonzero] = arr[left];
                left++, nonzero++;
            }
        }
        while(nonzero < n){
            arr[nonzero] = 0;
            nonzero++;
        }
    }
};

int main(){
    cout << "Enter the size of the array : ";
    int n;
    cin >> n;
    vector<int> arr(n);
    cout << "enter the elements of the array : ";
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }
    
    Shift s;
    s.zerotoend(arr);
    for(int i = 0 ; i < n ; i++){
        cout << arr[i] << " ";
    }
}