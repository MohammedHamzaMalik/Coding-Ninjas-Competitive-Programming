/*Problem Statement

Suggest Edit

You are given a string 'STH The Jing contains (0-2) [A-Z] [0-9] [special characters). You have to find the reverse of the string.

For example:

If the given string is: STR "abcde". You have to print the string "edcba".

Follow Up:

Try to solve the problem in 0(1) space complexity.

Input Format:

The first line of input contains a single integer 'T', representing the number of test cases or queries to be run.

Then the 'T' test cases follow.

The first and only line of each test case contains a string 'STR.

Output Format:

For each test case, print a single line containing a single string denoting the reverse of the given string 'STR.

The output of each test case will be printed in a separate line.

Constraints:

1<= |STRS|<=10^5

Where |STR|is the length of the string STR.

Sample Input 1:
abcde
coding
hello1

Sample Output 1:

edcba
gnidoc
1olleh
*/
#include <bits/stdc++.h>
string reverseString(string str)
{
    int a = str.length();
    // Write your code here.
    if (a == 1)
    {
        return str;
    }

    for (int i = 0; i < a / 2; i++)
    {
        char c = str[i];
        str[i] = str[a - 1 - i];
        str[a - 1 - i] = c;
    }
    return str;
}