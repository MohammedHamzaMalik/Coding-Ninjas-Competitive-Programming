/*Problem Statement

Suggest Edit

You are given an array A of length N, where N is always an odd integer. There are (N-1)/2 elements in the array that occur twice and one element which occurs once. Your task is to find the only element that occurs once in the array.

Note: There are (N-1)/2+1 elements that are unique in the array. Input Format:
The first line of the input contains 'T' denoting the number of test cases.

The first line of each test case contains an integer 'N', representing the length of the array.

The second line of each test case contains N space-separated integers of the array A.

Output Format:
for each test case,print the only integer which occurs once in the array.
the output of each test case is printed in new line.
constraint:
1<=t<=50
    1<=N<=10000
-10^6>=a[i]<=10^6;
where T denotes the number of test case and n denote the length of array a[]
time limit:1sec
sample input:
2
7
7 3 5 4 5 3 4
9
5 6 9 6 1 9 1 5 3
sample output 1
7
3
    */
#include <bits/stdc++.h> 
int occursOnce(vector<int> &a, int n){
    int len=a.size();
    if(len==1){
        return a[0];
    }

	sort(a.begin(),a.end());
    for(int i=0;i<len;){
        if(i==len-1){
            return a[i];
        }
        if(a[i]==a[i+1]){
            i+=2;
        }else{
            return a[i];
        }
    }
    return 0;
}
