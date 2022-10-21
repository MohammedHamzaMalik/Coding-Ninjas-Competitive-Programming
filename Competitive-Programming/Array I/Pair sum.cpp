// https://www.codingninjas.com/codestudio/problems/pair-sum_697295?leftPanelTab=0

/*Problem Statement
You are given an integer array 'ARR' of size 'N and an integer 'S'. Your task is to return the list of all pairs of elements such that each sum of elements of each pair is equals to 'S'.

Each pair should be shorted
return the list of pair in non decreasing order of their first value. In case two pair have same first value the pair with smaller second value should come first.

Input Format:
the first line of input contains two space-separated integer 'N' and 'S', denoting the size of the input array and the value of 'S'.
The second and last line of input contains 'N' space-separeted integers. denoting the elements of the input array:ARR[i].


Output Format:
Print 'C' lines, each line contains i=one pair i.e. two space-seperated integers.

no need to print

Constrains:
1<=N<=10^4
-10^5<=ARR[i]<=10^5
-2*10^5<=S<=2*10^5
time limit 1sec


Sample Input 1:
5 5
1 2 3 4 5

Sample Output 1:
1 4
2 3

Explaination For Sample Output 1:
Here
      1 + 4 = 5
      2 + 3 = 5
Hence the output will be,(1,4) ,(2,3).



Sample Input 2:
5 0
2 -3 3 3 -2

Sample Output 2:
-3 3
-3 3
-2 2

*/

#include <bits/stdc++.h>
#include <bits/stdc++.h>
vector<vector<int>> pairSum(vector<int> &arr, int s)
{
    // Write your code here.
    sort(arr.begin(), arr.end());
    vector<vector<int>> output;
    int i = 0;
    int n = arr.size();
    vector<int> v;
    while (i < n - 1)
    {
        v.push_back(arr[i]);
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] == s)
            {
                v.push_back(arr[j]);
                output.push_back(v);
                v.pop_back();
            }
        }
        i++;
        v.pop_back();
    }
    return output;
}