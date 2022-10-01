/*
Game of Stones
Send Feedback
Given the count of total stones in a game. Two-player ‘Ale’ and ‘Bob’ are playing the game. Your task is to find who will win the game if both the players are playing optimally.
Rules of the game.
1. In a single turn, a player can choose a single stone or ‘even’ number of stones.
2. They will play alternatively, which means in the first chance ‘Ale’ will collect the stones, in second-chance ‘Bob’ will collect the stones. And always ‘Ale’ will start the game.
3. If any player is not able to take any stones then another player will win the game.
Input format:
The first line of input contains an integer ‘T’ denoting the number of test cases.

The first line of each test case contains a single integer,  which denotes the total number of stones in the game.
Output Format:
For each test case, return a string ‘Ale’ or ‘Bob’ according to your answer.
Note:
1. Do not print anything, just return ‘Ale’ if ‘Ale’ will win the game else return ‘Bob’.
Constraints:
1 <= T <= 10^5
1 <= number of stones <= 10^9

Where ‘T’ is the total number of test cases.
Time limit: 1 second
Sample Input 1:
2
2
3
Sample Output 1:
Ale
Bob
Explanation of sample input 1:
Test Case 1:

Given the number of stones is ‘2’.
Then first player ‘Ale’ can choose both the stones because 2 is an even number.
So ‘Ale’ will the game.
Return ‘Ale’.

Test Case 2:

Given the number of stones is ‘3’.
In the first turn ‘Ale’ can choose ‘1’ stone or ‘2’ store, but not ‘3’ stone because ‘3’ is neither ‘1’ or even number.
If ‘Ale’ chooses ‘1’ in the first turn. Then in the second turn, ‘Bob’ will collect the remaining ‘2’ stone, so ‘Bob’ will win.
If ‘Ale’ chooses ‘2’ stones in the first turn. Then in the second turn, ‘Bob’ will collect the remaining ‘1’ stone, again ‘Bob’ will win the game.
So in both cases ‘Bob’ is winning the game. Hence Return ‘Bob’. 
Sample Input 2:
2
4
6
Sample Output 2:
Ale
Ale
*/



/*
    Time complexity: O(1)
    Space complexity: O(1)

    We are using constant time and space. 
*/

string gameOfStones(int num){

    // Condition when 'Bob' can win.
    if(num == 3){
        return "Bob";
    }
    else{
        return "Ale";
    }
}
