/*  You are given an array containing N non-negative integers. Your task is to
partition this array into two subsets such that the absolute difference between
subset sums is minimum.
You just need to find the minimum absolute difference considering any valid
division of the array elements.

Input Format:
The first line of input contains the integer T, denoting the number of
test cases.
The first line of each test case contains an integer N, denoting the
size of the array.
The second and the last line of each test case contains N space-
separated integers denoting the array elements.

Output Format:
For each test case, return the minimum possible absolute difference in a
separate line.  */

/* The solution is written through tabulation method and is time and 
   space optimized */

#include <bits/stdc++.h> 
int minSubsetSumDifference(vector<int>& arr, int n)
{
	int sum=0;
    for(int i=0 ; i<n ; i++){
        sum+=arr[i];
    }
    vector <int> prev(sum+1);
    prev[0]=1;
    for(int i=1 ; i<prev.size() ; i++){
        prev[i]=0;
    }
    vector <int> cur(sum+1);
    cur[0]=1;
    cur[arr[0]]=1;
    
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<=sum ; j++){
            int ans=0;
            if(j>=arr[i])
                ans=max(prev[j-arr[i]],ans);
            ans=max(prev[j],ans);
            cur[j]=ans;
        }
        prev=cur;
    }
    int fin=sum;
    for(int i=0 ; i<=sum ; i++){
        if(prev[i])
            fin=min(fin,abs(i-(sum-i)));
    }
    return fin;
}
