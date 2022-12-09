/*
Maximum XOR
Send Feedback
You are given two arrays of non-negative integers say ‘arr1’ and ‘arr2’. Your task is to find the maximum value of ( ‘A’ xor ‘B’ ) where ‘A’ and ‘B’ are any elements from ‘arr1’ and ‘arr2’ respectively and ‘xor’ represents the bitwise xor operation.
Input Format:
The first line of the input contains an integer, 'T,’ denoting the number of test cases.

The first line of each test case contains two space-separated integers, 'N' and ‘M’ denoting the number of elements in the first and second array.

The second line of each test case contains 'N' space-separated integers denoting the elements of the array first array.

The last line of each test case contains 'M' space-separated integers denoting the elements of the array second array.
Output Format:
For each test case, print a single integer - the maximum possible xor among all possible pairs.

Print the output of each test case in a separate line.
Note :
You do not need to input or print anything, and it has already been taken care of. Just implement the given function.
Constraints:
1 <=  T  <= 5
1 <=  N, M <= 1000
0 <=  arr1[i], arr2[i]  <= 10 ^ 9

Where 'T' denotes the number of test cases, 'N', ‘M’ denotes the number of elements in the first array and second array, ‘arr1[i]', and ‘arr2[i]’ denotes the 'i-th' element of the first array and second array.

Time limit: 1 sec
Sample Input 1:
1
7 7
6 6 0 6 8 5 6
1 7 1 7 8 0 2
Sample Output 1:
15
Explanation of sample input 1:
First testcase:
Possible pairs are (6, 7), (6, 8), (6, 2), (8, 7), (8, 8), (6, 2). And 8 xor 7 will give the maximum result i.e. 15
Sample Input 2:
1
3 3
25 10 2
8 5 3
Sample Output 2:
28
Explanation of sample input 2:
First test case:
28 is the maximum possible xor given by pair = (25, 5). It is the maximum possible xor among all possible pairs.
*/



/*
    Time Complexity: O(32 * (N + M))
    Space Complexity: O(32 * N)

    where 'N', and 'M' are the size of the given array.
*/

#define INT_SIZE 32

// A Trie Node
struct TrieNode
{
    int value; 
    // value to store in leaf node
    TrieNode * Child[2];
};

// Utility function to create a new Trie node
TrieNode * getNode()
{
    TrieNode * newNode = new TrieNode;
    newNode -> value = 0;
    newNode -> Child[0] = newNode -> Child[1] = NULL;
    return newNode;
}

// Utility function insert new key in trie.
void insert(TrieNode *root, int key)
{
    TrieNode *temp = root;

    // Start from the most significant bit, and insert all bit of key one-by-one into trie.
    for (int i = INT_SIZE - 1; i >= 0; i--)
    {
        // Find current bit in given prefix
        bool current_bit = (key & (1 << i));

        // Add a new Node into trie
        if (temp->Child[current_bit] == NULL)
        {
            temp->Child[current_bit] = getNode();
        }

        temp = temp->Child[current_bit];
    }

    // Store value of key at leafNode
    temp->value = key ;
}

// Utility function to find maximum XOR value of an integer inserted in Trie and given key.
int  findMax(TrieNode * root, int key)
{
    TrieNode * temp = root;

    for (int i = INT_SIZE - 1; i >= 0; i--)
    {
        // Find current bit in given prefix
        bool current_bit = ( key & ( 1 << i) );

        // Traversal Trie, look for prefix that has opposite bit.
        if (temp->Child[1 - current_bit] != NULL)
        {
            temp = temp->Child[1 - current_bit];
        }

        // If there is no opposite bit then look for the same bit.
        else if (temp->Child[current_bit] != NULL){
            temp = temp->Child[current_bit];
        }
    }

    // Return Xor with value at leaf node.
    return key ^ temp->value;
}

int maxXOR(int n, int m, vector<int> &arr1, vector<int> &arr2)
{
    // Initialize result.
    int maxVal = 0;  

    // Create a Trie and inssert all elements of first array into trie.
    TrieNode *root = getNode();

    for (int i = 0; i < n; i++)
    {
        insert(root, arr1[i]);
    }

    // For each element in second array find max XOR value from trie.
    for (int i = 0 ; i < m; i++)
    {
        // Find maximum XOR value of current element with elements inserted in Trie.
        maxVal = max(maxVal, findMax(root, arr2[i]));
    }

    return maxVal;
}
