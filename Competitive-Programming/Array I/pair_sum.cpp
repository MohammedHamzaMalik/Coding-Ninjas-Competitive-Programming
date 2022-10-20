// Problem Link: https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118820/offering/1381883

/*
Problem Statement:
You are given an array 'ARR' of size 'N' and an integer 'S'.
Your task is to return the list of all pairs of elements such 
that each sum of elements of each pair equals 'S'.

Input Format: 
The first line of input contains two space-separated integers
'N' and 'S', denoting the size of the input array and the value
of 'S'.
The second and last line of input contains 'N' space-separated 
integers, denoting the elements of the input array: ARR[i] where
0 <= i < 'N'.

Outut Format:
Print 'C' lines, each line contains one pair i.e. two space-separated
integers, where 'C' denotes the count of pairs having sum equals
to given value 'S'.

Constraints:
1 <= N <= 10^4
-10^5 <= ARR[i] <= 10^5
-2*10^5 <= S <= 2*10^5

Sample Input 1:
5 5
1 2 3 4 5
Sample Output 1:
1 4
2 3

Explaination For Sample Output 1:
Here, 1 + 4 = 5 and 2 + 3 = 5.
Hence the output will be, (1,4) , (2,3).

Sample Input 2:
5 0
2 -3 3 3 -2
Sample Output 2:
-3 3
-3 3
-2 2

*/


#include<bits/stdc++.h>
vector< vector<int> > pairSum(vector<int> &arr, int s){
    int n = arr.size();
    // Used to store result.
    vector< vector<int> > ans;
    sort(arr.begin(),arr.end());
    // Checking sum for every element.
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(arr[i] + arr[j] == s) {
                vector<int> pair(2);
                pair[0] = arr[i];
                pair[1] = arr[j];
                ans.push_back(pair);
            }
        }
    }
    return ans;
}