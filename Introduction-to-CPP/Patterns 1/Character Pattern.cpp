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
        int j=1;
        int ascii='A'+i-1;
        while(j<=i){
            cout<<char(ascii);
            j+=1;
            ascii+=1;
        }
        i+=1;
        cout<<"\n";
    }
    
}

