#include<iostream>
using namespace std;


int main(){

       /*  Read input as specified in the question.
	* Print output as specified in the question.
	*/
    int n;
    cin>>n;
    int num=1;
    for(int i=n;i>0;i--){
        for(int j=i;j<=n;j++){
            cout<<num;
        }
        num+=1;
        cout<<"\n";
    }
  
}


