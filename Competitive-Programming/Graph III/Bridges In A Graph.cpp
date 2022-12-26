/*
Bridges In A Graph
Send Feedback
Given an undirected graph of V vertices and E edges. Your task is to find all the bridges in the given undirected graph. A bridge in any graph is defined as an edge which, when removed, makes the graph disconnected (or more precisely, increases the number of connected components in the graph).
For Example :
If the given graph is :
graph

Then the edge between 0 and 4 is the bridge because if the edge between 0 and 4 is removed, then there will be no path left to reach from 0 to 4.and makes the graph disconnected, and increases the number of connected components.
Note :
There are no self-loops(an edge connecting the vertex to itself) in the given graph.

There are no parallel edges i.e no two vertices are directly connected by more than 1 edge.
Input Format :
The first line of input contains an integer T, the number of test cases.

The first line of each test case contains two single space-separated integers V, and E.

From the second line onwards of each test case, the next 'E' lines will denote the edges of the graph where every edge is defined by two single space-separated integers 'a' and 'b', which signifies an edge between vertex 'a’ and vertex 'b'.
Output Format :
For each test case, 
In the first line, print a single integer C denoting the count of bridges in the given graph.

From the second line onwards of each test case, Print C lines, each line contains one edge i.e two space-separated integers a and b, where C denotes the number of bridges in the given graph.
Note :
In the output format
Each pair of vertices of a bridge will be sorted i.e the first value should be less than or equals to the second value.

The list of bridge edges will be sorted in non-decreasing order of their first value. In case if two pairs have the same first value, the pair with a smaller second value will come first.

You do not need to print or sort anything, it has already been taken care of. Just implement the given function. 
Constraints :
1 <= T <= 50
1 <= V <= 10 ^ 3
V-1 <= E <= 3 * 10^3
0 <= a, b < V

Time Limit: 1 sec
Sample Input 1 :
2
5 4
0 1
3 1
1 2
3 4
3 3
0 1
1 2
2 0
Sample Output 1 :
4
0 1
1 2    
1 3
3 4
0
Explanation for Sample Input 1 :
For the first test case, the graph will be represented as 
graph

There are four bridges((0-1),(1-2),(1-3),(3-4)) in the above-given graph denoted by red lines.
For the second test case, there is no bridge present in the given graph.
Sample Input 2 :
1
6 7
1 2
1 0
0 2
0 4
5 4
5 3
3 4
Sample Output 2 :
1
0 4
Explanation for Sample Input 2 :
For the first test case, the graph will be represented as 
graph

There is only one bridge((0-4)) in the above-given graph denoted by red lines.
*/



#include<bits/stdc++.h>
void dfs(int node, int parent, int timer,unordered_map<int, bool> &vis, vector<int> &low, vector<int> &dis,unordered_map<int, list<int> > &adj,
       vector<vector<int>> &result ){
    
     vis[node] = true;
     dis[node] = low[node] = timer++;
    
    for(auto nbr : adj[node]){
        if(nbr == parent)
            continue;
        
        if(!vis[nbr]){
            
            dfs(nbr, node, timer, vis, low, dis, adj, result);
            low[node] = min(low[node], low[nbr]);
            if(low[nbr] > dis[node]){
                vector<int> ans;
                ans.push_back(node);
                ans.push_back(nbr);
                result.push_back(ans);
            }
        }
        else
            low[node] = min(low[node], dis[nbr]);    
    }
}
vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
    unordered_map<int, bool> vis;
    unordered_map<int, list<int> > adj;
    
    for(int i = 0; i < edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<int> low(v);
    vector<int> dis(v);
    int parent = -1;
    int timer = 0;
    
    for(int i = 0; i < v; i++){
        low[i] = -1;
        dis[i] = -1;
    }
    vector<vector<int>> result;
    for(int i = 0; i < v; i++){
        if(!vis[i]){
            dfs(i, parent, timer, vis, low, dis, adj, result);
        }
    }
    return result;

}
