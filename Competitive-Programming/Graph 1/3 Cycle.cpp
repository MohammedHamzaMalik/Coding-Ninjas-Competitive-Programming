/*
3 Cycle
Send Feedback
Given a graph with N vertices (numbered from 1 to N) and Two Lists (U,V) of size M where (U[i],V[i]) and (V[i],U[i]) are connected by an edge , then count the distinct 3-cycles in the graph. A 3-cycle PQR is a cycle in which (P,Q), (Q,R) and (R,P) are connected an edge.
Input Format :
Line 1 : Two integers N and M
Line 2 : List u of size of M
Line 3 : List v of size of M
Return Format :
The count the number of 3-cycles in the given Graph
Constraints :
1<=N<=100
1<=M<=(N*(N-1))/2
1<=u[i],v[i]<=N
Sample Input:
3 3
1 2 3
2 3 1
Sample Output:
1
*/



#include<bits/stdc++.h>
using namespace std;
#include<iostream>
#include<vector>
using namespace std;
int count_cycles(int** arr, int n)
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i != j && arr[i][j]==1)
			{
				for (int k = 0; k < n; k++)
				{
					if (j != k && k != i && arr[j][k]==1)
					{
						if (arr[i][k] == 1)
						{
							count += 1;
						}
					}
				}
			}
		}
	}
	return count;
}
int solve(int n,int m,vector<int>u,vector<int>v)
{
	int** arr = new int* [n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = 0;
		}
	}
	for (int i = 0; i < m; i++)
	{
		arr[u[i]-1][v[i]-1] = 1;
		arr[v[i]-1][u[i]-1] = 1;
	}
	return count_cycles(arr, n)/6;
}
int main(){
    // int t;
    // cin>>t;
    // while(t--){
        int n,m;
	vector<int>u,v;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int x;
		cin>>x;
		u.push_back(x);
        // v.push_back(y);
	}
	for(int i=0;i<m;i++)
	{
		int x;
		cin>>x;
		v.push_back(x);
	}
	cout<<solve(n,m,u,v)<<endl;
    // write your code here
}
// }return 0;}
