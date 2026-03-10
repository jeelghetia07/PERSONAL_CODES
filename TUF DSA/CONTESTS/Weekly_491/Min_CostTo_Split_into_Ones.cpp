#include<bits/stdc++.h>
using namespace std;

/*      LC = 
    You are given an integer n.

    In one operation, you may split an integer x into two positive integers a and b such that a + b = x.

    The cost of this operation is a * b.

    Return an integer denoting the minimum total cost required to split the integer n into n ones.
*/

int func(int secNum){
    if(secNum == 1) return 1;
    
    int cost = 1 * secNum;
    return cost + func(secNum-1);
}
int minCost(int n) {
    if(n == 1) return 0;
    int secNum = n-1;

    int totalCost = 0;
    totalCost += func(secNum);      // the mini num cost after spliting will always be with 1 * n-1...
    return totalCost;
}

int main(){
    int n1 = 3, n2 = 5, n3 = 8;
    
    return 0;
}