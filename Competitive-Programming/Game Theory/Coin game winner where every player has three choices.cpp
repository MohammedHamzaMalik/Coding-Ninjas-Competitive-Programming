/*
Coin game winner where every player has three choices
Send Feedback
Two players 'X' and 'Y', are playing a coin game. Initially, there are 'N' coins. Each player can pick exactly 'A' coins or 'B' coins or 1 coin. A player loses the game if he is not able to pick any coins. 'X' always starts the game, and each player plays optimally. You are supposed to find which player wins the coin game.
Input Format
The first line of input contains an integer ‘T’ representing the number of test cases.

The first line of each test case contains three integers: ‘N’ denoting the number of coins, integer ‘A’, integer ‘B’ denoting the number of coins each player can take in a turn.
Output Format:
For each test case, return one integer 0 or 1. return 1, if X wins the coin game, or return 0, if Y wins the coin game.
Note :
You do not need to print anything. It has already been taken care of. Just implement the given function.
Constraints:
1 <= T <= 10
1 <= N <= 10^5

Time limit: 1 sec
Sample Input 1:
2
5 3 4
4 2 3
Sample Output 1:
1
0
Explanation for Sample Input 1:
For the first test case, There are 5 coins, every player can pick 1 or 3 or 4 coins on his/her turn. X picks 3 coins in the first turn, now the remaining coins are 2, Y can only pick 1 coin. So, X wins by picking the last coin.

For the second test case, No, matter what coins X picks, Y always wins.
Sample Input 2:
2
8 2 4
9 3 4
Sample Output 2:
1
0
*/



#include<bits/stdc++.h>
int dp[100005];
int Solve(int n,int a,int b)
{
    if(n<=0)
       return 0;
    if(dp[n]!=-1)
         return dp[n];
    if(n>=a and !Solve(n-a,a,b))
         return dp[n]=1;
    if(n>=b and !Solve(n-b,a,b))
         return dp[n]=1;
    if(n>=1 and !Solve(n-1,a,b))
         return dp[n]=1;
    return dp[n]=0; 
}
int coinGameWinner(int n, int a, int b)
{
    memset(dp,-1,sizeof(dp));
  return Solve(n,a,b);
}
