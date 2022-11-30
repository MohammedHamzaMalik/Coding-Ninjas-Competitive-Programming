/*
Check Square
Send Feedback
You are given four points on a two-dimensional coordinate system.
Can you check if those four points make a square?
Example:
Let the input be [1,0,2,1] and [0,1,1,2].
So, the coordinates of the four points be [ {1, 0}, {0, 1}, {2, 1}, {1, 2} ]
example

From the above image, we can see that it is a square. Thus, the output will be ‘Yes’.
Input format:
The first line of input contains an integer ‘T’ denoting the number of test cases.

The first line of each test case contains four space-separated integers representing x-coordinates of the four points.

The second line of each test case contains four space-separated integers representing y-coordinates of the four points.
Output format :
For each test case, print ‘Yes’ if four points make a square otherwise print ‘No’.
Note:
Don’t print anything, just return True if four points make a square otherwise return False.
Constraints:
1 <= T <= 10^4
-10^9 <= xi, yi <= 10^9

Time limit: 1 sec
Sample Input 1:
2
1 0 2 1
0 1 1 2
1 0 0 1
1 0 1 2
Sample Output 1:
Yes
No
Explanation For Sample Input 1:
Test Case 1: Refer to the example described above.

Test Case 2:
    The quadrilateral for the given four points is represented below.
test case 2

As we can clearly see this is not a square. Thus, the answer will be ‘No’.
Sample Input 2:
2
1 2 4 2
0 2 4 2
0 1 2 3
1 -1 2 0
Sample Output 2:
No
Yes
*/



/*
    Time Complexity: O(1)
    Space Complexity: O(1)
*/

#include <algorithm>

bool isSquare(vector<int> x, vector<int> y) {
    vector<long long> distSq;
    for(int i = 0; i < 4; i++) {
        for(int j = i + 1 ; j < 4; j++) {
            long long dist = (1LL * (x[i] - x[j]) * (x[i] - x[j])) + (1LL * (y[i] - y[j]) * (y[i] - y[j]));
            distSq.push_back(dist);
        }
    }

    sort(distSq.begin(), distSq.end());

    
    //Check if the distance of all the sides are equal 
    //and the length of the diagonals are equal to the length of each side * root(2).
    if(distSq[0] == distSq[1] &&
       distSq[1] == distSq[2] &&
       distSq[2] == distSq[3] &&
       distSq[4] == distSq[5] &&
       distSq[0] * 2LL == distSq[4] &&
       distSq[0] > 0){
        return true;
    }
    return false;
}
