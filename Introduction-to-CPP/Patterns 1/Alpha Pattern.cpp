#include<iostream>
using namespace std;


int main(){
    
    /*  Read input as specified in the question.
     * Print output as specified in the question.
     */
    int n;
    cin>>n;
    int ascii=65;
    int i=1;
    while(i<=n){
        int j=1;
        while(j<=i){
            cout<<char(ascii);
            j+=1;
        }
        i+=1;
        ascii+=1;
        cout<<"\n";
    }
    
}

