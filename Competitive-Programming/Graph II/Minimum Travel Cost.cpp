/*
Minimum Travel Cost
Send Feedback
Ninjaland is a country having 'N' states numbered from 1 to 'N'. These 'N' states are connected by 'M' bidirectional roads. Each road connects to different states and has some cost to travel from one state to another. Now, the chief wants you to select 'N' - 1 roads in such a way that the tourist bus can travel to every state at least once at minimum 'COST'.
For example :
Consider a country having 4 states numbered from 1 to 4. These 4 states are connected by 5 bidirectional roads given as :
1 --- 2 with cost = 8
2 --- 3 with cost = 6
3 --- 4 with cost = 5
1 --- 4 with cost = 2
1 --- 3 with cost = 4

The map of the country can be represented as:


Now, the best way to choose 3 roads is:


The cost of travelling from any state to all other states is  2 + 4 + 6 i.e. 12.
Input format :
The first line contains an integer 'T' denoting the number of test cases or queries to be run. 

The first line of each test case or query contains two space-separated integers 'N' and ‘M’ representing the number of states and number of roads in the country, respectively. 

The next 'N' lines of every test case contain three single space-separated integers ‘A’, ‘B’ and ‘C’, representing a road between the states 'A' and 'B' and 'C' denoting the cost of travelling them.
Output format:
For each test case, print 'N' - 1 lines each containing 3 space separated integers 'A', 'B' and 'C' representing the road you have chosen and the cost to traverse that road.
Note:
You do not need to print anything, it has already been taken care of. Just implement the given function.
Constraints:
1 <= 'T' <= 10
1 <= 'N' <= 1000
'N' - 1 <= 'M' <= 2000
1 <= 'C' <= 10^6 

Time limit: 1 sec
Sample Input 1:
1
4 4
1 2 3
1 4 5
2 3 1
3 4 8  
Sample Output 1 :
1 2 3
2 3 1
1 4 5
Explanation for 1:
Here 'N' = 4, So we need to pick 3 roads such that all states are visited and cost is minimum. Now the possible ways are.

1. (1, 2) (2, 3) (1, 4): In this case, the total cost of travelling is 3 + 1 + 5 = 9.
2. (1, 2) (2, 3) (3, 4): In this case, the total cost of travelling is 3 + 1 + 8 = 12.
3. (1, 2) (1, 4) (3, 4): in this case, the total cost of travelling is 3 + 5 + 8 = 16.
4. (1, 4) (2, 3) (3, 4): In this case, the total cost of travelling is 5 + 1 + 8 = 14.

Clearly, the cost is minimal in the first case so we pick (1, 2) ( 2, 3) (1, 4) with cost of travel 9. Refer above for diagram. 
Sample Input 2:
1
3 3
1 2 5
2 3 4
3 1 2
Sample Output 2 :
2 3 4
3 1 2
Explanation for 2:
The given graph is:


Here 'N' = 3, So we need to pick 2 roads such that all states are visited and the cost is minimum. Now the possible ways are.

1. (1, 2) (2, 3) : In this case, the total cost of travelling is 5 + 4 = 9.
2. (1, 3) (2, 3) : In this case, the total cost of travelling is 2 + 4 = 6.
3. (1, 2) (1, 3) : in this case, the total cost of travelling is 5 + 2 = 7.

Clearly, the cost is minimal in the second case so we pick (1, 3) ( 2, 3)  with the cost of travel 6.



*/



/*
    Time Complexity: O(M*logN)
    Space Complexity: O(N + M)

    Where N is the number of states in the country.
    And M is number of roads.
*/

vector<vector<int>> findMST(vector<vector<int>> &road, int n, int m) {
  // Creating adjacency list representation of country graph from edge list.
  vector<pair<int, int>> adjList[n + 1];

  for (int i = 0; i < m; i++) {
    int first = road[i][0];
    int second = road[i][1];
    int cost = road[i][2];

    adjList[first].push_back(make_pair(second, cost));
    adjList[second].push_back(make_pair(first, cost));
  }

  vector<bool> visited(n + 1);
  vector<int> parent(n + 1);
  vector<int> weight(n + 1);

  for (int i = 1; i <= n; i++) {
    visited[i] = false;
    parent[i] = i;
    weight[i] = INT_MAX;
  }

  // We will take 1 as our source vertex.
  weight[1] = 0;

  set<pair<int, int>> minStates;

  for (int i = 1; i <= n; i++) {
    minStates.insert(make_pair(weight[i], i));
  }

  while (!minStates.empty()) {
    pair<int, int> temp = *(minStates.begin());
    minStates.erase(minStates.begin());

    visited[temp.second] = true;

    for (auto neighbours : adjList[temp.second]) {
      int node = neighbours.first;
      int cost = neighbours.second;

      if (visited[node] == false && cost < weight[node]) {
        minStates.erase(make_pair(weight[node], node));
        weight[node] = cost;
        minStates.insert(make_pair(weight[node], node));
        parent[node] = temp.second;
      }
    }
  }

  vector<vector<int>> mstEdges;

  for (int i = 2; i <= n; i++) {
    int first = i;
    int second = parent[i];

    mstEdges.push_back({first, second, weight[i]});
  }

  return mstEdges;
}
