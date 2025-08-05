#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Bubble{
public: 
    void bubble_sort(int arr[], int n){
        for(int i = n-1 ; i >= 0 ; i--){   //starts from index of last element.
            int didswap = 0;
            for(int j = 0 ; j <= i-1 ; j++){   // goes from 0 to the n-2 element..so that when checked...n-2 and n-1 are compared at the last.
                if(arr[j] > arr[j+1]){
                    swap(arr[j],arr[j+1]);
                    didswap = 1;
                }
            }
            if(didswap == 0){
                break;
            }
        }
    }
};

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }
    Bubble b;
    b.bubble_sort(arr,n);
    for(int i = 0 ; i < n ; i++){
        cout << arr[i] << " ";
    }
    return 0;
}