/*
Number Game
Send Feedback
Alice and Bob have invented a new game to play. The rules are as follows -
First, they get a set of n distinct integers. And then they take turns to make the following moves. During each move, either Alice or Bob (the player whose turn is the current) can choose two distinct integers x and y from the set, such that the set doesn't contain their absolute difference |x - y|. Then this player adds integer |x - y| to the set (so, the size of the set increases by one).
If the current player has no valid move, he (or she) loses the game. The question is who will finally win the game if both players play optimally. Remember that Alice always moves first.
Input Format :
Line 1 : n (size of the array)
Line 2 : array elements, a[i] (n spaced integers)
Output Format :
Line 1: Name of winner i.e. "Alice" or "Bob" (without quotes).
Constraints :
2  ≤  n  ≤  100 where n is initial size of array.
1  ≤  a[i]  ≤  10^9 where a[i] are the array elements
Sample Input 1:
2
2 3
Sample Output 1 :
Alice
Sample Input 2:
2
5 3
Sample Output 2 :
Alice
Sample Input 3:
3
5 6 7
Sample Output 3:
Bob
Sample Output 1 Explanation :
Consider the first test sample. Alice moves first, and the only move she can do is to choose 2 and 3, then to add 1 to the set. Next Bob moves, there is no valid move anymore, so the winner is Alice.
*/



/*
    Time Complexity : O(N * log(Max_Element) )
    Space Complexity : O(N)

    Where 'N' is size of initial set.
*/

// Function to find the gcd of two integers.
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

// Function to find the gcd of all the elements of an array.
int gcdCalc(vector<int> &ar, int n) {
    int ans = ar[0];

    for (int i = 1; i < n; i++) {
        ans = gcd(ar[i], ans);
    }
    return ans;
}


string gameWinner(vector<int> &arr, int n) {
    int gcdVal = gcdCalc(arr, n);

    int max = -1;

    for (int i = 0; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    // Total moves performed in game.
    int movesLeft = max / gcdVal - n;

    string ans;

    // If total moves are odd , Alice wins.
    if (movesLeft % 2 != 0) {
        ans = "Alice";
    } else {
        ans = "Bob";
    }
    return ans;
}
