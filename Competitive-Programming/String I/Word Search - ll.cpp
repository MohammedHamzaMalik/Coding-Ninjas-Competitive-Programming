/*
Word Search - ll
Send Feedback
You are given a two-dimensional grid having 'N' rows and 'M' columns, consisting of upper case characters. You are also given a word 'WORD'. You have to find the number of occurrences of that word in the grid.
Starting from a given cell, a word can be formed by moving in all eight directions: horizontally left, horizontally right, vertically up, vertically down, and four diagonal directions.
Example :
There are three occurrences of the word 'NINJA' in the following grid:
word_grid

Note :
1) Given word will not be a single character.

2) If occurrences of the given word start from two different cells, then these two occurrences are considered to be different.

Consider the word 'XYX' to be searched in the string 'AXYXB'. Here, we find an occurrence of 'XYX' at index 2 going in the right direction, and another occurrence at index 4 going in the left direction.

Although these two words correspond to the same word, they will be considered as different occurrences.
Input Format :
The first input line contains two integers, 'N' and 'M', the number of rows and columns respectively.

The next 'N' input lines representing the rows of the grid, contain a string each of length 'M'.

The next input line contains a string 'WORD'.
Output Format :
In the only output line prints the number of occurrences of the given string in the grid.
Note :
You don't have to print anything. It has already been taken care of, just implement the given function.
Constraints :
1 <= N <= 10^3
1 <= M <= 10^3
1 <= N*M <= 10^6
2 <= WORD.size <= 10^3

Time Limit : 1 sec
Sample Input 1 :
5 5
AANIQ
PJINT
NINJA
BLJIJ
PRADN
NINJA
Sample Output 1 :
3
Explanation For Sample Input 1 :
word_grid

Sample Input 2 :
3 4
RIAN
IAIR
AIRI
AIR
Sample Output 2 :
5
*/



/*
    Time Complexity : O(N*M*X)
    Space Complexity : O(1)

    Where N and M are the number of rows and columns and
    X is the length of the given word.
*/

// This function searches for the given word starting from cell (x, y) in all 8 directions.
int searchFromCell(string grid[], int n, int m, string word, int x, int y, int dx[], int dy[]) {

    int occurrences = 0;

    for (int i = 0; i < 8; i++) {
        int j;

        int lastX = x + dx[i] * (word.length() - 1);
        int lastY = y + dy[i] * (word.length() - 1);

        // There are not enough characters in this direction, so skip to the next direction.
        if (lastX < 0 || lastX >= n || lastY < 0 || lastY >= m) {
            continue; 
        }

        for (j = 0; j < word.length(); j++) {
            int newX = x + dx[i] * j;
            int newY = y + dy[i] * j;

            // There was a mismatch, break.
            if (grid[newX][newY] != word[j]) {
                break; 
            }
        }

        // The whole word was matched! Add 1 to occurrences.
        if (j == word.length()) {
            occurrences++;
        }
    }

    return occurrences;
}

int wordSearch(string grid[], int n, int m, string word) {
    int occurrences = 0;

    int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            
            // Search in all 8 directions only when the first letter of the word matches.
            if (grid[i][j] == word[0]) {
                occurrences += searchFromCell(grid, n, m, word, i, j, dx, dy);
            }
        }
    }

    return occurrences;
}
