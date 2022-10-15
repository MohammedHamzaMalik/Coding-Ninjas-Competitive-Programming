/*
Boredom
Send Feedback
Gary is bored and wants to play an interesting but tough game . So he figured out a new board game called "destroy the neighbours" . In this game there are N integers on a board. In one move, he can pick any integer x from the board and then all the integers with value x+1 or x-1 gets destroyed .This move will give him x points.
He plays the game until the board becomes empty . But as he want show this game to his friend Steven, he wants to learn techniques to maximise the points to show off . Can you help Gary in finding out the maximum points he receive grab from the game ?
Input Format :
First line will contain T (number of test case), each test case is consists of two line.
Line 1: Integer N 
Line 2: A list of N integers
Output Format :
For each test case print maximum points, Gary can receive from the Game setup in a newline.
Constraints :
 1 <= T <= 50
 1 <= N <= 10^5
 1 <= A[i] <= 1000
Sample Input :
1
2
1 2
Sample Output :
2
Explanation:
Gary can receive a maximum of 2 points, by picking the integer 2.
*/



#include<bits/stdc++.h>
using namespace std;
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int solve(int n,vector<int>A)
{
    int *freq=new int[1005];
    int *dp=new int[1005];
    for(int i=0;i<1005;i++)
    {
        freq[i]=dp[i]=0;
    }
    for(int i=0;i<n;i++)
        freq[A[i]]++;
    
    dp[1]=freq[1];
    
    for(int i=2;i<=1000;i++)
    {
        dp[i]=max(dp[i-1],dp[i-2]+i*freq[i]);
    }
    int maximum=dp[1000];
    delete[] freq;
    delete[] dp;
    return maximum;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }
        int ans = solve(n,A);
        cout<<ans<<'\n';
    }    // write your code here
    return 0;
}
