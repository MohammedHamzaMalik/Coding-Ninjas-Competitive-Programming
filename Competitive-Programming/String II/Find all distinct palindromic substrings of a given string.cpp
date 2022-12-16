/*
Find all distinct palindromic substrings of a given string
Send Feedback
Ninja did not do homework. As a penalty, the teacher has given a string ‘S’ to ninja and asked him to print all distinct palindromic substrings of the given string. A string is said to be palindrome if the reverse of the string is the same as the string itself. For example, the string “bccb” is a palindrome, but the string “def” is not a palindrome.
Input Format:
The first line of input contains an integer ‘T’, denoting the number of test cases.
The first and only line of each test case contains the string ‘S’. 
Output Format:
For each test case, print all distinct palindromic substrings of the given string. Print the substrings in sorted manner and they should be space-separated.    

Print the output of each test case in a separate line.
Constraints:
1 <= T <= 10
1 <= |S| <= 1000

String S contains lowercase English letters only.

Where ‘T’ represents the number of test cases and ‘S’ represents the given string.

Time limit: 1 sec
Sample Input 1:
2
aba
aabb
Sample Output 1:
a aba b
a aa b bb
Explanation of sample input 1:
For the first test case, 
All the possible substrings are [ ‘a’, ‘b’, ‘ab’, ‘ba’, ‘aba’ ] out of which [ ‘a’, ‘aba', 'b’ ] are 
palindromic substrings.

For the second test case,
All the possible substrings are [ ‘a’, ‘b’, ‘aa’, ‘ab’, ‘bb’, ‘aab’, ‘abb’ , ‘aabb’ ] out of which [ 
‘a’, ‘b’, ‘aa’, ‘bb’ ] are palindromic substrings.
Sample Input 2:
2
babbb
abcdc
Sample Output 2:
a b bab bb bbb 
a b c cdc d
*/



#include<bits/stdc++.h>

vector<string>distinctPalindrome(string &s)
{
    int n = s.size();
    
    vector<vector<bool> > dp(n, vector<bool>(n, false));
    for (int i = 0; i < n; i++)
    {    
        dp[i][i] = 1;
        
        if (i < n && s[i] == s[i + 1]) {
            dp[i][i + 1] = 1;
        }
    }
    
    for (int len = 3; len <= n; len++)
    {
        for (int i = 0; i + len - 1 < n; i++)
        {
            if (s[i] == s[i + (len - 1)] && dp[i + 1][i + (len - 1) - 1])
            {
                dp[i][i + (len - 1)] = true;
            }
        }
    }
 
    vector<int> kmp(n, 0);
    
    for (int i = 0; i < n; i++)
    {
        int j = 0, k = 1;
        while (k + i < n)
        {
            if (s[j + i] == s[k + i])
            {
                dp[k + i - j][k + i] = false;
                kmp[k++] = ++j;
            }
            
            else if (j > 0)
            {
                j = kmp[j - 1];
            }
            
            else
            {
                kmp[k++] = 0;
            }
        }
    }
    
    vector<string>ans;
    
    for (int i = 0; i < n; i++)
    {
        string str;
        for (int j = i; j < n; j++)
        {
            str += s[j];
            if (dp[i][j])
            {
                ans.push_back(str);
            }
        }
    }
    
    sort(ans.begin(),ans.end());
    
    return ans;
}
