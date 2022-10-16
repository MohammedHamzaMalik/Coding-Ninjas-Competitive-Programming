// Problem Link => https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118820/offering/1381870

/*
Problem Statement:

You are given an array (ARR) of length N, consisting of integers. 
You have to find the sum of the subarray (including empty subarray) 
having maximum sum among all subarrays. A subarray is a contiguous 
segment of an array. In other words, a subarray can be formed by 
removing 0 or more integers from the beginning, and 0 or more 
integers from the end of an array.

Input Format:

The first line of input carries an integer N, representing the length
of the array.
The second line of input contains N single space-separated integers,
denoting the elements of the array.

Output Format:

In the output line, output the maximum subarray sum.

Constraints:

1 <= N <= 10^6
-10^6 <= A[i] <= 10^6
where, N => length of the array
A[i] => numbers present in the array

Time Limit: 1 sec

Sample Input 1 :
9
1 2 7 -4 3 2 -10 9 1
Sample Output 1 :
11

Explanation For Sample 1 :
The subarray yielding maximum sum is [1, 2, 7, -4, 3, 2].


Sample Input 2 :
6
10 20 -30 40 -50 60
Sample Onput 2 :
60

Sample Input 3 :
3
-3 -5 -6
Sample Onput 3 :
0

*/

#include <bits/stdc++.h> 
long long maxSubarraySum(int arr[], int n)
{
    
    long long int sum=0;
    long long int maxSum=INT_MIN;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        maxSum=max(maxSum,sum);
        if(sum<0){
            sum=0;
        }
    }
    if(maxSum<0){
        return 0;
    }
    return maxSum;
}