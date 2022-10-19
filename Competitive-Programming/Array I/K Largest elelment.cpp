//https://www.codingninjas.com/codestudio/problems/k-largest-element_1062624?topList=top-array-coding-interview-questions&leftPanelTab=0
/* Problem Statement
YOu are given an unsorted array containing 'N' integers. You need to find 'K' largest element from the given array.Also ,you neeed to return the element in non-decreasing order.

Input Format:
The first line of the input contains an integer 'T' denoting the number of test cases.
the first line of each test case contains two space-separates positive integer 'N' and 'K' denoting number of elements present in the array and count of the largest elements you need to return.
the second line of each test case contains 'N' space-separated integers denoting the elements of the array.

Output Format:
The only line of output of each test case should contains 'K' largest element in the array in non-decreasing order.

no need to print anything.

Constraints:
1<=T<=100
1<=N<=10^4
1<=K<=N
-10^9<=ARR[i]<=10^9

where 'T' is the number of test cases, 'N' is the size of the array,'K'is the number of elements you need to return as answer and ARR[i] is the size of the array of elements.
 time limit: 1sec
 
 
 sample input 1:
 2
4 2
3 4 2 1
5 1
2 2 3 3 1

sample output 1:
3 4
3

explanation for sample input 1:
Test case 1:
If we sort the array then it will look like: [1, 2, 3, 4]. The 2 largest elements will be [3, 4].

Test case 2:
If we sort the array then it will look like: [1, 2, 2, 3, 3]. Then the largest element will be [3].

sample output 2:
2
5 5
0 10 1 2 2
6 2
-2 12 -1 1 20 1 


sample output 2:
0 1 2 2 10
12 20
*/

#include <bits/stdc++.h> 
vector<int> Klargest(vector<int> &a, int k, int n) {
    // Write your code here
    sort(a.begin(),a.end());
    vector<int> output;
    for(int i=0;i<k;i++){
        output.push_back(a[n-i-1]);
    }
    sort(output.begin(),output.end());
    return output;
}