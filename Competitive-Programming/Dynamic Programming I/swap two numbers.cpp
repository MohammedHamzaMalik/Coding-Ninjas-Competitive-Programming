//https://www.codingninjas.com/codestudio/problems/swap-two-numbers_1112577?leftPanelTab=0

/*Problem Statement
Take two number as input and swap them and print the swapped values.

Input Format
 
The first line of input contains a single integer 't', representing the total number of test cases.
The second line of inpt contains two integer 'a'and 'b', representing numbers

Output format:
the first line of output prints the swappes value of 'a'and'b'.

no need to print.

Constrains:
1<='T'<=10^2
-10^5<='a','b'<=10^5
time limit 1sec

Sample Input 1:
2
1 2 
3 4

Sample Output 1:
2 1
4 3


Explanation For Sample Input 1:
The output of the above test case is 2 1 for the first test case.
The output of the 2nd test case is 4 3.




Sample Input 2:
2
5 6
7 8

Sample Output 2:
6 5
8 7

Explanation For Sample Input 2:
The output of the above test case is  6 5 for the first test case.
The output of the 2nd test case is 8 7.
*/







#include <bits/stdc++.h> 
#include <utility>

pair < int, int > swap(pair < int, int > swapValues) {
    int* temp=new int ;
    *temp=swapValues.first;
    swapValues.first=swapValues.second;
    swapValues.second=*temp;
    delete temp;
    return swapValues;
}