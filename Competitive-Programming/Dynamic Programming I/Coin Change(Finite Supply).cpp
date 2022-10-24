/*
Coin Change(Finite Supply)
Send Feedback
You are given an array of integers ‘coins’ denoting the denomination of coins and another array of integers ‘freq’ denoting the number of coins of each denomination.
You have to find the number of ways to make the sum ‘V’ by selecting some(or all) coins from the array.
The answer can be very large. So, return the answer modulo 1000000007.
For Example :
‘N’ = 3, ‘coins’ = {1, 2, 3}, ‘freq’ = {1, 1, 3}, ‘V’ = 6

For the given example, we can make six by using the following coins:
{1, 2, 3}
{3. 3}
Hence, the answer is 2.
Input Format :
The first line contains a single integer ‘T’ denoting the number of test cases, then each test case follows:

The first line of each test case contains a single integer ‘N’ denoting the total number of coins.

The second line of the test case contains ‘N’ integers denoting the elements of the array ‘coins’.

The third line of the test case contains ‘N’ integers denoting the elements of the array ‘freq’.

The fourth line of the test case contains the integer ‘V’ denoting the change we want. 
Output Format :
For each test case, print a single integer denoting the total number of possible ways to get change ‘V’.

Output for each test case will be printed in a separate line.
Note :
You are not required to print anything; it has already been taken care of. Just implement the function.
Constraints :
1 <= T <= 10    
1 <= N <= 100
1 <= coins[i] <= 100
1 <= freq[i] <= 100
1 <= V <= 100


Time limit: 1 sec
Sample Input 1 :
2
3
1 2 4
1 1 1
7
3
1 2 4
2 3 2
7
Sample Output 1 :
1
2
Explanation For Sample Input 1 :
In the first test case, there is only one possible way to make the sum equal to 7 i.e., taking all the coins. Hence answer is 1.

In the second test case, You can make the sum seven by using the following coins:
{1, 2, 4}, {1, 2, 2, 2}. Hence the answer is 2.
Sample Input 2 :
2
4
1 11 7 6
1 2 3 1
10
3
5 1 2
1 1 3
6
Sample Output 2 :
0
2
*/



/*
    Time Complexity : O(N * V * maxFreq)
    Space Complexity : O(N * V * maxFreq)

    where, N is the size of the vector ‘coins’, V is the required
    change and ‘maxFreq’ is the maximum supply of any coin.
*/

int coinChangeHelper(vector<int> &coins, vector<int> &freq, int v, int supply, int index, vector<vector<vector<int>>> &dp) {

	// Base Case.
	if (v < 0 or supply < 0 or index < 0) {
		return 0;
	}

	// Check if we get the desired change.
	if (v == 0) {
		return 1;
	}

	// Check if the current position is already visited or not.
	if (dp[index][v][supply] != -1) {
		return dp[index][v][supply];
	}

	int answer = 0;

	// Check if we can take the current coin or not.
	if (v - coins[index] >= 0 and supply > 0) {
		answer = coinChangeHelper(coins, freq, v - coins[index], supply - 1, index, dp) % 1000000007;
	}

	// Go to the next coin.
	if (index > 0) {
		answer = (answer + coinChangeHelper(coins, freq, v, freq[index - 1], index - 1, dp)) % 1000000007;
	}

	// Update the dp array.
	dp[index][v][supply] = answer % 1000000007;
	return answer;
}

int coinChange(int n, vector<int> &coins, vector<int> &freq, int v) {

	int maxFreq = 1;
	for (int i = 0; i < n; i++) {
		maxFreq = max(maxFreq, freq[i]);
	}

	// initialize a dp array.
	vector<vector<vector<int>>> dp(n, vector<vector<int>>(v + 1, vector<int>(maxFreq + 1, -1)));

	// Function call.
	return coinChangeHelper(coins, freq, v, freq[n - 1], n - 1, dp);
}
