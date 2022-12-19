/*
Longest Chunked Palindrome Decomposition
Send Feedback
You are given a string ‘S’. Your task is to find the length of it’s longest possible chunked palindrome. In other words, you have to split the string ‘S’ into ‘K’ substrings ((Sub)1, (Sub)2, (Sub)3, ..., (Sub)K) such that:
1. The substring ‘(Sub)i’ is a non-empty string, for all 1 <= i <= K.
2. (Sub)1 + (Sub)2 + (Sub)3 + … + (Sub)K = ‘S’, which means the concatenation of all the substrings is equal to ‘S’.
3. (Sub)i = (Sub)(K-i+1), for all 1 <= i <= ‘K’.
You have to find the largest possible value of ‘K’
Note :
1. The string ‘S’ consists of only lowercase English alphabets.
2. A ‘substring’ is a contiguous sequence of characters within a string.
Input Format :
The first line contains an integer ‘T’, which denotes the number of test cases to be run. Then, the ‘T’ test cases follow. 

The first and only line of each test case contains a string ‘S’ of lowercase English alphabets.
Output Format :
For each test case, print in a new line an integer denoting the length of the longest possible chunked palindrome of string ‘S’.

Output for each test case will be printed in a separate line.
Note :
You do not need to print anything. It has already been taken care of. Just implement the given function.
Constraints :
1 <= T <= 10
1 <= |S| <= 1000

where 'T' denotes the number of test cases and |S| denotes the size of the string.

Time Limit: 1 sec
Sample Input 1 :
1
abcdefgdefabc
Sample Output 1 :
5
Explanation for sample input 1 :
We can split the string into “(abc)(def)(g)(def)(abc)”.
Sample Input 2 :
1
ninjas
Sample Output 2 :
1
Explanation for sample input 2 :
We can split the string into “(ninjas)”.
*/



/*
    Time Complexity: O(N^2)
    Space Complexity: O(N),

    where N is the size of the input string.
*/

int longestChunkedPal(string &s)
{

	// Declare a variable to store the answer.
	int ans = 0;
	int n = s.size();

	// Create two strings to store the substrings from left and right.
	string left = "", right = "";

	for (int i = 0; i < n; i++)
	{

		// Update both the strings.
		left = left + s[i];
		right = s[n - i - 1] + right;
        
		// If substring from the both end equals, then do the following.
		if (left == right)
		{
			ans++;
			left = "";
			right = "";
		}

	}

	return ans;
}
