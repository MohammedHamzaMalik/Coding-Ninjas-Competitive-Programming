/*
Prim's Algorithm
Send Feedback
Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the total weight of Minimum Spanning Tree (MST) using Prim's algorithm.
Input Format :
First line will contain T(number of test case), each test case follows as. 
Line 1: Two Integers V and E (separated by space)
Next E lines : Three integers ei, ej and wi, denoting that there exists an edge between vertex ei and vertex ej with weight wi (separated by space)
Output Format :
Weight of MST for each test case in new line.
Constraints :
1 <= T <= 10
2 <= V, E <= 10^5
1 <= wt <= 10^4
Sample Input 1 :
1
4 4
0 1 3
0 3 5
1 2 1
2 3 8
Sample Output 1 :
9
*/



// #include<bits/stdc++.h>
// using namespace std;
// int main(){
    
//     // write your code here
//     return 0;
// }
#include<iostream>
#include<climits>
using namespace std;
int get_min_vertex(bool* visited, int* weight, int n)
{
	int min_vertex = -1;
	for (int i = 0; i < n; i++)
	{
		if (!visited[i] && (min_vertex==-1||(weight[i]<weight[min_vertex])))
		{
			min_vertex = i;
		}
	}
	return min_vertex;
}
void prims(int **edges, int n)
{
	bool* visited = new  bool[n];
	int* parent = new int[n];
	int* weight = new int[n];
	for (int i = 0; i < n; i++)
	{
		weight[i] = INT_MAX;
                visited[i]=false;
	}
	parent[0] = -1;
	weight[0] = 0;
	for (int i = 0; i < n - 1; i++)
	{
		int min_vertex = get_min_vertex(visited, weight, n);
		visited[min_vertex] = true;
		for (int j = 0; j < n; j++)
		{
			if (!visited[j] && edges[min_vertex][j] !=0)
			{
				if (weight[j] > edges[min_vertex][j])
				{
					weight[j] = edges[min_vertex][j];
					parent[j] = min_vertex;
				}
			}
			}
	}
	int ans=0;
	for (int i = 1; i < n; i++)
	{
		if (parent[i] < i)
		{
			// cout << parent[i] << " " << i <<" "<< weight[i]<<endl;
            ans+=weight[i];
		}
		else
		{
			// cout << i << " " << parent[i] << " " << weight[i] << endl;
            ans+=weight[i];
		}
	}
    
    // int ans=0;
	// for (int i = 0; i < v - 1; i++)
	// {
	// 	if (output[i].first_vertex < output[i].second_vertex)
	// 		// cout << output[i].first_vertex << " " << output[i].second_vertex << " " << output[i].weight << endl;
	// ans+=output[i].weight;
	// 	else
	// 		// cout << output[i].second_vertex << " " << output[i].first_vertex << " " << output[i].weight << endl;
	// 		ans+=output[i].weight;
	// }
    cout<<ans<<"\n";
}
int main()
{
	int t;cin>>t;
    while(t--){
        int n, e;
	cin >> n >> e;
	int** edges = new int* [n];
	for (int i = 0; i < n; i++)
	{
		edges[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			edges[i][j] = 0;
		}
	}
	for (int i = 0; i < e; i++)
	{
		int f, s, weight;
		cin >> f >> s >> weight;
		edges[f][s] = weight;
		edges[s][f] = weight;
	}
	prims(edges, n);
	// for (int i = 0; i < n; i++)
	// {
	// 	delete[]edges[i];
	// }
	// delete[]edges;
    }
}
