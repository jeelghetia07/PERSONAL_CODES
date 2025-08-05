#include<iostream>
#include<vector>
#include<algorithm>
#include <unordered_set>
#include <set>
using namespace std;

class Fruits_2{
public:
    int Number_of_unplaced(vector<int>& fruits, vector<int>& baskets){
        int n = baskets.size();
        int unplaced_count = 0;
        unordered_set<int> BT;
        for(int i = 0 ; i < n ; i++){
            bool placed = false;
            for(int j = 0 ; j < n ; j++){
                if((fruits[i] <= baskets[j]) && (BT.find(j) == BT.end())){
                    BT.insert(j);
                    placed = true;
                    break;
                }
            }
            if(!placed) unplaced_count++;
        }
        return unplaced_count;
    }
};


int main(){
    int n;
    cin >> n;
    vector<int> baskets(n);
    vector<int> fruits(n);

    for(int i = 0 ; i < n ; i++){
        cin >> fruits[i];
    }
    for(int i = 0 ; i < n ; i++){
        cin >> baskets[i];
    }
    Fruits_2 f;
    cout << "the ans is : " << f.Number_of_unplaced(fruits,baskets) << "." << endl;

}