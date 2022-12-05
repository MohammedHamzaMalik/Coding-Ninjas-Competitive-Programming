/*
Number of Islands II
Send Feedback
You have a 2D grid of ‘N’ rows and ‘M’ columns which are initially filled with water. You are given ‘Q’ queries each consisting of two integers ‘X’ and ‘Y’ and in each query operation, you have to turn the water at position (‘X’, ‘Y’) into a land. You are supposed to find the number of islands in the grid after each query.
An island is a group of lands surrounded by water horizontally, vertically, or diagonally.
Input Format:
The first line contains an integer ‘T’ denoting the number of test cases. 

The first input line of each test case contains two single space-separated integers ‘N’ and ‘M’ representing the number of rows and columns of the grid, respectively.

The second line of each test case contains an integer ‘Q’ representing the number of queries.

Next ‘Q’ lines contain two single space-separated integers ‘X’ and ‘Y’, representing the coordinates of the grid i.e the coordinates of the point to be turned into land.
Output Format:
For each test case, print a single integer denoting the number of islands after each query operation.

Print the output of each test case in a separate line.
Note:
You are not required to print the expected output; it has already been taken care of. Just implement the given function.
Constraints:
1 <= T <= 5
1 <= N <= 1000
1 <= M <= 1000
1 <= Q <= 100000
0 <= X < N
0 <= Y < M

Time limit: 1 sec
Sample Input 1:
2
3 3
4
0 0
0 1
1 2
2 1
4 5
4
1 1
0 1
3 3
3 4
Sample Output 1:
1 1 2 3
1 1 2 2
Explanation of Sample Output 1:
In test case 1, 

0.  000
    000
    000

1.  100
    000
    000

2.  110
    000
    000

 3. 110
    001
    000

 4. 110
    001
    100

So, the answer is 1, 1, 2, 3.

In test case 2,

0.  00000
    00000
    00000
    00000

1.  00000
    01000
    00000
    00000

2.  01000
    01000
    00000
    00000

 3. 01000
    01000
    00000
    00010

 4. 01000
    01000
    00000
    00011

So, the answer is 1, 1, 2, 2.
Sample Input 2:
2
2 2
2
0 0
1 1
1 1
1
0 0
Sample Output 2:
1 2
1
Explanation of Sample Output 2:
In test case 1, 

0.  00
    00

1.  10
    00

2.  10
    01

So, the answer is 1, 2.

In test case 2,

0.  0

1.  1

So, the answer is 1.
*/



/*
    Time Complexity : O(Q * N * M)
    Space Complexity : O(N * M)

    Where 'Q' is the number of queries.
    Where 'N' is the number of rows and 'M' is the number of columns.
*/

// Funtion to check whether 'X', 'Y' is valid or not.
bool valid(int x, int y, int n, int m, vector<vector<int>> &grid, vector<vector<int>> &vis){
	if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == 0 || vis[x][y] == 1){
		return 0;
	}

	return 1;
}

// Funtion to mark all the reachable vertex from 'X', 'Y' as visited.
void dfs(int x, int y, vector<int> &dx, vector<int> &dy, vector<vector<int>> &grid, vector<vector<int>> &visited){
	visited[x][y] = 1;

	for (int dir = 0; dir < 4; dir++){
		int X = x + dx[dir], Y = y + dy[dir];

		if (!valid(X, Y, grid.size(), grid[0].size(), grid, visited)){
			continue;
		}
		dfs(X, Y, dx, dy, grid, visited);
	}
}

vector<int> numOfIslandsII(int n, int m, vector<vector<int>> &q){
	// To store the number of islands after each query.
	vector<int> ans;

	vector<vector<int>> grid(n, vector<int>(m));

	// Directions to the neighbouring cells of 'X', 'Y'.
	vector<int> dx = {1, 0, -1, 0};
	vector<int> dy = {0, 1, 0, -1};

	for (int i = 0; i < (int)q.size(); i++){
		int x = q[i][0], y = q[i][1];

		grid[x][y] = 1;

		int noOfIslands = 0;

		vector<vector<int>> visited(n, vector<int>(m));

		// Computing the number of connected components int the grid.
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				if (grid[i][j] == 1 && !visited[i][j]){
					dfs(i, j, dx, dy, grid, visited);
					noOfIslands++;
				}
			}
		}
		ans.push_back(noOfIslands);
	}
	// Return the answer.
	return ans;
}
