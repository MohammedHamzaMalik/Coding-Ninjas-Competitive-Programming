/*
Min Efforts Required
Send Feedback
The Ultimate Ninja Ankush, after training hard, goes for a good meal at the ninja cafe, for that he follows the path given on the map, which may or may not lead him to the ninja cafe. The map is a directed graph. Since he is also very lazy, he wants to minimize the effort to travel. The effort is defined as the product of all the distance it takes to reach from the dojo (source) to the ninja cafe (destination). Can you help him find the path with the minimum effort it would take The Ultimate Ninja Ankush to reach the destination?
More Formally, you are given a directed graph with ‘N’ nodes and ‘M’ edges where the distance of each edge is greater than 0, also given a source ‘src’ and a destination ‘dest’. The task is to find the minimum product of edges from src’ to ‘dest’. If there is no path from ‘src’ to ‘dest’, then return -1.
For example
Given:
‘N’ = 3, ‘M’ = 3. 
‘edges’ = 
    [[0 1 1],
     [1 2 1],
     [0 2 3]]
‘src’ = 0, ‘dest’ = 2.

There are two possible paths, that is to go from node-0 to node-2 directly, which will take 2 units of effort, or go from node-0 to node-1 and then node-1 to node-2, which will take 1 unit of effort.
Input format:
The first line of input contains an integer ‘T’ denoting the number of test cases.

The first line of each test case contains two space-separated integers, ‘N,’ where ‘N’ is the number of nodes in the graph, and ‘M’ where ‘M’ is the number of edges.

The next ‘M’ line contains 3 space-separated integers ‘U’, 'V’, and ‘WT’, ‘U’ is the parent node, ‘V’ is the child node and ‘WT’ is the weight of that edge.

The last line contains 2 space-separated integers, ‘src’ and ‘dest’.
Output Format :
For each test case, You are supposed to return an integer that denotes the minimum effort required.
Note:
You are not required to print the expected output; it has already been taken care of. Just implement the function.
Constraints:
1 <= ‘T’ <= 10
1 <= ‘N’ <= 100
1 <= ‘M’ <= (N*(N + 1))/2
0 <= ‘src’,’dest’ <= N 

Time Limit: 1sec.
Sample Input 1 :
2
3 3
0 1 1
1 2 1
0 2 3
0 2
4 2
0 1 4
0 2 2
0 3
Sample Output 1 :
1
-1  
Explanation of the Sample Input 1:
In the first test case, There are two possible paths, that is to go from node ’0’ to node-2’ directly, which will take 2 units of effort, or go from node ‘0’ to node ‘1’ and then node ‘1’ to node ‘2’, which will take 1 unit of effort. Therefore the final answer is 1.

In the second test case, The answer is -1 since there is no path from the source node[0] to the target node[3]. 
Sample Input 2 :
2
4 5
0 1 1
1 2 2
2 3 2
0 3 3
0 2 2
0 3
3 3
0 1 4
1 2 5
0 2 15
0 2
Sample Output 2 :
3
15
*/



/*
        Time Complexity : O('N * M')
        Space Complexity : O('N')

        Where 'N' is the number of nodes, and 'M' is the number of edges.
*/

long long int
minEffortsRequired(vector<pair<pair<int, int>, long long int>> &edges, int n,
                   int src, int dest) {

  if (src == dest) {
    return 0;
  }

  long long int inf = 1e18;

  vector<long long int> efforts(n + 1, inf);
  int m = edges.size();

  efforts[src] = 1;

  // Relaxing the edges, 'N-1' times.
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < m; j++) {
      int u = edges[j].first.first;
      int v = edges[j].first.second;
      long long int wt = edges[j].second;
      efforts[v] = min(efforts[v], efforts[u] * wt);
    }
  }

  /*
          This means there is no possible way,
          to reach from source to destination.
  */
  if (efforts[dest] == inf) {
    return -1;
  }

  return efforts[dest];
}
