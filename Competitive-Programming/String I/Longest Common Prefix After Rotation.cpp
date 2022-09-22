/*
Longest Common Prefix After Rotation
Send Feedback
You are given two strings 'A' and 'B' where string 'A' is fixed. But you can perform left shift operations on string B any number of times.
Your task is to find out the minimum number of left-shift operations required in order to obtain the longest common prefix of string 'A' and 'B'.
Note:
Left shift is defined as a single circular rotation on the string after which the first character becomes the last character and all other characters are shifted one index to the left.
For Example:
If A = “an”, B = “can”.
After performing one left shift operation, string B becomes “anc”.
After performing two left shift operations, string B becomes “nca”.
Follow Up:
Can you solve this in linear time and space complexity?
Input format:
The first line contains an integer 'T' which denotes the number of test cases or queries to be run. 
Then, the T test cases follow.

The first line of each test case contains the string A.

The second line of each test case contains the string B.
Output format:
For each test case, print the minimum number of left shift operations required in order to obtain the longest common prefix of string A and B.
Note:
You do not need to print anything. It has already been taken care of. Just implement the given function.
Constraints:
1 <= T <= 100
1 <= |A|, |B| <= 5 * 10^4
Where |A| and |B| denote the length of string, A and B respectively.   

All the characters of the string A and B contain lowercase English letters only.

Time limit: 1 second
Sample Input 1:
2
on
soon
an
an
Sample Output 1:
2
0
Explanation for sample 1:
For the first test case, the common prefix of A and B is .””
After one left shift, the string B becomes “oons”, now the common prefix is “o”.
After two left shifts, the string B becomes “onso”, now the common prefix is “on”.
After three left shifts, the string B becomes “nsoo”, now the common prefix is “”.
(We do not need to perform one more left shift, because if the number of left-shift operations is equal to the length of the string, then we get the original string. For example, here if we perform one more shift, then we get the string “soon” which was the original string.)
So after two left shifts, we get the longest common prefix i.e. “on”. Hence, the answer is 2.

For the second test case, the common prefix of A and B is “an”.
After one left shift, the string B becomes “na”, now the common prefix is “”.
So we get the longest common prefix without performing any shifts. Hence, the answer is 0. 
Sample Input 2:
2
abc 
def
sorry
personal
Sample output 2:
0
3
Explanation for sample 2:
For the first test case, the common prefix of A and B is “”.
After one left shift, the string B becomes “efd”, now the common prefix is again “”.
After two left shifts, the string B becomes “fde”, now the common prefix is again “”.
Here the length of the longest common prefix is 0, as there is no common prefix in all the cases. So we get the longest common prefix without performing any shifts. Hence, the answer is 0.
For the second test case, the common prefix of A and B is “”.
After one left shift, the string B becomes “ersonalp”, now the common prefix is “”.
After two left shifts, the string B becomes “rsonalpe”, now the common prefix is “”.
After three left shifts, the string B becomes “sonalper”, now the common prefix is “so”.
After four left shifts, the string B becomes “onalpers”, now the common prefix is “”.
After five left shifts, the string B becomes “nalperso”, now the common prefix is “”.
After six left shifts, the string B becomes “alperson”, now the common prefix is “”.
After seven left shifts, the string B becomes “lpersona”, now the common prefix is “”.

So after three left shifts, we get the longest common prefix i.e. “so”. Hence, the answer is 3.
*/



/*
    Time Complexity: O(N*(N+M)) 
    Space Complexity: O(1)

    Where M and N are the lengths of string a and b respectively.
*/

#include<string>

#include<algorithm>

int lengthOfTheCommonPrefix(string a, string b) {

    int n = b.length();
    int m = a.length();

    /*
		Initialize a count variable to 0, 
		which will store the length of the 
    	common prefix of "a" and "b".
	*/
    int count = 0;

    // Run a loop from 0 to min(n, m).
    for (int i = 0; i < min(n, m); i++) {

        /* 
        	If a[i] != b[i], then break out of the loop, 
        	else increase the count by 1.
        */
        if (a[i] != b[i]) {
            break;
        } else {
            count++;
        }
    }

    return count;
}

int minimumRequiredShifts(string a, string b) {

    int n = b.length();
    int m = a.length();

    // The ans variable stores the minimum required shifts. 
    int ans = 0;

    /* 
    	The max variable stores the length of the longest 
    	common prefix encountered so far.
    */
    int max = lengthOfTheCommonPrefix(a, b);

    for (int i = 1; i < n; i++) {

        // Perform the left shift on string b.
        reverse(b.begin(), b.begin());
        reverse(b.begin() + 1, b.end());
        reverse(b.begin(), b.end());

        int currentLength = lengthOfTheCommonPrefix(a, b);

        /* 
			If the length of the common prefix exceeds the max 
        	length so far, then update max to the currentLength 
        	and ans to i.
		*/
        if (currentLength > max) {
            max = currentLength;
            ans = i;
        }
    }

    return ans;
}
