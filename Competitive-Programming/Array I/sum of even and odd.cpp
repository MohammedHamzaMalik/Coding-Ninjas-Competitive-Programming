/* problem statement
Write a program to input an integer N and print the sum of all its even digits and all its odd digits separately.

Digits Mean Numbers, Not The Places! If The Given Integer Is "13245", Even Digits Are 2 & 4, And Odd
Digits Are 1, 3 & 5.

Input Format:
The only line of input contains a single integer N.
  
Output Format:
Print first even sum and then odd sum separated by space.

Constraints
0 <= N <= 10^8

sample input 1:
1234
Sample Output 1:
6 4


Sample Input 2:
552245

Sample Output 2:
8 15

*/



#include <iostream>
using namespace std;

int main() {
    //Write your code here
    int even=0,odd=0;
   int n;
    cin>>n;
    while(n!=0){
        int *temp=new int;
        *temp=n%10;
        if(*temp%2==0){
            even+=*temp;
        }
 
    else{
        odd+=*temp;
    }
        delete temp;
        n/=10;
    }
    cout<<even<<" "<<odd;
    return 0;
}