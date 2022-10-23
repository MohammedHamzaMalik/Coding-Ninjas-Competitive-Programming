/*
Digits Decoding
Send Feedback
A few days back, Ninja encountered a string containing characters from ‘A’ to ‘Z’ which indicated a secret message. For security purposes he encoded each character of the string to its numeric value, that is, A = 1, B = 2, C = 3, till Z = 26 and combined them as a single sequence (SEQ) of digits of length N. Let's say the message was "LA", Ninja encoded it as 121 for L=12 and A=1.
Today, when he read the encoded secret message, he realised that he was not able to decode the original string. So, the Ninja is wondering in how many ways he can decode the numeric sequence to some valid string.
A valid string is a string with characters from A to Z and no other characters.
Example:
Let the encoded sequence be 121,

The first way to decode 121 is:
1 = A
2 = B
1 = A
Thus, the decoded string will be ABA.

The second way to decode 121 is:
12 = L
1 = A
Thus, the decoded string will be LA.

The third way to decode 121 is:
1 = A
21 = U
Thus, the decoded string will be AU.

So, there will be 3 ways to decode the sequence 121 i.e. [(ABA), (LA), (AU)].
Note:
The input sequence will always have at least 1 possible way to decode.    

As the answer can be large, return your answer modulo 10^9  + 7.
Follow Up:
Can you solve this using constant extra space?
Input format:
The first line of input contains an integer T denoting the number of queries or test cases. 

The first and only line of each test case contains a digit sequence.
Output format:
For each test case, print the number of ways to decode the given digit sequence in a separate line.
Note:
You do not need to print anything, it has already been taken care of. Just implement the given function.
Constraints:
1 <= T <= 10   
1 <= N <= 10^5
0 <= SEQ[i] <= 9

Time limit: 1 sec
Sample Input 1:
2
121
1234
Sample Output 1:
3
3
Explanation For Sample Input 1:
For test case 1: Refer to the example explained above.

For test case 2:
There will be 3 ways to decode it which are

The first way to decode this is:
1 = A
2 = B
3 = C
4 = D
Thus, the decoded string will be ABCD.

The second way to decode this is:
12 = L
3 = C
4 = D
Thus, the decoded string will be LCD.

The third way to decode this is:
1 = A
23 = W
4 = D
Thus, the decoded string will be AWD.

All the other ways to decode the sequence will lead to an invalid string.
Sample Input 2:
2
1213
21031
Sample Output 2:
5
1
*/



/*
    Time Complexity: O(N)
    Space Complexity: O(1)

    Where N is size of the sequence.
*/

int decodingDigits(string seq)
{
    int n = seq.size();

    //The idea is to store answers for the last 2 iterations,
    //in 2 variables named prev1 and prev2.
    int prev1 = 1, prev2 = 1, cur;

    for (int i = 1; i < n; i++)
    {
        cur = 0;
        if (seq[i] != '0')
        {
            cur += prev1;
        }

        int num = (seq[i - 1] - '0') * 10 + seq[i] - '0';
        if (num >= 10 and num <= 26)
        {
            cur += prev2;
        }

        prev2 = prev1;
        prev1 = cur % 1000000007;
    }
    return prev1;
}
