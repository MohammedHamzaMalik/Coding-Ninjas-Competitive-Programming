/*
Last Substring In Lexicographical Order
Send Feedback
You are given a string ‘Str’ of length ‘N’. Find the last substring of ‘Str’ in lexicographical order.
In Lexicographical order string ‘S1’ comes before string ‘S2’ if S1 is the prefix of S2 and (|S1| < |S2|), or if none of them is a prefix of the other and at the first position where they differ, the character in ‘S1’ is smaller than the character in ‘S2’.
Example :
Consider string ‘Str’ = “abba”, then its substring in lexicographical order is [“a”, “ab”, “abb”, “abba”, “b”, “bb”, “bba”].  Clearly, the last substring in lexicographical order is  “bba”. 
Input format :
The first line of input contains an integer ‘T’ denoting the number of test cases, then ‘T’ test cases follow.

The first and only line of each test case consists string ‘Str’
Output format :
For each test case, in a separate line print the last substring of ‘Str’ in lexicographical order.
Note :
You do not need to print anything, it has already been taken care of. Just implement the given function.
Constraints :
1 <= T <= 50
1 <= N <= 10^4
‘Str’ contains only lowercase English letters.

Time limit: 1 sec
Sample Input 1 :
2
a
abba
Sample Output 1 :
a
bba
Explanation For Sample Input 1 :
Test case 1 :
There is only one character in a given string, so it has only one substring ‘a’. So the last substring in lexicographical order will be ‘a’. 

Test case 2 :
See the problem statement for an explanation.
Sample Input 2 :
2
codingninjas
zdca
Sample Output 2 :
s
zdca
*/



