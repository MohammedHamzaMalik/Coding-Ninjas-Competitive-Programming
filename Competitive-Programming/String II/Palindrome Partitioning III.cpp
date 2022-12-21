/*
Palindrome Partitioning III
Send Feedback
On Valentine’s Day, Alice and Bob planned to go on a dinner date, but Alice is still unsure about Bob, so she decided to give him a task. She gave him a string ‘S’ of length ‘N’ containing only lowercase English letters and an integer ‘K’ and told him that he could:
Change some characters of ‘S’ to other lowercase letters  (if required).

Divide ‘S’ into ‘K’ non-empty disjoint substrings such that each substring is a palindrome.
She asked Bob to find the minimum number of characters he needs to change to divide the given string in the required condition. Since Bob is busy preparing a perfect date for her, he called you to solve Alice’s challenge. Can you help Bob to impress her?
Input Format
The first line of input contains an integer 'T' representing the number of test cases.

The first line of each test case contains two space-separated integers, ‘N’ and ‘K’. Here ‘N’ denotes the length of the string, and ‘K’ is an integer given by Alice.

The next line contains a string ‘S’ of length ‘N’. Here ‘S’ is the string given by Alice to Bob. 
Output Format:
For each test case, print a single line containing a single integer denoting the minimum number of characters that Bob needs to change to divide ‘S’ into ‘K’ non-empty disjoint palindromic substrings.

The output of each test case will be printed in a separate line.
Note:
You do not need to print anything, it has already been taken care of. Just implement the given function.
Constraints:
1 <= T <= 5
1 <= N <= 50
1 <= K <= N
‘S’ contains only lowercase English letters.

Time limit: 1 sec.
Sample Input 1:
2
6 2
coding
6 6
ninjas
Sample Output 1:
2
0
Explanation For Sample Input 1:
Test Case 1 :  
The string given by Alice is “coding” and ‘K’ = 2
One possible way is to change ‘d’ to ‘c’ and ‘g’ to ‘i’, the resulting string will be “cocini”

Now we can divide the new string into 2 substrings “coc” and “ini”
So the minimum required change is 2.

Test Case 2 : 
The string given by Alice is “ninjas” and ‘K’ = 6

We can divide the string into 6 substrings of length 1.
So the minimum required change is 0.
Sample Input 2:
1
6 3
aabbcc
Sample Output 2:
0
*/



#include<bits/stdc++.h>

int dp[105][105];
   
int changes(int i , int j , string& s)
{
   int cnt = 0;
   while(i < j){
       cnt += (s[i++] != s[j--]);
   }
   return cnt;
}

int recur(int idx, int k, string &s)
{
   if(idx == s.size()){
       return (k == 0) ? 0 : 1e7;
   }

   if(k == 0){
       return 1e7;
   }

   if (dp[idx][k] != -1){
       return dp[idx][k];
   }

   int ans = INT_MAX;
   
   for (int i = idx ; i < s.size() ; i++)
   {
       ans = min(ans , changes(idx , i , s) + recur(i + 1, k - 1, s));
   }
   
   return dp[idx][k] = ans;
}

int paliPartitioning(string s, int k)
{
   if(k == s.size())
   {
       return 0;
   }
   
   memset(dp , -1 , sizeof(dp));
   
   return recur(0 , k , s);
}
