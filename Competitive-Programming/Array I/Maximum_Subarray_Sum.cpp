// Problem Link => https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118820/offering/1381870

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