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


// CourseRegistration :- in the new course available.....when i press enable....the student id..email and name should be freezed just gender should be changable(selected)....
// Myprofile :- the option for uploading photo i want it....would it be enebled by backend??? how will it be stored in the DB???in the edit .....i want u to freeze the mail id , name , and student id.....becoz it cannot change by a student..... just  phn number and address editable...
// Timetable :- the week view is not showing all the lectures according to time.....its just showing Data Structures....ig there is a problem in the code...plz change it ....and finally...Library :- i want to see all the branch books rather than only for CS(or that will be done by the backend or DB)???and lastly...i want u to remove the attendance and faculty portion fully....form the whole system