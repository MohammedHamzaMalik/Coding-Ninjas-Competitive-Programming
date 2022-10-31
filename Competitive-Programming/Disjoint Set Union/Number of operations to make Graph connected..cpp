/*
Number of operations to make Graph connected.
Send Feedback
You have been given a graph consisting of ‘N’ vertices numbered from 1 to ‘N’. The graph has ‘M’ edges. In an operation, you can shift an edge between two directly connected vertices to between pair of disconnected vertices to make them directly connected. Return the minimum number of operations to make the graph connected. If it is not possible to make graph connected return -1.
Example:
Let’s say ‘N’ is 4 and ‘M' is 3. The 3 edges are (1,2), (2,3) and (1,3). Then our graph will look as follows:-
subsequence

To make the graph connected we can shift the edge between (1,3) to (1,4). This operation will make the graph connected. There are multiple ways in which we can make graph connected. So, in this case, we can make graph connected in just one operation.
Note:
1. A connected graph is a graph that is connected in the sense of a topological space, i.e., there is a path from any vertex to any other vertex in the graph.

2. There are no repeated edges and self-loops in the graph.

3. You do not need to print anything; it has already been taken care of. Just implement the function.
Input Format:
The first line contains a single integer ‘T’ representing the number of test cases.

The first line of each test case contains two space-separated integers ‘N’ and ‘M’ representing the number of vertices and the number of edges in the graph.

Each of the next ‘M’ lines contains two space-separated integers representing the vertices that are directly connected by an edge.
Output Format:
For each test case, print a single line containing a single integer denoting the minimum number of operations to make the graph connected. If it is not possible to make graph connected return -1.

The output of each test case will be printed in a separate line.
Note:
You do not need to input or print anything, as it has already been taken care of. Just implement the given function.
Constraints:
1 <= T <= 10
1 <= N <= 10000
1 <= M <= 10000
1 <= U[i], V[i] <= N

Where ‘T’ is the number of test cases.‘N’ is the number of vertices in the graph. ‘M’ is the number of edges in the graph. ‘U[i]’ and ‘V[i]’ are vertices of the i-th edge.

Time Limit: 1sec.
Sample Input 1:
2
4 3
1 2
2 3
3 1
4 3
1 2
2 3
3 4
Sample Output 1:
1
0
Sample Output 1 Explanation:
Test case 1:

The graph looks as follows:-
subsequence

Initially, graph is disconnected. We can apply one operation and shift the edge between (2,3) to (3,4). This operation will make the graph connected. The graph after the operation will look as follows:-
subsequence

Therefore the answer is 1.


Test case 2:

The graph looks as follows:-
subsequence

The graph is already connected so we don’t need to make any operation.

Therefore the answer is 0.
Sample Input 2:
2
4 2
1 2
3 4
4 6
1 2
1 3
1 4
2 3
2 4
3 4
Sample Output 2:
-1
0 
*/



#include<bits/stdc++.h>

void bfs(vector<vector<int>> &adj, int m, int n, vector<int> &vis, int start)
{
    queue<int> q;
    q.push(start);
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        vis[node]=1;
        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                q.push(it);
            }
        }
    }
}

int makeGraphConnected(int n, vector<pair<int,int>> edges, int m) 
{
	// Write Your Code here
    if(n>m+1) return -1;
    vector<vector<int>> adj(n+1);
    vector<int> vis(n+1, 0);
    for(int i=0; i<m; i++)
    {
        adj[edges[i].first].push_back(edges[i].second);
        adj[edges[i].second].push_back(edges[i].first);
    }
    
    int ans=-1;
    for(int i=1; i<=n; i++)
    {
        if(!vis[i])
        {
            bfs(adj, m, n, vis, i);
            ans++;
        }
    }
    
    return ans;
}


