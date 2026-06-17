#include<bits/stdc++.h>
using namespace std;

/*      LC = GFG
    Given an array arr[] of integers, where each element arr[i] represents the number of pages in the i-th book. You also have an integer k representing the number of students. The task is to allocate books to each student such that:

    Each student receives atleast one book.
    Each student is assigned a contiguous sequence of books.
    No book is assigned to more than one student.
    All books must be allocated.
    The objective is to minimize the maximum number of pages assigned to any student. In other words, out of all possible allocations, find the arrangement where the student who receives the most pages still has the smallest possible maximum.

    Note: If it is not possible to allocate books to all students, return -1.
*/

class Solution {
  public:
    int findStud(int minPg, vector<int>& arr, int students){
        int stu = 1, pages = 0;
        
        for(int i = 0 ; i < arr.size() ; i++){
            if(pages + arr[i] <= minPg){
                pages += arr[i];
            }
            else{
                stu++;
                pages = arr[i];
            }
        }
        
        return stu;
    }
    int findPages(vector<int> &arr, int Totalstudents) {
        int n = arr.size();
        
        if(Totalstudents > n) return -1;
        
        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);
        
        while(low <= high){
            int minPages = (low+high)/2;
            
            int stuAllocated = findStud(minPages, arr, Totalstudents);      // to find how many students are allocated pages.
            
            if(stuAllocated <= Totalstudents){      // if there are TStud = 5 and allocated are only 4 so we hvae to reduce the pages so all get pages.
                high = minPages-1;
            }
            else{
                low = minPages+1;
            }
        }
        return low;
    }
};

int main(){
    /*
        Input: arr[] = [12, 34, 67, 90], k = 2
        Output: 113
        Explanation: Allocation can be done in following ways:
        => [12] and [34, 67, 90] Maximum Pages = 191
        => [12, 34] and [67, 90] Maximum Pages = 157
        => [12, 34, 67] and [90] Maximum Pages = 113.
        The third combination has the minimum pages assigned to a student which is 113.


        Input: arr[] = [15, 17, 20], k = 5
        Output: -1
        Explanation: Since there are more students than total books, it's impossible to allocate a book to each student.
    */

    return 0;
}