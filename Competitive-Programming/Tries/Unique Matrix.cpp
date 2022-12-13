/*
Unique Matrix
Send Feedback
You are given a binary matrix 'MATRIX' of 'N' rows and 'M' columns.
Your task is to return all the unique rows in the order they appear in the matrix.
For example:
Matrix = [ [1,0,1], [0,0,1 ], [1,0,1 ]] 
Result = [ [1,0,1], [0,0,1] ]. 
The row [1,0,1] is before [0,0,1] as it appears before in matrix.
Note: In the binary matrix, all the entries are either 0 or 1.
Input Format:
The first line of input contains an integer 'T’ denoting the number of test cases to run. Then the test case follows.

The first line of each test case contains two single space-separated integers ‘N’, ‘M’, denoting the number of rows and number of columns in the matrix, respectively. 

The next ‘N’ lines of each test case contain ‘M’ space-separated integers denoting the elements of the binary matrix.
Output Format:
For each test case, print all the unique rows in the order they appear in the matrix.

The output for each test case will be printed in a separate line.
Note:
You don’t need to print anything. It has already been taken care of. Just implement the given function.
Constraints:
1 <= T <= 10 
1 <= N <= 3000
1 <= M <= 40 

where ‘N’ and ‘M’ are the number of rows and columns of the matrix, respectively.

Time Limit: 1 sec.
Sample Input 1:
2
1 1
1
3 2
1 0
1 1
0 0
Sample Output 1:
1
1 0
1 1
0 0
Explanation of Sample Input 1:
For the first case, there is only one row in the matrix [ [1] ].

For the second test case, all the rows are unique, and they are printed in the order they appear in the matrix.
Sample Input 2:
2
2 5
0 0 0 0 0
1 0 0 0 0
5 2
0 1
0 0
0 0
0 0
0 0
Sample Output 2:
0 0 0 0 0
1 0 0 0 0
0 1
0 0
*/



/*
    Time Complexity: O(N * M)
    Space Complexity: O(N * M)

    Where N and M are the number of rows,
    columns in the matrix respectivley.
*/

typedef struct trieNode
{
    struct trieNode* left;
    struct trieNode* right;
} trieNode;

vector<vector<int>> uniqueRow(vector<vector<int>>& matrix, int n, int m)
{
    trieNode* head = new trieNode;
    head -> left = NULL;
    head -> right = NULL;
    vector<vector<int>> ans;

    for(int i = 0; i < n; i++)
    {
        // If the current row is unique or not.
        bool unique = false;
        trieNode* node = head;

        for(int j = 0; j < m; j++)
        {
            if(matrix[i][j] == 0)
            {
                if(node -> left == NULL)
                {
                    // New node is created and current row is unique.
                    node -> left = new trieNode;
                    node -> left -> left = NULL;
                    node -> left -> right = NULL;
                    unique = true;
                }
                node = node -> left;
            }
            else
            {
                if(node -> right == NULL)
                {
                    // New node is created and current row is unique.
                    node -> right = new trieNode;
                    node -> right -> left = NULL;
                    node -> right -> right = NULL;
                    unique = true;
                }

                node = node -> right;
            }
        }

        if(unique)
        {
            ans.push_back(matrix[i]);
        }
    }

    return ans;
}
