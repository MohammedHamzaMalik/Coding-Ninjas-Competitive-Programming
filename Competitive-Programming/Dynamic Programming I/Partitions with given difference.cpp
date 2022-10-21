/*  Given an array ARR', partition it into two subsets (possibly empty) such that their
union is thee original array. Let the sum of the elements of these two subsets be S1' and 'S2.
Given a difference 'D', count the number of partitions in which 'S1' is greater than
or equal to 'S2' and the difference between "S1 and S2' is equal to 'D'. Since the
answer may be too large, return it modulo 10^9 + 7.  

Input Format:
The first line contains a single integer T' denoting the number of test
cases, then each test case follows:
The first line of each test case contains two space- separated integers,
N and D, denoting the number of elements in the array and the desired difference.
The following line contains N integers denoting the space-separated integers "ARR.

Output Format:
For each test case, find the number of partitions satisfying the above
conditions modulo 10^9 + 7.
Output for each test case will be printed on a separate line.   */

/* Initially the total sum is calculated and stored. Then all possible sums of
   subsets are checked through recursion if any of them follow the constraint */

#include <bits/stdc++.h> 

#define mod 1000000007

int f(int ind,int s,int &sum,int &d,vector<int> &v,vector <vector<int>> &dp){
    if(ind==-1){
        if((s-(sum-s))==d) return 1;
        return 0;
    }
    if(dp[ind][s]!=-1) return dp[ind][s];
    int ans=0;
    ans=(ans+f(ind-1,s+v[ind],sum,d,v,dp))%mod;
    ans=(ans+f(ind-1,s,sum,d,v,dp))%mod;
    return dp[ind][s]=ans;
}

int countPartitions(int n, int d, vector<int> &arr) {
    int sum=0;
    for(int i=0 ; i<n ; i++){
        sum+=arr[i];
    }
    vector <vector<int>> dp(n+5,vector<int> (sum+5,-1));
    int ans=f(n-1,0,sum,d,arr,dp);
    return ans;
}