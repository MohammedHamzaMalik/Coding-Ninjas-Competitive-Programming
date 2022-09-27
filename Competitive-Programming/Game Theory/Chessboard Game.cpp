/*
Chessboard Game
Send Feedback
There is a chessboard of dimensions 15 X 15, and Alice and Bob start playing a game on it. The game is not chess, and involves just one coin.
The coordinates of the top left cell are (1,1) and the bottom right are (15,15). The coin is initially at (x,y). In each turn, the player whose turn it is can move the coin to any of the four cells (provided they are inside the board):
(x-2,y+1)
(x-2,y-1)
(x+1,y-2)
(x-1,y-2)
The figure below shows the possible moves of a coin at (5,4) (An 8 x 8 board is given in the image, but in the problem, it will always be a 15 x 15 board).


Alice makes the first move. Both Alice and Bob take alternate turns and move until it is not possible to move the coin anymore. The player unable to make a move loses.
For example:
If there is a coin at (1,1), Bob wins the game as Alice can make no move to start the game.
Input Format:
The first line contains 'T', denoting the number of test cases.
For each Test :
The first line contains three space-separated integers, ’X’ and ‘Y’.
Output Format:
For each query, if Alice wins, print “First” and if Bob wins, print “Second”..
Note:
You are not required to print the expected output. It has already been taken care of. Just implement the function.
Constraints -
1 <= 'T' <= 5 * 10^3
1 <= 'X',’Y’ <= 15.

Time Limit: 1 sec
Sample Input 1:
2
5 2
2 2
Sample Output 1
Second
Second
Explanation for Sample Input 1:
For test case 1:


Alice starts at the red square, and moves to either of the blue squares. However, whichever blue square Alice moves to, Bob can move to one of the green squares. It is not possible to make any moves from the green squares, and hence Bob wins. (Only the top 5 x 5 part of the board is shown).

For Test case 2:
   Alice cannot make any move, so Bob wins. 
Sample Input 2:
1
2 3
Sample Output 2:
First
*/



/*
    Time Complexity : O(4^N)
    Space Complexity : O(N^2)
    where 'N' is the length of the chessboard.
*/

// Check if coordinates lie inside the board.
bool isValid(int x, int y)
{
    return x >= 0 && x < 15 && y >= 0 && y < 15;
}

// Recursive function to cheeck if current cell is a winning state.
bool isWinning(int x, int y, vector<int> &dx, vector<int> &dy)
{   
    bool isWin = 0;
    for (int i = 0; i < 4; ++i)
    {
        // If a losing state is reachable, current state is winning.
        if (isValid(x + dx[i], y + dy[i]) && !isWinning(x + dx[i], y + dy[i], dx, dy))
        {
            isWin = 1;
            break;
        }
    }
    return isWin;
}

string winnerOfGame(int x, int y)
{
    // Decrement to make it 0-indexed.
    x--, y--;

    // Dx and Dy to simplify iterating reachable cells.
    vector<int> dx = {-2, -2, 1, -1};
    vector<int> dy = {1, -1, -2, -2};

    // If function returns true, First person wins, else second.
    if (isWinning(x, y, dx, dy))
        return "First";
    else
        return "Second";
}
