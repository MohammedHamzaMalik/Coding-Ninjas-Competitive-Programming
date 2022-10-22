/*YouProblem Statement

You are given a string 'str', your task is to convert all the characters of the string into lowercase letters.

For Example:

You are given, 'str' = 'AbcdEfgh', in this string if you convert all the characters into lowercase, the string will be 'abcdefgg'. Hence it is the answer.

Input Format:

The first line of input contains a single integer 'T', representing the number of test cases.

The first line of each test case contains a string 'str' representing the given string.

Output Format:

For each test case, print a single string representing the given string with all characters in lower case.

Print a separate line for each test case.

Constraints:

1<= T<= 10

1 <=|str| <= 10^4

'str' will contain upper and lower case characters of the English alphabet. Time Limit: sec.

Sample Input 1
2
AbcdEfgh
AAAAb

Sample Output 1:
abcdefgh
aaaab

Explanation For Sample Input 1:

For the first test case, 'str' 'Abcdefgh', in this string if you convert all the characters into lowercase, the string will be abcdefgg. Hence it is the answer.

For the second test case, 'str' 'AMAh, in this string if you convert all the characters into Inercase, the string will be 'asaab'. Hence it is the answer.

Sample Input 2:
abcde
ABCDE

Sample Output 2
abcde
abcde
*/
#include <bits/stdc++.h>
string toLowerCase(string &str)
{
    // Write your code here.
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] >= 65 && str[i] <= 90)
        {
            str[i] = (char)(str[i] + 32);
        }
    }
    return str;
}