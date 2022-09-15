#include<iostream>
using namespace std;


int main(){

       /*  Read input as specified in the question.
	* Print output as specified in the question.
	*/
    int S,E,W;
    cin>>S>>E>>W;
    for(int i=S;i<=E;i+=W){
        int C = 5 * (i-32)/9;
        cout<<i<<'\t'<<C<<endl;
    }
  
}


