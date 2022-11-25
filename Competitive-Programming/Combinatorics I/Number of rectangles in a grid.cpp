/*
Number of rectangles in a grid
Send Feedback
You are given an arbitrary grid with M rows and N columns. You have to print the total number of rectangles which can be formed using the rows and columns of this grid. In simple words, print the number of unique rectangles in the grid.
For example:
Consider the grid shown below. The dark black boundary encloses a grid of dimension 3x4.
alt text

The green colour represents rectangles of dimension 1x1. 
The brown colour represents the rectangles of dimension 1x2.
The blue colour represents the rectangles of dimension 2x2.
The red colour represents the rectangles of dimension 3x3.
The yellow colour represents the rectangles of dimension 3x1.
There can be many different other possibilities as well. You need to print the total number of all such rectangles. 
Note:
Two rectangles are said to be unique if atleast one of their 4 sides is non-overlapping.
Input Format:
The first line of the input contains a single integer T, representing the number of test cases.

The first and only line of each test case contains two space-separated positive integers, representing the values of M(number of rows) and N(number of columns) respectively.
Output Format:
For each test case, print the number of rectangles which can be formed using the rows and columns of the given grid.
Note:
You do not need to print anything. It has already been taken care of. Just implement the given function.
Constraints:
1 <= T <= 100
1 <= N, M <= 10^4
Time Limit: 1sec
Follow Up:
Try to solve this problem in O(1) time.
Sample Input 1:
1
3 4
Sample Output 1:
60
Explanation for sample input 1:
In a grid of 3x4 dimensions, 
There are 30 rectangles of 1xN where N=1, 2, 3, 4
There are 20 rectangles of 2xN where N=1, 2, 3, 4
There are 10 rectangles of 3xN where N=1, 2, 3, 4
Adding all these values, we get 30+20+10 = 60. 
Hence, there are 60 rectangles in a grid of dimension 3x4.
Sample Input 2:
1
4 5
Sample Output 2:
150
*/



/*
	Time Complexity: O(1)
	Space Complexity: O(1)
*/

long long countRectangles(int m, int n) 
{

	// Below formula is a simplified version of MC2 * NC2.
	long long ans = (1ll * m * (m + 1) * n * (n + 1)) / 4;
	return ans;
}
