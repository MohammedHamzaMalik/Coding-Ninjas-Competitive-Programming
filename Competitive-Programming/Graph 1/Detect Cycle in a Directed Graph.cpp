/*
Detect Cycle in a Directed Graph
Send Feedback
Given a directed graph, check whether the graph contains a cycle or not. Your function should return true if the given graph contains at least one cycle, else return false.
Input Format:
The first line of input contains an integer T, the number of test cases.

The first line of each test case contains two single space-separated integers ‘V’, and ‘E’. ‘V’ represents the number of nodes and ‘E’ represents the number of edges in the graph.

From the second line onwards of each test case, the next 'E' lines will denote the edges of the graph where every edge is defined by two single space-separated integers 'A' and 'B', which signifies an edge from vertex 'A’ to vertex 'B'.
Output Format:
For each test case print "true" if a cycle exists, else "false".
Constraints:
1 <= T <= 10
1 <= V <= 10^3
0 <= E <= 10^3
0 <= A, B < V

Time Limit: 1 sec
Sample Input 1:.
2
4 4
0 1
1 2
2 3
3 0
3 3
1 0
1 2
0 2
Sample Output 1:
true
false
Explanation for Sample Input 1:
In the first case,
From node 0 we can reach 0 again by following this sequence of nodes in the path: 0,1,2,3,0. As we can see in the image below.
Example

In the second case,
There is no cycle in the given graph. As we can see in the image below.
Example

Sample Input 2:
2
3 2
0 1
0 2
3 3
1 1
0 2
1 2
Sample Output 2:
false
true
*/



/*
    Time Complexity : O(V + E)
    Space Complexity : O(V + E)

	Where ‘V’ is the number of nodes and E represents the number of edges in the given graph.
*/

// Recursive function to find if there is back edge
bool DFS(int u, vector<int>& color, vector<vector<int>>& graph)
{
	// This vertex will be ancestor of the future vertices.
	color[u] = 1;

	// Iterate through all adjacent vertices.
	for (int i = 0; i < graph[u].size(); i++)
	{
		int v = graph[u][i];

		// Check for the back edge.
		if (color[v] == 1)
		{
			return true;
		}

		// Check if v is not visited and there is a back edge in subtree rooted with v.
		if (color[v] == 0 && DFS(v, color, graph))
		{
			return true;
		}
	}

	// Mark this vertex as visited.
	color[u] = 2;

	return false;
}


bool isCyclic(vector<vector<int>>& edges, int v, int e)
{
	// Adjacency list for the given sets of edges.
	vector<vector<int>> graph(v + 1);

	// Adding edges in the graph (adjacency list).
	for (int ei = 0; ei < e; ei++)
	{
		int a = edges[ei][0];
		int b = edges[ei][1];
		graph[a].push_back(b);
	}

	// Initialize color of all vertices as unvisited.
	vector<int> color(v, 0);

	// Do a DFS traversal if the node is unvisited.
	for (int i = 0; i < v; i++)
	{
		if (color[i] == 0 && DFS(i, color, graph) == true)
		{
			return true;
		}
	}

	return false;
}
