#include<iostream>
using namespace std;


int main(){

       /*  Read input as specified in the question.
	* Print output as specified in the question.
	*/
    int n;
    cin>>n;
    for(int i=n;i>0;i--){
        for(int j=i;j<=n;j++){
            cout<<"*";
        }
        cout<<"\n";
    }
  
}


