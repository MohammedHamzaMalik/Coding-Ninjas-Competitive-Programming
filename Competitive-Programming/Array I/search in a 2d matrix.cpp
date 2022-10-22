/*Problem Statement

Suggest Edit

You have been given a 2-D array 'MAT' of size M x N where 'M' and 'N' denote the number of rows and columns, respectively. The elements of each row are sorted in non-decreasing order.

Moreover, the first element of a row is greater than the last element of the previous row (if exists).

You are given an integer TARGET' and your task is to find if it exists in the given 'MAT' or not.

Example:
Input Format:

The first line of input contains an integer 'T' representing the number of test cases Then the test case follows :

The first line of each test case contains three space-separated integers 'M', 'N' and TARGET where 'M' and 'N' denote the number of rows and columns of the 'MAT', respectively and TARGET is the integer to be found.

From the second line of each test case, the next 'N' lines represent the rows of the 'MAT. Every row contains 'M' single space-separated integers.

Output Format:

For each test case, print "TRUE" if 'TARGET is present in the 'MAT', else print "FALSE",
Constraints:

1 <= T <= 10^2

1 <= N <= 50

1 <= M <= 50

-10^5 <= MAT[i], TARGET <= 10^5

Time Limit: 1 sec
sample input:
1
3 4 8
1 2 3 4
5 6 7 8
9 10 11 12

 sample output
 true
*/
#include <bits/stdc++.h>
#include <bits/stdc++.h>
#include <vector>

bool findTargetInMatrix(vector<vector<int>> &mat, int m, int n, int target)
{

    int lastel = 0;
    for (int i = 0; i < m; i++)
    {
        if (target <= mat[i][n - 1])
        {
            lastel = i;
            break;
        }
    }
    for (int j = 0; j < n; j++)
    {
        if (target == mat[lastel][j])
        {
            return true;
        }
    }
    return false;
}