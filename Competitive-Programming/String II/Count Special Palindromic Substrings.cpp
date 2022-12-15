/*
Count Special Palindromic Substrings
Send Feedback
You are given a string 'STR'. Your task is to count the number of special palindromic substrings of size greater than 1 that the given string contains. A substring is said to be a special palindrome in the following two cases:
If all the characters in the substring are the same.

If the length of the substring is odd and only the middle element is different, while all the other characters are the same. 
Example:
“aba” is a special palindrome, while “abaa” is not
Input Format:
The first line contains an integer ‘T’, which denotes the number of test cases or queries to be run. Then the test cases are as follows.

The first and the only line of each test case contains the string 'STR'.
Output Format:
For each test case, print the count of special palindromic substrings.

Print the output of each test case in a separate line.
Note:
You don’t need to print anything; It has already been taken care of. Just implement the given function.
Constraints:
1 <= T <= 100
1 <= |STR| <= 10000

Time limit: 1 sec
Sample Input 1:
2
bcbc
ccddd
Sample Output 1:
2
4
Explanation For Sample Input 1:
In the first test case, 
The special palindromic substrings in the given string are: bcb and cbc. Hence, the answer is 2 in this case.

In the second test case, 
The special palindromic substrings in the string are: cc, dd, ddd and dd. Hence, the answer is 4 in this case. 
Sample Input 2:
2
abccdcdf
baabaab
Sample Output 2:
3
4
*/



/*
    Time complexity: O(N) 
    Space complexity: O(N)
	
    Where N is the size of the string.
*/


int specialPalindromes(string &str)
{

    // Initialise ans to store count of special palindromes
    int ans = 0;

    // Initialise variable to store length of string
    int n = str.length();

    // Create an array with all values 0 to store count of continuous same characters
    vector<int> countSame(n, 0);

    // First pointer
    int a = 0;

    // Start traversing through the string
    while(a < n)
    {

        // Initialise a variable to store temporary count of continuous same characters
        int countContinuous = 1;

        // Initialise a variable to store next character
        int b = a + 1;

        // Count same characters
        while(b < n and str[a] == str[b] && (b < n))
        {
            countContinuous++;
            b++;
        }
            
        // CASE: 1
        // Count total substrings from the count of  continuous same characters
        ans = ans + (countContinuous * (countContinuous - 1) / 2);

        // Store this count in the array 
        countSame[a] = countContinuous;

        a = b;
    }

    // CASE: 2
    for(int i = 1; i < n; i++)
    {

        // If current character is equal to previous character
        if(str[i] == str[i - 1])
        {

            // Update values of array
            countSame[i] = countSame[i - 1];
        }

        if(i > 0 && i < (n - 1) && (str[i - 1] == str[i + 1]) && (str[i] != str[i + 1]))
        {
            ans += min(countSame[i - 1], countSame[i + 1]);
        }
    }

    // Return count
    return ans;
}
