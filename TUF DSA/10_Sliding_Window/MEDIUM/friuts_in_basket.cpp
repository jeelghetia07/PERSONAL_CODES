#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include <unordered_set>
#include <unordered_map>
using namespace std;


                                        //     OPTIMAL APPROACH O(n)     //


class Basket{
public:
    int friuts_inside(vector<int>& arr,int n){
        int left = 0 , right = 0 , maxLen = 0;
        unordered_map<int,int> mpp;
        while(right < n){          // this loop runs till the end.     having O(n).
            mpp[arr[right]]++;
            if(mpp.size() > 2){      // if there are more than 2 types of friuts...remove the before added friuts of the same type.
                while(mpp.size() > 2){                    // this at the worst case has O(n)....becoz it can have al friuts of the same type int the full vector.
                    mpp[arr[left]]--;
                    if(mpp[arr[left]] == 0){         // if all the same friuts are removed then...we can remove the type of friut from the map.
                        mpp.erase(arr[left]);            // this removes it.
                    }
                }
                left++;                             // came ahead of the trimmed part.
            }
            if(mpp.size() <= 2){
                maxLen = max(maxLen, right-left+1);         // this updates the quantity of friuts of 2 diff but same types of fruits. until a new fruit is added to the basket.
                right++;
            }
        }
        return maxLen;
    }
};





                                //  BRUTE FORCE APPROACH ( TC = O(n2) )    //


// class Basket{                    // same que as largest subarray of 2 diff elements.
// public:
//     int friuts_inside(vector<int>& arr,int n){
//         int Quantity = 0;                     // this is counting the types of elements...(maxLen of subarray.)
//         for(int i = 0 ; i < n ; i++){        // this loop creates subarrays.
//             unordered_set<int> st;
//             for(int j = i ; j < n ; j++){           // this loop extends the loop length and checks the set.
//                 st.emplace(arr[j]);                 // no element is repeated.
//                 if(st.size() <= 2){                 // should only contain 2 elements.
//                     Quantity = max(Quantity,j-i+1);    // these are the quantity of the types of friuts we are taking.
//                 }
//                 else{break;}
//             }
//         }
//         return Quantity;
//     }
// };

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }
    Basket b;
    cout << "Max fruits are : " << b.friuts_inside(arr,n) << endl;
    return 0;
}