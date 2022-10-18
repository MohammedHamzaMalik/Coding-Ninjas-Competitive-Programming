// Problem Link ->https://www.codingninjas.com/codestudio/guided-paths/competitive-programming/content/148628/offering/1792849?leftPanelTab=0




// You have been given an unsorted array 'ARR'.
// Your task is to sort the array in such a way that the array looks like a wave array.

//  Example:
//    If the given sequence 'ARR' has 'N' elements then the sorted wave array
//    looks like -
//    'ARR[] >= ARR[1]' and 'ARR[1] <= ARR[2]'
//    'ARR[2] >= ARR[3]' and 'ARR[3] <= ARR[4]'
//    'ARR[4] >= ARR[5]' and 'ARR[5] <= ARR[6]' And so on.

// Idea -> To look like a wave if we can put all maximun to up part nd all minimum to lower part ,then the array
//  will look like a wave . To do this we can just simply sort the array and swap the adjacent 2 numbers.

#include <bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+n);

    
    for (int i = 0; i < n; i += 2) {
        
        if (i != n - 1) {
            // Swap elements.
            swap(arr[i], arr[i + 1]);
        }
    }

    for (int i = 0; i < n; i++)
    {
       cout<<arr[i]<<" ";
    }
    
    

}