Ninja And Numbers
Send Feedback
Ninja is learning tree data structures. His friend is helping him learn by giving him problems to solve. He gives him a tree with N nodes numbered from 0 to N - 1 in the form of a parent array parent where parent[i] is the parent of the ith node. The root of the tree is node 0. Now Ninja has to find the kth ancestor of a given node. The kth ancestor of a tree node is the kth node in the path from that node to the root node.
Input Format:
The first line of input contains a single integer ‘T’, denoting the number of test cases.

The second line of each test case contains a positive integer ‘N’, denoting the number of nodes.

The third line of each test case contains the parent array.

The fourth line of each test case contains a node value and k value.
Output Format :
The first and only line of each test case contains an integer denoting the kth ancestor.
Note:
You are not required to print the expected output; it has already been taken care of. Just implement the function. 
Constraints:
1 <= T <= 10
1 <= k <= N <= 5 * 10 ^ 4
0 <= node < N
0 <= parent[i] < N

Time limit: 1 second
Sample Input 1:
2
7
-1 0 0 1 1 2 2
3 1
7
-1 0 0 1 1 2 2
5 2
Sample Output 1:
1
0
Explanation for Sample Output 1:
1

In the first test case, it is visible from the figure that the 1st ancestor of a node with the value of 3 is the parent node of 3. Parent of 3 is 1.So we return 1 as our answer. 

In the second test case, the first ancestor of the node with the value 5 is 2. Now to find the 2nd ancestor of this node, we find the 1st ancestor of the parent of this node. Now, 1st ancestor of 2 is 0. So we return 0 as our answer
Sample Input 2:
2
7
-1 0 0 1 1 2 2
4 2
7
-1 0 0 1 1 2 2
6 1
Sample Output 2:
 0
 2
   
   
   
/*
    Time Complexity: O(Nlog(N))
    Space Complexity: O(Nlog(N))

    Where 'N' is the number nodes in the tree.
*/

int par[1003][20];

vector<vector<int> > graph;

// Utility function for preprocessing using binary lifting concept
void dfs(int src = 0,int p = -1,int h = 0)
{
    if(p != -1)
    {
      par[src][0] = p;
      for(int j = 1; (1 << j) <= h; j++)
      {
         par[src][j] = par[par[src][j - 1]][j - 1];
      }
    }

    for(int i = 0; i < graph[src].size(); i++)
    {
        if(graph[src][i] == p)
        {
            continue;
        }
            
         dfs(graph[src][i], src, h + 1);
    }
}

// Utility function that returns the k-th ancestor.
int getKthAncestor(int node, int k) {
    
    for(int i = 31; i >= 0; i--)
    {
        if(node == -1)
        {
            break;
        }

        if((1 << i) & k)
        {
            node = par[node][i];
        }
    }

    return node;
}

int kthAncestor(int n, vector<int> parent, int node, int k)
{
    // Resize graph to size 'n'
    graph.resize(n);
    
    // Run through all parents and create graph considering edge b/w 'i' and parent[i]
    for(int i = 1;i < parent.size(); ++i)
    {
        int u = parent[i];

        graph[u].push_back(i);
    }

    memset(par, -1, sizeof(par));

    // Preprocessing
    dfs();

    for(int i = 0; i < n; i++)
    {
        graph[i].clear();
    }

    // Call helper function
    return getKthAncestor(node, k);
}
