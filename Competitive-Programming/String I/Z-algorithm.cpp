/*
Z-algorithm
Send Feedback
You’re given a string S of length N and a string P of length M. Your task is to find the number of occurrences of P in S in linear time.
For example:
If S = "ababa", and P = "ab", then "ab" occurs twice in "ababa".
Note:
The string only consists of lowercase English alphabets.
Input Format:
The first line of input contains T, the number of test cases.

The first line of each test case contains two integers N and M, the length of string S and P respectively.

The second line of each test case contains the string S.

The third line of each test case contains the string P.
Output Format:
The only line of output of each test case should contain an integer denoting the number of occurrences of P in S.
Note:
You don’t need to print anything. It has already been taken care of. Just implement the given function.
Constraints:
1 <= T <= 100
1 <= N, M <= 10^4

Time Limit: 1 sec
Sample Input 1:
2
5 2
ababa
ab
4 10
codercodes
code
Sample Output 1:
2
2
Explanation of Sample Input 1:
In the 1st testcase,
"ab" occurs two times in "ababa". The first occurrence is from position 1 to position 2 and the second occurrence is from position 4 to position 5.

In the 2nd testcase, 
"code" occurs two times in "codercodes". The first occurrence is from position 1 to position 4 and the second occurrence is from position 6 to position 9.
Sample Input 2:
2
7 3
aababba
aba
6 2
zzzzyz
zz   
Sample Output 2:
1
3
*/



vector<int> computeLPS( string p, int m ){
   int i = 1, len = 0;
   vector<int> lps(m,0);
   while ( i < m ){
       if ( p[i] == p[len] ){
           len++;
           lps[i] = len;
           i++;
       } else {
           if ( len != 0 ){
               len = lps[len-1];
           } else {
               lps[i] = 0;
               i++;
           }
       }
   }
   return lps;
}

int KMP( string s, string p ){
   int n = s.size(), m = p.size(), i = 0, j = 0, count = 0;
   vector<int> lps = computeLPS(p,m);
   while ( i < n ){
       if ( s[i] == p[j] ){
           i++;
           j++;
       } else {
           if ( j != 0 ){
               j = lps[j-1];
           } else {
               i++;
           }
       }
       if ( j == m ){
           count++;
           j = lps[j-1];
       }
   }
   return count;
}

int zAlgorithm(string s, string p, int n, int m){
return KMP(s,p);
}
