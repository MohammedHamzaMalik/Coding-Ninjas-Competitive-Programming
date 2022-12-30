/*
Connected Horses
Send Feedback
You all must be familiar with the chess-board having 8 x 8 squares of alternate black and white cells. Well, here we have for you a similar N x M size board with similar arrangement of black and white cells.
A few of these cells have Horses placed over them. Each horse is unique. Now these horses are not the usual horses which could jump to any of the 8 positions they usually jump in. They can move only if there is another horse on one of the 8-positions that it can go to usually and then both the horses will swap their positions. This swapping can happen infinitely times.
A photographer was assigned to take a picture of all the different ways that the horses occupy the board! Given the state of the board, calculate answer. Since this answer may be quite large, calculate in modulo 10^9+7.
Input Format:
First line contains T which is the number of test cases.
T test cases follow first line of each containing three integers N, M and Q where N,M is the size of the board and Q is the number of horses on it.
Q lines follow each containing the 2 integers, X and Y which are the coordinates of the Horses.
Output format:
For each test case, output the number of photographs taken by a photographer in new line.
Constraints:
 1<=T<=10
 1<=N,M<=1000
 1<=Q<=N*M
Sample Input:
2
4 4 4
1 1
1 2
3 1
3 2
4 4 4
1 1
1 2
3 1
4 4
Sample Output:
4
2
*/



#include<bits/stdc++.h>

using namespace std;

long long mod =(pow(10,9)+7);

long long factorial(long long n){

    if(n ==0|| n ==1){

        return 1;

    }


 

    long long smallOutput =factorial(n-1);

    long long output = n*smallOutput;

    return(output%mod);

}


 

void dfs(int**chess,bool**visited,int x,int y,vector<pair<int,int>>&component,int n,int m){

        int dir[8][2]={{-2,1},{2,-1},{-1,-2},{-1,2},{1,2},{1,-2},{-2,-1},{2,1}};

        component.push_back(make_pair(x, y));

        visited[x][y]=true;


 

        for(int k =0; k <8; k++){

            int nextX =(x+dir[k][0]);

            int nextY =(y+dir[k][1]);

            if(nextX >=0&& nextX < n && nextY >=0&& nextY < m &&visited[nextX][nextY]==false&&chess[nextX][nextY]==1){

                dfs(chess, visited, nextX, nextY, component, n, m);

            }

        }

}


 

int main(){

    int t;

    cin >> t;

    

    while(t--){

    long long n, m, q;

    cin >> n >> m >> q;

    int** chess =new int*[n];

    for(int i =0; i < n; i++){

        chess[i]=new int[m];

        for(int j =0; j < m; j++){

            chess[i][j]=0;

        }

    }


 

    for(int i =0; i < q; i++){

        int x, y;

        cin >> x >> y;

        chess[(x-1)][(y-1)]=1;

    }


 

    bool** visited =new bool*[n];

    for(int i =0; i < n; i++){

        visited[i]=new bool[m];

        for(int j =0; j < m; j++){

            visited[i][j]=false;

        }

    }


 

    long long finalAns =1;

    for(int i =0; i < n; i++){

        for(int j =0; j < m; j++){

            if(chess[i][j]==1&&visited[i][j]==false){

                vector<pair<int,int>> component;

                dfs(chess, visited, i, j, component, n, m);

                long long ans =factorial(component.size());

                finalAns  =(((finalAns%mod)*(ans%mod))%mod);

            }

        }

    }

cout << finalAns << endl;

    }

    return 0;

}
