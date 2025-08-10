#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Insertion{
public:
    void insertion_sort(int arr[] , int n){
        for(int i = 0 ; i < n ; i++){
            int j = i;
            while(j > 0 && (arr[j-1] > arr[j])){    // this checks whether the element before is sorted or not...if not the swap..and j moves to the left..to check the before element and then its seen that...as all get sorted ...j becomes 0..and there for the loop breaks and i++.
                swap(arr[j],arr[j-1]);
                j--;
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
    Insertion I;
    I.insertion_sort(arr,n);
    for(int i = 0 ; i < n ; i++){
        cout << arr[i] << " ";
    }
    return 0;
}


// TC : O(n2) 