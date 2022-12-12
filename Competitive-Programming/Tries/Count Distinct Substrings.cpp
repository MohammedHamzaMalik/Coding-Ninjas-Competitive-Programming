/*
Count Distinct Substrings
Send Feedback
Given a string 'S', you are supposed to return the number of distinct substrings(including empty substring) of the given string. You should implement the program using a trie.
Note :
A string ‘B’ is a substring of a string ‘A’ if ‘B’ that can be obtained by deletion of, several characters(possibly none) from the start of ‘A’ and several characters(possibly none) from the end of ‘A’. 

Two strings ‘X’ and ‘Y’ are considered different if there is at least one index ‘i’  such that the character of ‘X’ at index ‘i’ is different from the character of ‘Y’ at index ‘i’(X[i]!=Y[i]).
Input Format :
The first line contains a single integer ‘T’ denoting the number of test cases.

Then, the ‘T’ test cases follow.

The first line of each test case contains a string.
Output Format :
For each test case, print an integer denoting the number of distinct substrings in the given string.

The output for each test case will be printed in a separate line.
Note :
You don’t need to print anything, It has already been taken care of. Just implement the given function.
Constraints :
1 <= T <= 5
1 <= |S| <= 10^3

‘S’ contains only lowercase English letters.

Time Limit: 1 sec
Sample Input 1 :
2
sds
abc
Sample Output 1 :
6
7
Explanation of Sample Input 1 :
In the first test case, the 6 distinct substrings are { ‘s’,’ d’, ”sd”, ”ds”, ”sds”, “” }

In the second test case, the 7 distinct substrings are {‘a’, ‘b’, ‘c’, “ab”, “bc”, “abc”, “” }.
Sample Input 2 :
2
aa
abab
Sample Output 2 :
3
8
Explanation of Sample Input 2 :
In the first test case, the two distinct substrings are {‘a’, “aa”, “” }.

In the second test case, the seven distinct substrings are {‘a’, ‘b’, “ab”, “ba”, “aba”, “bab”, “abab”, “” }
*/



/*
    Time Complexity: O(N^2)
    Space Complexity: O(N^2)

    Where 'N' is the length of the given string.
*/

//    Class for making trie
class TrieNode
{
public:
    TrieNode *children[26];

    TrieNode()
    {

        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
    }

    ~TrieNode()
    {
        for (int i = 0; i < 26; i++)
        {
            if (children[i] != NULL)
            {
                delete children[i];
            }
        }
    }
};

//    Function to insert a string into the trie.
void insert(string &s, int i, TrieNode *head)
{
    TrieNode *temp = head;

    int n = s.length();

    //    Iterate through the given string
    while (i < n)
    {
        char ch = s[i];

        //    If child node is not present.
        if (temp->children[ch - 'a'] == NULL)
        {
            //    Create new child node.
            temp->children[ch - 'a'] = new TrieNode();
        }

        //    Move to the child node.
        temp = temp->children[ch - 'a'];
        i++;
    }
}

//    Function to count the number of nodes in the trie.
int countNodes(TrieNode *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int subTreeNodes = 1;

    //    Iterate through the children of the current node.
    for (int i = 0; i < 26; i++)
    {
        subTreeNodes += countNodes(root->children[i]);
    }

    return subTreeNodes;
}

int countDistinctSubstrings(string &s)
{
    int n = s.length();

    //    Intialize the root of  the trie.
    TrieNode *head = new TrieNode();

    //    Insert all suffixes into the trie.
    for (int i = 0; i < n; i++)
    {

        insert(s, i, head);
    }

    //    Count the total number of nodes in the trie.
    int totalNodes = countNodes(head);

    //    Free the memory.
    delete head;

    //    Return the number of distinct substrings.
    return totalNodes;
}
