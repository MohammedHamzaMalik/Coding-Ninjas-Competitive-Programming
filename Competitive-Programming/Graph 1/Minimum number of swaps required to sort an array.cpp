/*
Minimum number of swaps required to sort an array
Send Feedback
You have been given an array 'ARR' of 'N' distinct elements.
Your task is to find the minimum no. of swaps required to sort the array.
For example:
For the given input array [4, 3, 2, 1], the minimum no. of swaps required to sort the array is 2, i.e. swap index 0 with 3 and 1 with 2 to form the sorted array [1, 2, 3, 4].
Input Format:
The first line of input contains an integer ‘T’ representing the number of test cases. Then the test cases follow.

The first line of each test case contains an integer ‘N’ representing the size of the input array.

The second line of each test case contains the 'N' elements of the array separated by a single space.
Output Format:
For each test case, print a single line containing a single integer which represents the minimum no. of swaps required to sort the array.

The output for each test case is in a separate line.
Note:
You do not need to print anything; it has already been taken care of. Just implement the given function.
Constraints:
1 <= T <= 100
1 <= N <= 1000
0 <= ARR[i] <= 10 ^ 9

Where 'ARR[i]' is the value of the input array elements.

Time Limit: 1 sec
Sample Input 1:
2
4
4 3 2 1
5
1 5 4 3 2
Sample Output 1:
2
2
Explanation of Sample Input 1:
For the first test case, swap index 0 with 3 i.e. 4 -> 1 and 1 with 2 i.e. 3 -> 2 to form the sorted array {1, 2, 3, 4}.

For the second test case, swap index 1 with 4 i.e. 5 -> 2 and 2 with 3 i.e. 4 -> 3 to form the sorted array {1, 2, 3, 4, 5}.
Sample Input 2:
2
4
1 2 3 4
6
3 5 2 4 6 8
Sample Output 2:
0
3
*/



/*
    Time complexity: O(N * Log(N))
    Space complexity: O(N)

    where 'N' is the size of the given array.

*/

// Returns the minimum number of swaps required to sort the array.
int minSwaps(vector<int> &arr) {
  int count = 0;
  vector<int> temp = arr;

  sort(temp.begin(), temp.end());

  // Hashmap to store the indexes of the input array.
  unordered_map<int, int> map;

  for (int i = 0; i < arr.size(); i++) {
    map[arr[i]] = i;
  }

  for (int i = 0; i < arr.size(); i++) {
    /*
        Checking whether the current element
        is at the right place or not.
    */
    if (arr[i] != temp[i]) {
      count++;
      int init = arr[i];
      /*
          If not, swap this element with the index
          of the element which should come here.
      */
      swap(arr[i], arr[map[temp[i]]]);

      // Update the indexes in the hashmap accordingly.
      map[init] = map[temp[i]];
      map[temp[i]] = i;
    }
  }

  return count;
}
