/*
Permutations of an array
Send Feedback
Given an array of distinct integers, return all permutations of the array.
Input format :
The first line of input contains a single interger T representing test cases.
First line of each test case contains an integer N denoting the total number of elements in the array.
Second line of each test case contains N space separataed integers denoting the elements of the array whose all possible permutations are to be calculated.
Output format :
For each test case, all possible permutations of the given array are printed.
Constraints :
1<= T <= 10
1 <= N <= 7
-10^9 <= ARR[i] <= 10^9
Time Limit: 1 sec
Sample Input 1 :
2
3
1 2 3 
1
1
Sample Output 1 :
1 2 3   1 3 2   2 1 3  2 3 1  3 1 2   3 2 1
1
Sample Input 2 :
2
2
0 1
3
4 5 6
Sample Output 2 :
0 1  1 0
4 5 6   4 6 5   5 4 6   5 6 4   6 4 5   6 5 4
Explanation to Sample Input 1:
In test case 1, For [0, 1], size of the array is 2. Therefore, number of permutations is 2! = 2. The possible 2 permutations are [[0, 1], [1, 0]].

In test case 2, For [4, 5, 6], the size of the array is 3. Therefore, the number of permutations is 3! =  6. The possible 6 permutations are [[4, 5, 6], [4, 6, 5], [5, 4, 6], [5, 6, 4], [6, 4, 5], [6, 5, 4]].
*/

#include<bits/stdc++.h>
using namespace std;

void permutation(vector<int> &v, vector<vector<int>> &ans, int size) {
    if (size == 1) {
        ans.push_back(v);
        return;
    }
    sort(v.begin(), v.end());

    while (true) {
        ans.push_back(v);
        int i = size - 1;
        while (v[i - 1] >= v[i]) {
            if (--i == 0) {
                return;
            }
        }
        int j = size - 1;
        while (j > i && v[j] <= v[i - 1]) {
            j--;
        }
        swap(v[i - 1], v[j]);
        reverse(v.begin() + i, v.end());
    }
}

vector<vector<int>> permutations(vector<int> &v, int size) {
    vector<vector<int>> ans;
    permutation(v, ans, size);
    return ans;
}
