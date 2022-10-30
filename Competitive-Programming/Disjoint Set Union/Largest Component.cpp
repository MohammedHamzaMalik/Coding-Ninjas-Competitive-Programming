/*
Largest Component
Send Feedback
You are given an array 'ARR' of size 'N' containing positive integers. Consider an undirected graph using the given array with the following conditions:
-> The graph consists of 'N' vertices.
-> The ith vertex has a value 'ARR[i]'.
-> There is an edge between two vertices 'i' and 'j' (where 'i' < 'j'), if and only if GCD('ARR[i]', 'ARR[j]') is greater than 1.
GCD(a, b) is the maximum number x such that both a and b are divisible by x.
Your task is to find the size of the largest component in the graph.
A component of an undirected graph is a subgraph in which any two vertices are connected to each other by paths, and which is connected to no additional vertices in the rest of the graph. The size of a component is the number of vertices in it.
Input format :
The first line of input contains a single integer 'T', representing the number of test cases or queries to be run. 
Then the 'T' test cases are as follows.

The first line of each test case contains a positive integer 'N', which represents the size of the array 'ARR'.

The next line contains 'N' single space-separated positive integers representing the elements of the array.
Output Format :
For each test case, print an integer denoting the size of the largest component in the graph.
Note:
You do not need to print anything, it has already been taken care of. Just implement the given function.
Constraints :
1 <= T <= 10
1 <= N <= 10^3
1 <= ARR[i] <= 10^5

Where 'ARR[i]' is the ith element in the array.

Time Limit: 1 sec
Sample Input 1:
1
6
10 4 2 5 3 9
Sample Output 1:
4
Explanation for Sample Input 1:
In the first test case, there are two components of size 4 and 2.
sample

Sample Input 2:
2
3
1 2 3
4
2 2 2 2
Sample Output 2:
1
4
Explanation for Sample Input 2:
In the first test case, there are three components and each is of size 1.
In the second test case, there is only one  components and it is of size 4.
*/



/*
    Time Complexity: O(N^2 * log(K))
    Space complexity: O(N^2)
    
    Where N is the size of the given array and K is the maximum element in the given array.
*/

int GCD(int a, int b){
    if (b == 0){
        return a;
    }
    return GCD(b, a % b);
}

void dfs(int v, int &componentSize, vector<bool> &isVisited, vector<vector<int>> &adjList){
    isVisited[v] = true;
    componentSize++;

    for (int i = 0; i < adjList[v].size(); i++){
        int u = adjList[v][i];

        if (isVisited[u] == false){
            dfs(u, componentSize, isVisited, adjList);
        }
    }
}

int largestComponent(vector<int> &arr, int n){
    // Stores the size of largest component.
    int ans = 0;

    vector<vector<int>> adjList(n);

    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){

            if (GCD(arr[i], arr[j]) > 1){
                // Add an edge between i and j.
                adjList[i].push_back(j);
                adjList[j].push_back(i);
            }
        }
    }

    vector<bool> isVisited(n, false);

    for (int i = 0; i < n; i++){
        if (isVisited[i] == false){
            // Stores the size of a component.
            int componentSize = 0;

            dfs(i, componentSize, isVisited, adjList);

            ans = max(ans, componentSize);
        }
    }

    return ans;
}
