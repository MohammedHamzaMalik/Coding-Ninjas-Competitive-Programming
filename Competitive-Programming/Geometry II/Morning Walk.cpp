/*
Morning Walk
Send Feedback
Every morning, Alex and Bob go for their regular morning walk. There are some fixed paths for both of them. Alex starts at point A and goes till point B, and Bob starts at point C and goes till point D. Given the values of A, B, C, and D, can you tell whether they will meet at a point or intersect or never meet each other?
You will output a string containing:
“Never” if they never meet.
“Point” if they meet at a point.
“Intersect” if they intersect each other.
For Example:
For A = 1, B = 3, C = 5, D = 10


They will never meet as their paths have no common points.
Input Format:
The first line contains a single integer ‘T’ denoting the number of test cases to be run. Then the test cases follow.
The first line of each test case contains four space-separated integers representing A, B, C, D.
Output Format:
For each test case, print a string according to the above conditions.
Output for each test case will be printed in a separate line.
Note:
You are not required to print anything, it has already been taken care of. Just implement the function.
Constraints:
1 <= T <= 10^4
-10^6 <= A, B, C, D <= 10^9

Time Limit: 1 sec.
Sample Input 1:
2
8 10 1 8
1 10 5 8
Sample Output 1:
Point
Intersect
Explanation For Sample Output 1:
For the first test case,
Alex will walk from 8 to 10 and Bob will walk from 1 to 8, and they both will meet at 8.
So, the output will be Point.

For the second test case.
Alex will walk from 1 to 10 and Bob will walk from 5 to 8, so they will intersect each other as the paths have intersecting points.
So the output will be Intersect.
Sample Input 2:
2
1 10 8 15
1 5 6 10
Sample Output 2:
Intersect
Never
*/



/*
  Time Complexity: O(1).
  Space Complexity: O(1).
*/

string morningWalk(int a,int b,int c,int d){
    int alexStart = min(a,b);
    int alexEnd = max(a,b);
    int bobStart = min(c,d);
    int bobEnd = max(c,d);

    int end = min(alexEnd,bobEnd);
    int start = max(alexStart,bobStart);
  
    /*
        If start is equal to end then end point of 
        Bob's path is equal to starting point of Alex's
        path and vice versa. 
    */

    if(start == end){
    return "Point";
    }

    // If start is less than end then their path intersect.
    if(end > start){
        return "Intersect";
    }

    // Else they never meet.
    return "Never";
}
