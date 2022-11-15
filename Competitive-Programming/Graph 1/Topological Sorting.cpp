/*
Topological Sorting
Send Feedback
Given a DAG(direct acyclic graph), print Topological Sorting of a given graph
Input Format:
The first line of input contains an integer T, the number of test cases.
The first line of each test case contains two single space-separated integers V, and E.
From the second line onwards of each test case, the next 'E' lines will denote the edges of the graph where every edge is defined by two single space-separated integers 'a' and 'b', which signifies an edge from vertex 'a’ to vertex 'b'.
Output Format :
For each test, case output will be "Correct" if the topological sort is done correctly else it will be "Incorrect".
Constraints:
1 <= T <= 10
1 <= V <= 1000
0 <= E <= 3000
0 <= U, V <= V-1

Time Limit: 1sec
Sample Input 1:
1
5 4
0 2
1 2
3 1
0 4
Sample Output 1:
Correct
Sample Output 1 Explanation:
One correct sort order is : 3 1 0 4 2.
*/



/*
    Time Complexity O(N)
    Space Complexity: O(N)

    where N is the number of nodes in the graph i.e N = 'nodes'.
*/

#include <algorithm>

void dfs(int idx, vector<vector<int>> &g, vector<int> &ans, vector<int> &vis) {
  if (vis[idx])
    return;
  vis[idx] = 1;
  for (int next : g[idx])
    dfs(next, g, ans, vis);

  ans.push_back(idx);
}
vector<int> topologicalSort(vector<vector<int>> &graph, int edges, int nodes) {
  // cout<<graph.size()<<" ";
  // return {};
  vector<vector<int>> g(nodes + 1);
  for (vector<int> edge : graph)
    g[edge[0]].push_back(edge[1]);

  vector<int> ans;
  vector<int> vis(nodes + 1, 0);
  for (int i = 0; i < nodes; i++) {
    if (!vis[i]) {
      dfs(i, g, ans, vis);
    }
  }
  reverse(ans.begin(), ans.end());
  return ans;
}
