/*
Distribute Items
Send Feedback
Find the total number of ways to distribute N items among three people such that :
Each person gets at least one item.

Exactly one person among all the three people gets the maximum number of items.
Input Format:
The first and the only line of input will contain an integer N, denoting the total number of items.
Constraints:
0 <= N <= 10^9

Time Limit: 1sec
Output Format:
 The only line of output prints the total number of ways to distribute the items.
Sample Input 1:
5
Sample Output 1:
3
Explanation For Sample Input 1:
We can distribute 5 items among three people in total 3 ways i.e. (1, 1, 3) (1, 3, 1) (3, 1, 1) 

NOTE: (1, 2, 2) is not a valid distribution of items since two people have a maximum number of items. Also, (0, 2, 3) is not a valid distribution because 1st person is not having at least one item.
Sample Input 2:
7
Sample Output 2:
12
*/



/*
    Time Complexity : O(1)
    Space Complexity : O(1)
*/

long countWays(int n) {
  long ans = ((long)(n - 1) * (n - 2)) / 2;

  // Subtract total number of ways when all 3 people get same number of items
  if (n % 3 == 0) {
    ans--;
  }

  // Now, subtract total number of ways when two persons get same number of
  // items and that too greater than third person. This distribution is possible
  // when two person get x number of items and third one will get y number of
  // items i.e. 2x + y = N y > 0 so, min value of y = 1, max value of x can be
  // (N - 1) / 2 also for invalid way y < x, as y = N - 2x so, n - 2x < x => x >
  // N / 3 thus total number of possible such x are (N - 1) / 2 - (N / 3)
  int waysTwoEquals = ((n - 1) / 2) - (n / 3);

  ans -= (waysTwoEquals * 3);

  return ans;
}
