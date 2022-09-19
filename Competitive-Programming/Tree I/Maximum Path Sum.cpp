/************************************************************
Maximum Path Sum
Send Feedback
You are given an n-ary tree consisting of ‘N’ nodes. Your task is to return the maximum sum of the path from the root to the leaf node.
For example:
For the given tree:


The path 1 -> 3 -> 7 produces the maximum i.e, 11.
Input Format:
The first line of the input contains a single integer 'T', representing the number of test cases.

The first line of each test case contains an integer 'N', which denotes the number of nodes in the tree.

The second line of each test case contains elements of the N-ary tree in the level order form. The line consists of values of nodes separated by a single space. In case a node is changed, we take -1. The first not-null node(of the previous level) is treated as the parent of the first node of the current level. The second not-null node (of the previous level) is treated as the parent node for the next nodes of the current level and so on.
Output Format:
For each test case, print the maximum sum of the path from the root to the leaf node.

Print the output of each test case in a separate line.
Note:
You don’t need to print anything, it has already been taken care of.
Constraints:
1 <= T <= 10
1 <= N <= 5000
0 <= DATA <= 10^4

Where ‘T’ is the number of test cases, and ‘N’ is the total number of nodes in the binary tree, and “DATA” is the value of the tree node.

Time Limit: 1 sec
Sample Input 1:
2
7
1 2 3 -1 4 5 6 -1 7 -1 -1 -1 -1 -1
4
1 2 3 4 -1 -1 -1 -1
Sample Output 1:
11
5
Explanation of Sample Input 1:
Test Case 1: Given the tree:


The path (1 -> 3 -> 7) produces the maximum sum i.e, 11.

Test Case 2: Given the tree:


The path (1 -> 5) produces the maximum sum i.e, 5.
Sample Input 2:
2 
3
1 3 -1 5 -1 -1
5
10 9 8 -1 1 2 -1 -1 -1 -1
Sample Output 2:
9
21
************************************************************/  
  
  
/************************************************************

   Following is the TreeNode class structure

   class TreeNode {
    public:
        int data;
        vector<TreeNode*> children;

        TreeNode(int data) {
            this->data = data;
        }
   }

************************************************************/

#include<bits/stdc++.h>
void findmax(TreeNode*root,int sum,int &ans){
    if(root->children.size()==0){
        sum+=root->data;
      ans=max(ans,sum);
        return;
    }
    
    
    for(auto it:root->children){
        findmax(it,sum+root->data,ans);
    }
   
}
int findMaxSum(int n, TreeNode* root)
{
    int ans=0;
    findmax(root,0,ans);
    return ans;
}
