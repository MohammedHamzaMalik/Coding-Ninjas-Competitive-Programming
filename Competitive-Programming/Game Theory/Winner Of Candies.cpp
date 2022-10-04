/*
Winner Of Candies
Send Feedback
You and your friend met after a long time and decided to have candies. You brought ‘X’ candies while your friend brought ‘Y’ candies. Since you both were bored you decided to play a game where each of you will play one by one and you will start first. The game goes as follows :
In the ith move, the person will give i candies to the other person.
The person who is unable to donate the required amount of candies will lose. You are required to find out who will win the game.
For Example:
For X = 1, Y = 2 the game goes as follows - 

You will donate 1 candy. So you now have 0 and your friend has 3 candies.

Your friend will donate 2 candies. So you now have 2 and your friend has 1 candy.

You are required to donate 3 candies but you only have 2 candies.

Hence your friend wins.
Input Format:
The first line contains a single integer ‘T’ denoting the number of test cases to be run. Then the test cases follow.

The first line of each test case contains two space-separated integers X and Y which denote the number of candies you and your friend have initially.
Output Format:
For each test case, print “Win” if you will win the game and “Lose” if you don’t win the game.

Output for each test case will be printed in a separate line.
Note:
You are not required to print anything; it has already been taken care of. Just implement the function.
Constraints:
1 <= T <= 100
1 <= X, Y <= 10^9

Time Limit: 1 sec.
Sample Input 1:
1
3 2
Sample Output 1:
Win
Explanation For Sample Output 1:
The game proceeds as follows:- 
link

Sample Input 2:
1
100 1
Sample Output 2:
Win
*/



#include <bits/stdc++.h>

string winnerOfCandies(int x, int y){
    // Loop will stop when either x or y become less than or equal to 0
    for(int term = 1 ; x > 0 && y > 0 ; term++ ){
        // term is odd :
        if(term&1 == 1){
            x -= term;
            y += term;
        }else{
            y -= term;
            x += term;
        }
    }
    return (x <= 0 ) ? "Lose" : "Win";
}
