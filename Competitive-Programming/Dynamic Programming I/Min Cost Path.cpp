/*
Min Cost Path
Send Feedback
Given an integer matrix of size m*n, you need to find out the value of minimum cost to reach from the cell (0, 0) to (m-1, n-1).
From a cell (i, j), you can move in three directions : (i+1, j), (i, j+1) and (i+1, j+1).
Cost of a path is defined as the sum of values of each cell through which path passes.
Input Format :
Line 1 : Two integers, m and n
Next m lines : n integers of each row (separated by space)
Output Format :
Minimum cost
Constraints :
1 <= m, n <= 100
Sample Input 1 :
3 4
3 4 1 2
2 1 8 9
4 7 8 1
Sample Output 1 :
13
*/



#include<bits/stdc++.h>
#include<climits>
#include<cmath>
// n - number of rows
/// m - number of columns

int solve(int **input,int n,int m,int i,int j,int **dp)
{
    if(i==n-1 and j==m-1)
    {
        return input[i][j];
    }
    if(i>=n || j>=m)
    {
        return INT_MAX;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    int x=solve(input,n,m,i,j+1,dp);
    int y=solve(input,n,m,i+1,j+1,dp);
    int z=solve(input,n,m,i+1,j,dp);
    
    /*
    calculating min of three
    */
    int ans=0;
    if(x<y and x<z)
    {
        ans=x+input[i][j];
    }
    else if(y<x and y<z)
    {
        ans=y+input[i][j];
    }
    else
    {
        ans=z+input[i][j];
    }
    
    dp[i][j]=ans;
    return ans;
}

int minCostPath(int **input, int n, int m) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    int **dp=new int *[n+1];
    for(int i=0;i<=n;i++)
    {
        dp[i]=new int[m+1];
        for(int j=0;j<=m;j++)
        {
            dp[i][j]=-1;
        }
    }
    return solve(input,n,m,0,0,dp);

}
