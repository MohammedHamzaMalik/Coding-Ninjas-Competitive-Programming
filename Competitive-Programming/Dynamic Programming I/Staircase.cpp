/*
Staircase
Send Feedback
A child is running up a staircase with n steps and can hop either 1 step, 2 steps or 3 steps at a time. Implement a method to count how many possible ways the child can run up to the stairs. You need to return all possible number of ways.
Time complexity of your code should be O(n).
Since the answer can be pretty large print the answer % mod(10^9 +7)
Input Format:
First line will contain T (number of test case).
Each test case is consists of a single line containing an integer N.
Output Format:
For each test case print the answer in new line
Constraints :
1 <= T < = 10
1 <= N <= 10^5
Sample input 1
2
2
3
Sample output 1
2
4
Explanation of sample input 1:
Test case 1:
To reach at top of 2nd stair, we have only two options i.e (2), (1,1)

Test case 2:
 To reach at top of 3rd stair, we have four options i.e (1,1,1), (1,2) ,(2,1), (3)
Sample input 2:
2
5
10
Sample output 2:
13
274
*/



#include<bits/stdc++.h>
using namespace std;
long long int staircase(long long int n, long long int *arr=new long long int[71]()){
    /*  Don't write main().
     *  Don't read input, it is passed as function argument.
     *  Return output and don't print it.
     *  Taking input and printing output is handled automatically.
     */
    if(n==1)
    {
        return 1;
    }
    if(n==0)
    {
        return 1;
    }
    if(n==2)
    {
        return 2;
    }
    if(arr[n]>0)
    {
        return arr[n];
    }
    long long int steps_3=staircase(n-3, arr);
    long long int steps_2=staircase(n-2, arr);
    long long int step_1=staircase(n-1, arr);
    long long int ans=step_1+steps_2+steps_3;
    arr[n-1]=step_1;
    arr[n-2]=steps_2;
    arr[n-3]=steps_3;
    arr[n]=ans;
    return ans;
}
int main(){
 	int t;cin>>t;
    while(t--){
        long long int n;
        cin>>n;
        long long int ans=staircase(n);
        cout<<ans<<"\n";
    }
    // write your code here
    return 0;
}
