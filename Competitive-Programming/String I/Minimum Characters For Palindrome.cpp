/*
Minimum Characters For Palindrome
Send Feedback
Given a string STR of length N. The task is to return the count of minimum characters to be added at front to make the string a palindrome.
For example, for the given string “deed”, the string is already a palindrome, thus, minimum characters needed are 0.
Similarly, for the given string “aabaaca”, the minimum characters needed are 2 i.e. ‘a’ and ‘c’ which makes the string “acaabaaca” palindrome.
Input format :
The first line contains an integer 'T' which denotes the number of test cases or queries to be run. Then, the T test cases follow.

The first and only line of each test case or query contains the string STR. 
Output format :
For each test case, print the count of minimum characters needed in a separate line.
Note :
You do not need to print anything, it has already been taken care of. Just implement the given function.
Constraints :
1 <= T <= 10 
1 <= N <= 10 ^ 5 
STR contains only lowercase English letters.

Time limit: 1 sec
Sample input 1 :
2
abcd
dad 
Sample output 1 :
3
0
Explanation of sample input 1 :
For test case 1 : 
Minimum characters to be added at front to make it a palindrome are 3 i.e. “dcb” which makes the string “dcbabcd”.  

For test case 2 :
The string is already a palindrome, we do not need to add any character.     
Sample input 2 :
2
xxaxxa    
abb
Sample output 2 :
1
2
*/



bool palindrome(int i,int j,string &str){
   while(i<=j){
       if(str[i]!=str[j])
           return false;
       i++;
       j--;
   }
   return true;
}
int minCharsforPalindrome(string str) {
// Write your code here.
int n=str.length();
   int i=0,j=n-1;
   while(i<=j){
       bool x=palindrome(i,j,str);
       if(x)
           break;
       else
           j--;
   }
   return n-j-1;
}
