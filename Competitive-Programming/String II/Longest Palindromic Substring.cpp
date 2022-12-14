/*
Longest Palindromic Substring
Send Feedback
You are given a string (STR) of length N.
Your task is to find the longest palindromic substring. If there is more than one palindromic substring with the maximum length, return the one with the smaller start index.
Note:
A substring is a contiguous segment of a string.
For example :
The longest palindromic substring of "ababc" is "aba", since "aba" is a palindrome and it is the longest substring of length 3 which is a palindrome. There is another palindromic substring of length 3 is "bab". Since starting index of "aba" is less than "bab", so "aba" is the answer.
Input Format:
The first line of input contains a single integer 'T', representing the number of test cases or queries to be run. 
Then the 'T' test cases follow.

The first and only one of each test case contains a string (STR).
Output Format :
For every test case, print a single line containing the longest palindromic substring. 

If there are multiple possible answers then you need to print the substring which has the lowest starting index.
Note :
You do not need to print anything; it has already been taken care of. Just implement the given function.
Follow up:
Try to solve it using O(1) space complexity.
Constraints :
1 <= T <= 10
0 <= N <= 10^3

where 'T' is the number of test cases, 'N' is the length of the given string.

Time Limit: 1 sec
Sample Input 1:
1
abccbc
Sample Output 1:
bccb
Explanation for input 1:
For string "abccbc" there are multiple palindromic substrings like "a", "b", "c", "cc", "bccb", "cbc". But "bccb" is of the longest length. Thus, answer is "bccb".
Sample Input 2:
1
aeiou
Sample Output 2:
a
Explanation for input 2:
For string "aeiou" there are multiple palindromic substrings like "a", "e", "I", "o", "u", and all of the same length. But palindromic substring "a"  has the minimum starting index. Thus, the answer is "a".
*/



/*
    Time Complexity : O(N ^ 2)
    Space Complexity: O(1)
    
    Where N is the length of the string.
*/

#include <algorithm>

int expandAroundCenter(string str, int left, int right) 
{
    int start = left, end = right;
    int n = str.length();

    // Expand the center.
    while (start >= 0 && end < n && str[start] == str[end]) 
    {
        start--;
        end++;
    }

    return end - start - 1;
}

string longestPalinSubstring(string str)
{
    int n = str.length();

    if (n < 1) 
    {
        return "";
    }

    int start = 0, end = 0;

    for (int i = 0; i < n; i++) 
    {
        // Longest odd length palindrome with center points as i.
        int len1 = expandAroundCenter(str, i, i);

        // Longest even length palindrome with center points as i and i + 1.
        int len2 = expandAroundCenter(str, i, i + 1);

        int len = max(len1, len2);

        // Update the start and end.
        if (len > end - start + 1) 
        {
            start = i - (len - 1) / 2;
            end = i + (len) / 2;
        }

    }

    return str.substr(start, end - start + 1);
}
