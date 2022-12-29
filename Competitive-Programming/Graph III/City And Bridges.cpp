/*
City And Bridges
Send Feedback
Ninja got a map in his hand with ‘N’ cities numbered 1 to ‘N’, connected with bridges. He asks his sister to delete some cities from the map.
He will ask his sister a ‘Q’ query. Each query is denoted by an integer ‘X’, meaning that he will delete the city ‘X’. He wants to see if the new map obtained after deleting the city node will have more connected components than the previous map.
He wants to build the program for the queries given by his sister for the above condition.
Ninja knows that you are a very good programmer and can help him in writing the code for the above. Help Ninja!
Note:
A connected component in the map is the maximum subset of cities that are connected i.e we can go from one city to any other in that subset.
Input format :
The first line of input contains an integer ‘T’, which denotes the number of test cases. Then each test case follows.

The first line of each test case contains two separated integers ‘N’ and ‘M’ denoting ‘N’ cities and ‘M’ bridges.

Each of the next ‘M’ lines contains 2 integers ‘A’  and ‘B’, meaning that there is an edge between city A and city B.

The next line contains a single integer ‘Q’ denoting the number of queries

The next line contains ‘Q’ space-separated integers denoting the value of the nodes to be deleted.
Output format :
For each query, if deleting the city on the map results in more number of connected components then print ‘Yes’, else print ‘No’.

Output for each query will be printed separated by a single space.
Constraints:
1 <= T <= 5
1 <= N <= 10^5
1 <= M <= 10^5
0 <= A <= N
1 <= B <= N
1 <= X <= N

Time Limit : 1 sec.
Sample Input 1 :
2
5 5
0 1
1 2
2 3
3 4
2 4
1
0
5 5
0 1
1 2
2 3
3 4
2 4
1
1
Sample Output 1 :
No
Yes
Explanation for sample test case 1:


Test Case 1 :
If we remove the node with value 0 from the graph, The graph will have only 1 connected component with nodes 1, 2, 3, 4 which is not more than the connected components in the graph before deleting the node. Therefore the output will be “No”.

Test Case 2:
If we remove node with value 1 from the graph, the graph will have 2 connected components i.e one with 0 and one with 2, 3, 4. which is more than the connected  components in the graph before deleting the node. Therefore the output will be “Yes” . 
Sample Input 2 :
2
5 5
1 2
2 3
3 4
4 5
3 5
2 
3 5
5 5
1 2
2 3
3 4
4 5
3 5
1
4
Sample Output 2 :
Yes No
No
*/



#include <unordered_set>

void articulation(vector<vector<int>> &arr, int u, int par, unordered_set<int> &art, vector<bool> &vis, int &tme, vector<int> & low, vector<int> & discovery)
{
    
    vis[u] = true;
    
    ++tme;
    
    int children = 0;
    
    // Initialize discovery time and low value.
    low[u] = discovery[u] = tme;
    
    // Go through all vertices aadjacent to u.
    for(int i = 0; i < arr[u].size(); i++) 
    {
        
        // 'adjacent' is current adjacent of u
        int adjacent = arr[u][i];
        if(adjacent == par) 
        {
            continue;
        }
        
        if(!vis[adjacent]) 
        {
            ++children;
            articulation(arr, adjacent, u, art, vis, tme, low, discovery);
            
            /*
                Check if the subtree rooted with 'adjacent' has a connection to
                one of the ancestors of u.
            */
            low[u] = min(low[u], low[adjacent]);
            
            // u is an articulation point in following cases.
            // (1) u is root of DFS tree and has two or more chilren.
            if(par == -1 and children > 1) 
            {
                art.insert(u);
            }
            
            /*
                (2) If u is not root and low value of
                one of its child is more than discovery value of u.
            */
            if(par != -1 and low[adjacent] >= discovery[u]) 
            {
                art.insert(u);
            }
        }
        
        // Update low value of u for parent function calls.
        else
        {
            low[u] = min(low[u], discovery[adjacent]);
        }
    }
}

void cityAndBridges(vector<vector<int>> &arr, int n, int m, int q, vector<int> &query) 
{
    unordered_set<int> art;
    int tme = 0;
    vector<bool> vis(n, false);
    vector<int> low(n, -1);
    vector<int> discovery(n, -1);

    for(int i = 0; i < n; i++) 
    {
        if(!vis[i])
        {
            articulation(arr, i, -1, art, vis, tme, low, discovery);
        }
    }
    
    for(int i = 0; i < q; i++) 
    {
        if(art.find(query[i]) != art.end())
        {
            cout << "Yes" << " ";
        }
        
        else
        {
            cout << "No" << " ";
        }
    }
    
}
