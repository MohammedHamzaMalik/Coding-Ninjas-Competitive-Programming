/*
Arrangement
Send Feedback
You are given a number 'N'. Your goal is to find the number of permutations of the list 'A' = [1, 2, ......, N], satisfying either of the following conditions:
A[i] is divisible by i or i is divisible by A[i], for every 'i' from 1 to 'N'.
Input Format:
The first line of the input contains ‘T’ denoting the number of test cases.

The first line of each test case contains an integer N.
Output Format:
For each test case return the number of satisfying permutations in a new line.
Note:
You do not need to print anything or take input. This already has been taken care of. Just implement the function.
Constraints:
1 <= T <= 10
0 <= N <= 15

Time Limit: 1 sec
Sample Input 1:
2
1
2
Sample Output 1:
1
2
Explanation for Sample Input 1:
In test case 1:
The only permutation is A=[1]
    A[1] = 1 is divisible by i = 1

The permutation is satisfying the conditions therefore answer is 1

In test case 2:
The 1st permutation is A=[1,2]:
    A[1] = 1 is divisible by i = 1
    A[2] = 2 is divisible by i = 2
The 2nd permutation is A=[2,1]:
    A[1] = 2 is divisible by i = 1
    i = 2 is divisible by A[2] = 1

Both permutations are satisfying either of the conditions therefore answer is 2
Sample Input 2:
2
3
4
Sample Output 2:
3
8
*/



void calculate(int n, int pos, vector<bool>& visited, int& count){
        if(pos > n) count++;
        for(int i = 1; i <= n; ++i){
            if(!visited[i] && (pos % i == 0 || i%pos == 0)){
                visited[i] = true;
                calculate(n, pos+1, visited, count);
                visited[i] = false;
            }
        }
    }

int countArrangement(int n) {
      int count=0;
    vector<bool>vis(n+1,false);
     calculate(n, 1, vis, count);
    return count;
}
