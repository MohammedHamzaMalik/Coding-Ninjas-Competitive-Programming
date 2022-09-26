/*
First Repeated Character
Send Feedback
You are given a string 'STR' of lowercase English alphabets. You need to find the repeated character present first in the string.
Example:
If the string is: “abccba”, then the first repeated character is ‘c’, but the repeated character that is present first in the string is ‘a’. You need to print ‘a’.
Note:
Keep in mind that you need to print the repeated character that is present first in the string and not the first repeating character.
Input Format:
The first line contains a single integer ‘T’ representing the number of test cases. 

The first line of each test case will contain a string ‘S’, which denotes the string of lowercase English alphabets.
Output Format:
For each test case, print the repeated character that occurs first in the string. If no repeated character is found then print ‘%’.

Output for every test case will be printed in a separate line.
Note:
You don't need to print anything. It has already been taken care of. 

You just need to complete the “repeatedCharacter” function that returns the first repeating character in the string. In case there is no repeating character then return “%”.
Constraints:
1 <= T <= 200
0 <= size of S <= 10000

where 'S’ is the string of lowercase English alphabets.

Time limit: 1 sec
Sample Input 1:
2
abccba
codingninjas
Sample Output 1:
a
i
Explanation of sample input 1:
In the first test case, 
The repeated character that occurs first in the string is ‘a’

In the second test case, 
The repeated character that occurs first in the string is ‘i’
Sample Input 2:
3
hello
helloh
abc
Sample Output 2:
l
h
%
Explanation for sample input 2:
In the first test case, 
The repeated character that occurs first in the string is ‘l’

In the second test case, 
The repeated character that occurs first in the string is ‘h’

In the third test case, 
There is no repeating character in the string, so print ‘%’
*/



#include<bits/stdc++.h>
char repeatedCharacter(string &str){
	// Write Your Code Here.
    int n=str.length();
    unordered_map<char,int> m;
    for(int i=0;i<n;i++)
    {
        m[str[i]]++;
    }
    
    for(int i=0;i<n;i++)
    {
        if(m[str[i]]>1)
        {
            return str[i];
        }
    }
    return '%';
}
