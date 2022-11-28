/*
Circle Intersection
Send Feedback
You have been given the coordinates of the center of two circle by (‘X1’,’Y1’) and (‘X2’,’Y2’) respectively with radius ‘R1’ and ‘R2’ you have to find if they intersect each other or not. If they are touching each other that is also called an intersection here.
Example:
Input: X1 = 0, Y1 = 0, X2 = 2, Y2 = 0, R1 = 1, R2 = 1

Output: YES

Circles intersect with each other at (1,0) with each other. Refer to the image given below:
circle

Input Format :
The first line will contain the integer 'T', denoting the number of test cases.

For each test case, the first line will be ‘X1’, ‘Y1’, ‘X2’, ‘Y2’, ‘R1’, ‘R2’.
Output format :
For each test case, print the “YES” if they are intersecting each other else print “NO”.    
Note :
You don't need to print anything. It has already been taken care of. Just implement the given function.
Constraints :
1 <= 'T' <= 10
-10^9 <= ‘X1’, ‘Y1’, ‘X2’, ‘Y2’, ‘R1’, ‘R2’  <= 10^9

Time Limit: 1 sec
Sample Input 1 :
2
0 0 2 0 1 1
0 0 2 2 1 1 
Sample Output 1 :
YES
NO
Explanation Of Sample Input 1 :
For the first case if you draw the circle they will intersect each other.
circle

For the second case if you draw the circle they will not intersect each other.


Sample Input 2 :
2
0 0 1000000000 0 600000000 400000000
0 0 100 100 5 5
Sample Output 2 :
YES
NO
*/



/*
    Time Complexity: O( 1 )
    Space Complexity: O( 1 )
*/

bool intersectCircle(int x1, int y1, int x2, int y2, int r1, int r2) {

    // Find the square of the distance.
    long long dist = (long long)(x1 - x2) * (x1 - x2) + (long long)(y1 - y2) * (y1 - y2);

    // Find the square of the sum of radius.
    long long rad = (long long)(r1 + r2) * (r1 + r2);

    // If distance square <= radius square than they either touching / intersecing each other.
    if (dist <= rad) {
        return true;
    } else {
        return false;
    }
}
