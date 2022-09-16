/*
Code : Mirror Number Pattern
Send Feedback
Print the following pattern for the given N number of rows.
Pattern for N = 4




The dots represent spaces.


Input format :
Integer N (Total no. of rows)
Output format :
Pattern in N lines
Constraints
0 <= N <= 50
Sample Input 1:
3
Sample Output 1:
      1 
    12
  123
Sample Input 2:
4
Sample Output 2:
      1 
    12
  123
1234
*/


#include<iostream>
using namespace std;


int main(){

       /*  Read input as specified in the question.
	* Print output as specified in the question.
	*/
    int n;
    cin>>n;
    int i=1;
    while(i<=n){
        int start=1;
        int j=1;
        while(j<=n-i){
            cout<<" ";
            j+=1;
        }
        while(j<=n){
            cout<<start;
            start+=1;
            j+=1;
        }
        cout<<"\n";
        i+=1;
    }
  
}


