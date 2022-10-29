/*
Loot Houses

Loot Houses
Send Feedback
A thief wants to loot houses. He knows the amount of money in each house. He cannot loot two consecutive houses. Find the maximum amount of money he can loot.
Input format :
The first line of input contains an integer value of 'n'. It is the total number of houses.

The second line of input contains 'n' integer values separated by a single space denoting the amount of money each house has.
Output format :
Print the the maximum money that can be looted.
Constraints :
0 <= n <= 10 ^ 4

Time Limit: 1 sec
Sample Input 1 :
6
5 5 10 100 10 5
Sample Output 1 :
110
Sample Input 2 :
6
10 2 30 20 3 50
Sample Output 2 :
90
Explanation of Sample Output 2 :
Looting first, third, and the last houses([10 + 30 + 50]) will result in the maximum loot, and all the other possible combinations would result in less than 90.
*/



// int maxMoneyLooted(int *arr, int n)
// {
// 	//Write your code here
// }
#include<iostream>
#include<algorithm>
using namespace std;
int maxMoneyLooted(int arr[], int n, int i=0, int *temp=new int[10002]()){

	/*Write your code here.
	 *Don’t write main(). 
	 *Don’t take input, it is passed as function argument.
	 *Don’t print output.
	 *Taking input and printing output is handled automatically.
         */ 
    if(i>=n)
	{
		return 0;
	}
    if(temp[i]>0)
    {
        return temp[i];
    }
	int maximum=0;
	int including=arr[i]+maxMoneyLooted(arr, n, i+2, temp);
	int not_including=maxMoneyLooted(arr,n, i+1, temp);
	maximum=max(including, not_including);
    temp[i]=maximum;
	return maximum;
}
