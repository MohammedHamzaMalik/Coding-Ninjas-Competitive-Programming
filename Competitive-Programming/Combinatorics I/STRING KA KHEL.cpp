/*
STRING KA KHEL
Send Feedback
Ninja started a gaming shop and for that shop, he is planning to make a new game ‘String Ka Khel’. In that game user is provided with ‘N’ number of strings and he has to find out the maximum length of strings he can form by joining these ‘N’ strings. For joining two strings there is a condition that two strings will only join if the last character of the first string is same as the last character of the second string. If the user will find out the correct answer he will be given Coding Ninja goodies by the Ninja.
So your task is to find the maximum length of string which can be formed by joining strings according to the given condition. If no such combination exists return ‘0’. Strings only contain the letter ‘B’ and ‘R’.
Example:
The string is ‘RR’, ‘RB’ so we can combine ‘RR’ and ‘RB’ as the last character of ‘RR’ i.e ‘R’ matches with the first character of ‘RB’. But we cant combine ‘RB’ and ‘RR’ as the last character of ‘RB’ i.e ‘B’ doesn't matches with the first character of ‘RR’ i.e ‘R’ so our answer is '4'.
Input Format:
The first line of input contains an integer ‘T’ denoting the number of test cases.

The first line of each test case contains an integer ‘N’ denoting the number of strings.

The second line of each test case contains ‘N’ space-separated strings.
Output Format:
For each test case, print a single line containing a single integer denoting the maximum length of string which can be formed. In case no two strings can add simply print ‘0’.

The output of each test case will be printed in a separate line.
Note:
You do not need to print anything. It has already been taken care of. Just implement the given function.
Constraints:
1 <= T <= 100
2 <= N <= 1000
1 <= | ST | <= 1000    

Where ‘T’ represents the number of test cases and ‘N’ represents the total number of strings and '|ST|' represents the length of each of the ‘N’ strings.

Time Limit: 1 second    
Sample Input 1:
2
3
RBR BBR RRR
2
RRR BBB
Sample Output 1:
9
0
Explanation of Sample Input 1:
Test Case 1:

So according to this test case ‘3’ strings are given ‘RBR’, ‘BBR’, ‘RRR’ so possible combinations are:

‘RBR’ + ‘RRR’ length is  6.
‘RRR’ + ‘RBR’ length is  6.
‘BBR’ + ‘RBR’ length is  6.
‘BBR’ + ‘RRR’ length is  6.
‘BBR’ + ‘RBR’ + ‘RRR’ length is  9.
‘BBR’ + ‘RRR’ + ‘RBR’ length is  9.
So we can choose between any two strings which have a length of ‘9’, hence ‘9’ is the maximum length possible.

Test Case 2:

There are two possible ways : 
‘RRR’,  ‘BBB’ can't be possible because the last char is first(‘R’) != first char is second(‘B’). 
'BBB’, ‘RRR’   can't be possible because the last char of the first string (‘B’) != first char of the second string(‘R’).
Sample Input 2 :
2
3
BBR BBR BRB
2
B B
Sample Output 2 :
6
2
*/


int stringKhel(vector<string>& arr, int n)
{
   int bb = 0, rb = 0, rr = 0, br = 0;
   int len = arr[0].size();
   for (int i = 0; i < n; i++)
   {
       char first = arr[i][0];
       char last = arr[i][len - 1];

       if (first == 'R' && last == 'B') 
       {
           rb++;
       }

       if (first == 'B' && last == 'R')
       {
           br++;
       }

       if (first == 'R' && last == 'R')
       {
           rr++;
       }

       if (first == 'B' && last == 'B')
       {
           bb++;
       }
   }

   int ans;
   if (br == 0 && rb == 0)
   {
       ans = max(bb, rr);
   }
   else
   {
       if (br == rb)
       {
           ans = rr + bb + 2 * min(br, rb);
       }
       else
       {
           ans = rr + bb + 2 * min(br, rb) + 1;
       }
   }
   
   if (ans == 1)
   {
       return 0;
   }
   else
   {
       return (ans * len);
   }
}
