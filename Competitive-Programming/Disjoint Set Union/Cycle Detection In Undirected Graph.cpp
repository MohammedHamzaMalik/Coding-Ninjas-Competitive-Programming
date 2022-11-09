/*
Cycle Detection In Undirected Graph
Send Feedback
You have been given an undirected graph with 'N' vertices and 'M' edges. The vertices are labelled from 1 to 'N'.
Your task is to find if the graph contains a cycle or not.
A path that starts from a given vertex and ends at the same vertex traversing the edges only once is called a cycle.
Example :
In the below graph, there exists a cycle between vertex 1, 2 and 3. 
Example

Note:
1. There are no parallel edges between two vertices.

2. There are no self-loops(an edge connecting the vertex to itself) in the graph.

3. The graph can be disconnected.
For Example :
Input: N = 3 , Edges =  [[1, 2], [2, 3], [1, 3]].
Output: Yes

Explanation : There are a total of 3 vertices in the graph. There is an edge between vertex 1 and 2, vertex 2 and 3 and vertex 1 and 3. So, there exists a cycle in the graph. 
Input Format:
The first line of input contains an integer 'T' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first line of each test case contains two single space-separated integers ‘N’ and ‘M’ representing the total number of vertices and edges, respectively.

The next ‘M’ lines contain two single space-separated integers representing an edge of the graph.
Output Format:
For each test case, the only line of output will return “Yes” if there exists a cycle in the graph. Else print “No”.
Note:
You are not required to print the expected output, it has already been taken care of. Just implement the function.
Constraints:
1 <= T <= 10
1 <= N <= 5000
0 <= M <= min(5000, (N * (N - 1)) / 2)
1 <= edges[i][0] <= N 
1 <= edges[i][1] <= N 

Time Limit: 1 sec 
Sample Input 1:
1
3 2
1 2
2 3
Sample output 1:
No
Explanation of Sample output 1:
 The above graph can be represented as 
Example

There are a total of 3 vertices in the graph.There is an edge between vertex 1 and 2 and vertex 2 and 3. So, there is no cycle present in the graph. 
Sample Input 2:
2
4 0 
4 3
1 4
4 3
3 1
Sample output 2:
No
Yes
*/



/*
    Time Complexity : O(N + M)
    Space Complexity : O(N)

    where 'N' is the number of vertices and
    'M' is the number of edges in the graph.
*/

bool isCycle (int vertex, vector<vector<int>>& graph, vector<bool>& visited, int parent)
{
    visited[vertex] = true;

    for (int adjVertex : graph[vertex])
    {
        if (visited[adjVertex] == false)
        {
            if (isCycle (adjVertex, graph, visited, vertex) == true)
            {
                return true;
            }
        }
        else if (adjVertex != parent)
        {
            return true;
        }
    }

    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    vector<vector<int>> graph(n + 1, vector<int>());

    for (int i = 0; i < m; i++)
    {
        graph[edges[i][1]].push_back(edges[i][0]);
        graph[edges[i][0]].push_back(edges[i][1]);
    }

    vector<bool> visited(n + 1, false);

    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == false)
        {
            if (isCycle (i, graph, visited, -1) == true)
            {
                return "Yes";
            }
        }
    }

    return "No";
}
