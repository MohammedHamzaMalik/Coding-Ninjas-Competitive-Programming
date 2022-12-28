/*
Critical Connection
Send Feedback
You are given a network with ‘N’ system nodes [0 to N - 1] and ‘M’ connection. Your task is to find out all critical connections in a given network.
Note: A connection between node ‘u’ and ‘v’ is said to be a critical connection, if after removal of a connection ‘u’ - ‘v’, there is no connection between node ‘u’ and ‘v’ and the network goes down.
For example:
For given N = 4, M = 4, 
1

The connection between system node 0 and 1 is a critical connection.
Input Format:
The first line contains one positive integer ‘T’, denoting the number of test cases, then ‘T’ test case follow

The first line of each test case contains two integers ‘N’ and  ‘M’, denoting the number of system nodes and the number of connections.

The next ‘M’ line contains two space-separated integers ’u’ and ‘v’, denoting the connection between ‘u’ and ‘v’.
Output Format:
The first line of each test case contains one integer ‘X’, denoting the number of critical connections.

The next ‘X’ lines contain two space-separated integers ’u’ and ‘v’, denoting critical connection between ‘u’ and ‘v’and ‘u’ is smaller than ‘v’.

The output of each test case will be printed on a separate line.
Note:
You do not need to print anything, it has already been taken care of. Just implement the given function.
Constraints:
1 <= T <= 5
1 <= N, M <= 10 ^ 6
0 <= u, v <= N - 1
There are no repeated connections. 

Time Limit: 1 sec.
Sample Input 1:
2
4 4
0 1
1 2
1 3
2 3
6 6
0 1
1 2
1 3
3 4
4 5
0 4
Sample Output 1:
1
0 1
2
1 2
4 5
Explanation of Sample Output1:
In the first test case, the given network  looks like this: 
1

The only connection between nodes 0 and 1 is critical. So, the number of critical connections is 1. 

In the second test case, the given network looks like this: 
1

The connection between nodes 1, 2, and 4, 5 is a critical connection. So, there are 2 critical connections. If anyone's failure makes the network go down
Sample Input 2:
2
5 6
0 1
1 3
2 1
2 2
2 4
3 3
5 3
0 1
2 0
4 3
Sample Output 2:
4
0 1
1 2
1 3
2 4
3
0 1
0 2
3 4
*/



#include <bits/stdc++.h>

void dfs(int node,int parent,vector<vector<int>>&graph,vector<int>&vis,
        vector<int>&tin,vector<int>&low,int &timer,vector<vector<int>>&ans)
{
    vis[node] = 1;
    low[node] = tin[node]=timer++;
    
    for(auto it: graph[node])
    {
        if(it == parent) continue;
        if(!vis[it])
        {
         dfs(it,node,graph,vis,tin,low,timer,ans);
            low[node] = min(low[node],low[it]);
            if(low[it] > tin[node]){
                ans.push_back({node,it});
            }
           }else{
            low[node] = min(low[node],low[it]);
        }
    }
}
    vector< vector<int> > criticalConnections(int n, vector<vector<int>> & edges) 
{
	vector<vector<int>>graph(n),ans;
    vector<int>tin(n,-1);
    vector<int>low(n,-1);
    vector<int>vis(n,0);
     for(auto e:edges)
    {
        int a = e[0];
        int b=e[1];
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
     int timer=0;
        for(int i=0;i<n;i++)
    {
        if(!vis[i])
            dfs(i,-1,graph,vis,tin,low,timer,ans);
    }
    return ans;
}
