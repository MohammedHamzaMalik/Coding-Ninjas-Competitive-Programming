//## Read input as specified in the question.
//## Print output as specified in the question.

#include<iostream>
using namespace std;

int main(){
    int n; 
    cin >> n;
    for(int i = 1; i <= n; i++){
        int count = 0;
        for(int j = 1; j <= n; j++){
            if(j <= n-i){
                cout << "  ";
            } 
            else {
                cout << i + count << " ";
                count ++;
            }
        }
        cout << endl;
    }
    return 0;
}
