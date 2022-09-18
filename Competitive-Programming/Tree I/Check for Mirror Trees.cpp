Check for Mirror Trees
Send Feedback
While learning DSA, Ninja found two N-ary trees and wants to check whether they are mirror images of each other or not. But, he can’t find a suitable method to check the same. Can you help Ninja to solve this problem?
You are given two N-ary trees, ‘TREEA’ and ‘TREEB’ having ‘N’ vertices labeled from 0 to ‘N’-1, and both the trees are rooted at node 0. Your task is to find whether the trees are mirror images of each other or not. Edges of the tree are in order from left to right.
For Example:
For the given example below, the trees are mirror images of each other.
Example

Input Format:
The first line of the input contains an integer, 'T,’ denoting the number of test cases.

The first line of each test case contains a single integer, the ‘N’ denoting the number of vertices in both the trees.
Next, ‘N’-1 lines have two integers i,j, denoting an edge between vertex i and vertex j in ‘TREE_A’.
Next, ‘N’-1 lines have two integers i,j, denoting an edge between vertex i and vertex j in ‘TREE_B’.
Output Format:
For each test case, print ‘YES’ if both the trees are mirror images of each other.

Print the output of each test case in a separate line.
Note:
You do not need to print anything. It has already been taken care of. Just implement the given function.
Constraints:
1 <= T <= 10
1 <= N <= 1000.
0 <= Node Label <=N-1.


Time limit: 1 sec
Sample Input 1:
2
5 
0 1
1 2
1 3
1 4
0 1
1 4
1 3
1 2
5
0 1
0 2
2 3
2 4
0 2
0 1
2 3
2 4
Sample Output 1:
YES
NO
Explanation of sample input 1:
For the first test case,
altimage

As from the image above, we can clearly see that these two N-ary trees are mirror images of each other. Hence, the answer is ‘YES’.



For the second test case, 
altimage

The given two trees are not the mirror images because corresponding to the Node 4 of ‘TREE_A’, there exist Node3 of ‘TREE_B’.Hence, the answer is ‘NO’.
Sample Input 2:
2
5
0 1
0 2
1 3
1 4
0 2
0 1
1 4
1 3
5
0 1
0 2
1 4
2 3
0 1
0 2
1 3
3 4
Sample Output 2:
YES
NO



#include<bits/stdc++.h>
bool checkMirror(int n, vector<vector<int>> &A, vector<vector<int>> &B)
{
    
    unordered_map<int,vector<int> > adj1; 
    for ( int i = A.size()-1 ; i>=0 ; i--)
    {
        int u = A[i][0]; 
        int v = A[i][1]; 
        adj1[u].push_back(v); 
    }
    unordered_map<int,vector<int> > adj2; 
    for ( int i = 0; i<A.size() ; i++)
    {
        int u = B[i][0]; 
        int v = B[i][1]; 
        adj2[u].push_back(v); 
    }
    for ( int i =0 ; i < n ;i++)
    {
        vector<int> temp1 , temp2 ;
      if(adj1.find(i) != adj1.end())
      {
          for(auto j : adj1[i])
          {
              temp1.push_back(j); 
          }
      }
         if(adj2.find(i) != adj2.end())
      {
          for(auto j : adj2[i])
          {
              temp2.push_back(j); 
          }
      }
        if(temp1.size()!= temp2.size())
            return false ; 
        int l =0 ; 
        while( l < temp1.size()&&l< temp2.size())
        {
            if(temp1[l]!=temp2[l])
                return false ; 
                
           l++;
        }
    }
    return true ; 
}
