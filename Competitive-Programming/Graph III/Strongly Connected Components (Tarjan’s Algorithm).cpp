/*
Strongly Connected Components (Tarjan’s Algorithm)
Send Feedback
You are given an unweighted directed graph of 'V' vertices and 'E' edges. Your task is to print all the strongly connected components (SCCs) present in the graph.
Input format:
The very first line of input contains an integer ‘T’ denoting the number of test cases.

The first line of every test case contains two space-separated integers ‘V’ and ‘E’ denoting the number of vertices and the number of edges present in the graph. 

The next ‘E’ lines contain two space-separated integers ‘a’ and ‘b’ denoting a directed edge from vertex ‘a’ to ‘b’.
Note:
Use zero-based indexing for the vertices.
Output format:
For each test case, print space-separated vertices present in the strongly connected components of the graph, print the output for one SCC on each line.

The order of sequence does not matter.
Note:
You do not need to print anything, it has already been taken care of. Just implement the given function.
Constraints:
1 <= 'T' <= 300 
1 <= 'V' <= 2000
'V' - 1 <= 'E' <= 2000
0 <= 'a, b' < 'V'

Time Limit: 1 sec
Sample Input 1:
1
5 6
0 1
1 2
1 4
2 3
3 2
4 0
Sample Output 1:
0 1 4 
2 3 
Explanation for Sample Input 1:
For the first test case, the graph is shown below. There are two SCCs in the graph, which are enclosed in the boxes as shown in the image below.
sample graph 1

Sample Input 2:
2
1 0
4 4
0 1
1 2
2 3
3 1
Sample Output 2:
0
0
1 2 3
Explanation for Sample Input 2:
For the first test case, the graph has 1 node(0) but there are no edges, therefore only 1 SCC exists and that is {0}.

For the second test case, one SCC is {0} and the other is {1, 2, 3}. Therefore the answer is 0, 1 2 3
*/



#include<bits/stdc++.h>

void topo(int i,vector<bool>& vis,stack<int>& st,unordered_map<int,list<int>>& adj){
    vis[i]=1;
    for(auto it : adj[i]){
        if(!vis[it]){
            topo(it,vis,st,adj);
        }
    }
    
    st.push(i);
}

void dfs(int node,vector<bool>& vis,vector<int>& temp,unordered_map<int,list<int>>& trans){
    vis[node]=1;
    temp.push_back(node);
    for(auto it:trans[node]){
        if(!vis[it]){
            dfs(it,vis,temp,trans);
        }
    }
}

vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
    // Write your code here.
    unordered_map<int,list<int>> adj;
    unordered_map<int,list<int>> trans;
    
    int m = edges.size();
    for(int i=0;i<m;i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        trans[v].push_back(u); //transpose graph  
    }
    
    //topological sort
    stack<int> st;
    vector<bool> vis(n,0);
    
    for(int i=0;i<n;i++){
        if(!vis[i]){
            topo(i,vis,st,adj);
        }
    }
    
    fill(vis.begin(),vis.end(),0); //marking unvisited 
    
    
    //doing dfs on transposed graph to find scc
    vector<vector<int>> ans;
    while(!st.empty()){
        vector<int> temp;
        int node = st.top();
        st.pop();
        if(!vis[node]){
            dfs(node,vis,temp,trans);
        }
        
        ans.push_back(temp);
    }
    
    return ans;
    
}
