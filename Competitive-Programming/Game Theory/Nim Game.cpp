/*
Nim Game
Send Feedback
Ninja and his friend are playing a game. They are having ‘N’ piles and each pile contains ‘A[i]’ amount of stones in it. Ninja will make the first move.
In each move, a player can choose any pile and remove any number of stones ( at least one ) from that pile. The player who cannot make a move loses the game.
Assuming both players play optimally, output 1 if Ninja wins the game and 0 if Ninja loses the game.
Example :
N = 3
A = [ 3, 4, 5 ]

Explanation : 

One of the optimal ways to play the game is : 

Ninja removes 3 stones from the first pile : [ 0, 4, 5 ].
Friend removes 3 stones from the second pile : [ 0, 1, 5 ].
Ninja removes 3 stones from the third pile : [ 0, 1, 1 ].
Friend removes 1 stone from the second pile : [ 0, 0, 1 ].
Ninja removes 3 stones from the third pile : [ 0, 0, 0 ].

Thus Ninja wins the game here.
Input Format :
The first line contains an integer 'T' which denotes the number of test cases to be run. Then the test cases follow.

The first line of each test case contains an integer ‘N’ denoting the number of piles of stones.

The next line contains ‘N’ integers representing the elements of array ‘A’. ‘A[i]’ denotes the number of stones in pile number ‘i’.
Output format :
For each test case, output 1 if Ninja wins the game and 0 if he loses.

Print the output of each test case in a new line.
Note :
You don’t need to print anything. It has already been taken care of. Just implement the given function.
Constraints :
1 <= T <= 5
1 <= N <= 10^5
1 <= A[i] <= 10^9

Time Limit : 1 sec
Sample Input 1 :
2
3
1 2 3
3
3 3 1
Sample Output 1 :
0
1
Explanation Of Sample Input 1 :
For test case 1 we have,    

One of the optimal ways of the game is : 

Ninja starts by removing 1 stone from pile 1 : [ 0, 2, 3 ].
Friend removes 1 stone from the second pile : [ 0, 1, 3 ].
Friend removes 2 stones from the third pile : [ 0, 1, 1 ].
Ninja removes 1 stone from the second pile : [ 0, 0, 1 ].
Friend removes 1 stone from the third pile : [ 0, 0, 0 ].

Hence, Ninja loses the game as he cannot make a move now.

So, we output 0.

For test case 2 we have,    

One of the optimal ways of the game is : 

Ninja starts by removing 1 stone from pile 3 : [ 3, 3, 0 ].
Friend removes 1 stone from the second pile : [ 3, 2, 0 ].
Ninja removes 2 stones from the first pile : [ 1, 2, 0 ].
Friend removes 1 stone from the first pile : [ 0, 2, 0 ].
Ninja removes 2 stones from the second pile : [ 0, 0, 0 ].

Hence, Ninja wins the game as his friend cannot make a move now.

So, we output 1.
Sample Input 2 :
2
2 
7 2 
5
4 1 7 5 1 
Sample Output 2 :
1
1
*/



int ninjaGame(vector<int> &piles, int n) {
    // Write your code here.
    int xorSum=0;
    
    //Taking Xor of all piles
    for(int i=0;i<piles.size();i++){
        xorSum^=piles[i];
    }
    if(xorSum!=0){
        return 1;
    }
    else return 0;
}
