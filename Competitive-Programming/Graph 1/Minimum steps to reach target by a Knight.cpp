/*
Minimum steps to reach target by a Knight
Send Feedback
You have been given a square chessboard of size ‘N x N’. The position coordinates of the Knight and the position coordinates of the target are also given.
Your task is to find out the minimum steps a Knight will take to reach the target position.
alt text

Example:
knightPosition: {3,4}
targetPosition: {2,1}
alt text

The knight can move from position (3,4) to positions (1,3), (2,2) and (4,2). Position (4,2) is selected and the ‘stepCount’ becomes 1. From position (4,2), the knight can directly jump to the position (2,1) which is the target point and ‘stepCount’ becomes 2 which is the final answer. 
Note:
1. The coordinates are 1 indexed. So, the bottom left square is (1,1) and the top right square is (N, N).

2. The knight can make 8 possible moves as given in figure 1.

3. A Knight moves 2 squares in one direction and 1 square in the perpendicular direction (or vice-versa).
Input format:
The first line of input contains an integer ‘T’ denoting the number of test cases.
The next ‘3*T’ lines represent the ‘T’ test cases.

The first line of each test case contains a pair of integers denoting the initial position of the knight.

The second line of each input contains a pair of integers denoting the target position.

The third line of each test case contains an integer ‘N’ denoting the rows/columns of the chessboard.
Output format:
For each test case, print an integer representing the minimum steps a Knight will take to reach the target position.
Note :
You do not need to print anything; it has already been taken care of. Just implement the given function.
Constraints
1 <= T <= 10
1 <= N <= 1000
1 <= KNIGHTPOSITION(X, Y), TARGETPOSITION(X, Y) <= N

Time limit: 1 second
Sample input 1
2
8
2 1
8 5
6
4 5
1 1
Sample output 1
4
3
Explanation of sample input 1:
Test case 1:
alt text

The knight is initially at position [2,1]. It has 3 possible blocks to move to, [4,2], [3,3], and [1,3]. The knight chooses [4,2]. Now, there are 6 more possible blocks to move to. The knight chooses [5,4]. Further, the knight chooses position [7,3]. Finally, the knight moves to the target position which is [8,5] which calculates to 4 steps.

Test case 2:
The knight moves from position [4,5] to [5,3] to [3,2] and finally to the target position [1,1] which gives us the minimum steps by the knight, that is, 3.
(4, 5) -> (5, 3) -> (3, 2) -> (1, 1).
Sample input 2:
2
6 
2 4
6 4
6
1 1
4 5
Sample output 2:
2
3
*/



/*
    Time complexity: O( abs( KX - TX ) * ( KY - TY ) )
    Space complexity: O( abs( KX - TX ) * ( KY - TY ) )

    where 'KX' denotes x-coordinate of knight, 'TX' denotes x-coordinate of the
   target, 'KY' denotes y-coordinate of the knight and 'TY' denotes y-coordinate
   of the target.
*/

int minStepsHelper(pair<int, int> knightPosition, pair<int, int> targetPosition,
                   vector<vector<int>> &dp) {

  // If knight is on the target position return 0.
  if (knightPosition.first == targetPosition.first &&
      knightPosition.second == targetPosition.second) {
    return 0;
  } else {

    // If already calculated then return that value.
    if (dp[abs(knightPosition.first - targetPosition.first)]
          [abs(knightPosition.second - targetPosition.second)]) {
      return dp[abs(knightPosition.first - targetPosition.first)]
               [abs(knightPosition.second - targetPosition.second)];
    } else {
      int x1, y1, x2, y2;

      // (x1, y1) and (x2, y2) are the two positions which will be considered.
      if (knightPosition.first <= targetPosition.first) {
        if (knightPosition.second <= targetPosition.second) {
          x1 = knightPosition.first + 2;
          y1 = knightPosition.second + 1;
          x2 = knightPosition.first + 1;
          y2 = knightPosition.second + 2;
        } else {
          x1 = knightPosition.first + 2;
          y1 = knightPosition.second - 1;
          x2 = knightPosition.first + 1;
          y2 = knightPosition.second - 2;
        }
      } else {
        if (knightPosition.second <= targetPosition.second) {
          x1 = knightPosition.first - 2;
          y1 = knightPosition.second + 1;
          x2 = knightPosition.first - 1;
          y2 = knightPosition.second + 2;
        } else {
          x1 = knightPosition.first - 2;
          y1 = knightPosition.second - 1;
          x2 = knightPosition.first - 1;
          y2 = knightPosition.second - 2;
        }
      }

      dp[abs(knightPosition.first - targetPosition.first)]
        [abs(knightPosition.second - targetPosition.second)] =
            min(minStepsHelper({x1, y1}, targetPosition, dp),
                minStepsHelper({x2, y2}, targetPosition, dp)) +
            1;

      // Exchanging the coordinates x with y of both knight and target will
      // result in same ans.
      dp[abs(knightPosition.second - targetPosition.second)]
        [abs(knightPosition.first - targetPosition.first)] =
            dp[abs(knightPosition.first - targetPosition.first)]
              [abs(knightPosition.second - targetPosition.second)];
      return dp[abs(knightPosition.first - targetPosition.first)]
               [abs(knightPosition.second - targetPosition.second)];
    }
  }
}
int minSteps(pair<int, int> knightPosition, pair<int, int> targetPosition,
             int size) {
  vector<vector<int>> dp(size + 2, vector<int>(size + 2, 0));

  // There are 4 corner cases for which the minimum steps is 4.
  if ((knightPosition.first == 1 && knightPosition.second == 1 &&
       targetPosition.first == 2 && targetPosition.second == 2) ||
      (knightPosition.first == 2 && knightPosition.second == 2 &&
       targetPosition.first == 1 && targetPosition.second == 1)) {
    return 4;
  } else if ((knightPosition.first == 1 && knightPosition.second == size &&
              targetPosition.first == 2 && targetPosition.second == size - 1) ||
             (knightPosition.first == 2 && knightPosition.second == size - 1 &&
              targetPosition.first == 1 && targetPosition.second == size)) {
    return 4;
  } else if ((knightPosition.first == size && knightPosition.second == 1 &&
              targetPosition.first == size - 1 && targetPosition.second == 2) ||
             (knightPosition.first == size - 1 && knightPosition.second == 2 &&
              targetPosition.first == size && targetPosition.second == 1)) {
    return 4;
  } else if ((knightPosition.first == size && knightPosition.second == size &&
              targetPosition.first == size - 1 &&
              targetPosition.second == size - 1) ||
             (knightPosition.first == size - 1 &&
              knightPosition.second == size - 1 &&
              targetPosition.first == size && targetPosition.second == size)) {
    return 4;
  } else {
    dp[1][0] = 3;
    dp[0][1] = 3;
    dp[1][1] = 2;
    dp[2][0] = 2;
    dp[0][2] = 2;
    dp[2][1] = 1;
    dp[1][2] = 1;
    return minStepsHelper(knightPosition, targetPosition, dp);
  }
}
