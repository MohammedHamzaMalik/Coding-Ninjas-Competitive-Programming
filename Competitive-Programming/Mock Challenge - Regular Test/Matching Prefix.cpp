/*
Matching Prefix
Send Feedback
You are given an integer ’N’ denoting the length of the array ‘Arr’ of strings made up of lower case English alphabets. The cost of this array is equal to the sum of length of each string in the array.
You can select a new string ‘S’ of length ‘N’, you are now allowed to delete the prefix from the strings in the array (This leads to lowering the cost of the array), the deleted prefix should be exactly the same as the selected string ‘S.
Find the string ‘S’ such that the cost of the array ‘Arr’ is minimized. If multiple strings exist, then find the lexicographically smallest string amongst them.
For Example :
If the array of strings is: {co, code, studio, codingninjas, coding, debug, coder, cipher} 
Then the original cost of the array is 2 + 4 + 6 + 12 + 6 + 5 + 5 + 6 = 46.

If we select the new string as “cod” and delete the matching prefixes if exists then the array becomes: {co, e, studio, ingninjas, ing, debug, er, cipher}, and the cost now becomes: 2 + 1 + 6 + 9 + 3 + 5 + 2 + 6 = 34.

You can check for any other possible string, the cost will not become less than 34, hence the optimal answer for this case is “cod”.
Input Format :
The first line contains a single integer ‘T’ denoting the number of test cases, then each test case follows:

The first line of each test case contains a single integer ‘N’ denoting the length of the array of strings.

The next N lines each contain ‘Arr[i]’ consisting of lower case English alphabets, denoting the ith string in the array.
Output Format :
For each test case, print the string which minimizes the cost of the array of deletion of common prefixes.

Output for each test case will be printed in a separate line.
Note :
You are not required to print anything; it has already been taken care of. Just implement the function.
Constraints :
1 <= T <= 10      
1 <= N <= 20
1 <= Arr[i].length <= 20

Time limit: 1 sec
Sample Input 1 :
2
8
co
code
studio
codingninjas
coding
debug
coder
cipher
3
cat
bat
rat
Sample Output 1 :
cod
bat
Explanation For Sample Input 1 :
For test case 1 :
If we choose a string as “cod” and delete the matching prefixes from the array of strings, then the array becomes:  {“co”, “e”, “studio”, “ingninjas”, “ing”, “debug”, “er”, “cipher”}.
Cost of this array is: 2 + 1 + 6 + 9 + 3 + 5 + 2 + 6 = 34, this is the lowest possible cost we can get.

For test case 2 :
If we choose a string as “bat” and delete the matching prefixes from the array of strings, then the array becomes: { “cat”, “”, “rat” }, the cost of this array is 3 + 0 + 3 = 6.
If we choose “cat” or “rat” then also we will have the cost equal to 6, but we need to return the lexicographically shortest string if multiple outputs are possible, hence we return “bat”.
Sample Input 2 :
2
1
ninjacoder
2
rabbit
robot
Sample Output 2 :
ninjacoder
rabbit
*/



/*
    Time Complexity: O( N^2 * L^2 )
    Space Complexity: O(1)

    where  N and L denotes the number of strings and the maximum length of string respectively
*/

string matchingPrefix(int n, vector < string > arr) {

   // Initialize minCost to store minimum cost
   int minCost = INT_MAX;

   // Initialize ans to store the string to be returned
   string ans;

   // Iterate each string
   for (int i = 0; i < n; i++) {

      // Iterating each charachter of the string
      for (int j = 0; j < arr[i].size(); j++) {

         // Variable to store the the current cost
         int curCost = 0;

         // Variable to store current length of prefix string
         int len = j + 1;

         // Current prefix string 
         string prefixStr = arr[i].substr(0, len);

         // Iterate each string
         for (int k = 0; k < n; k++) {

            // Increment current cost with length of string
            curCost += arr[k].size();

            // Checking if the size of string is atleast 'len'
            if (arr[k].size() >= len) {

               // New prefix string of length equal to 'len'
               string newStr = arr[k].substr(0, len);

               if (newStr == prefixStr) {

                  // Matching prefix string found
                  curCost -= len;

               }
            }
         }

         // Updating the answer if a lower cost is found
         if (curCost < minCost) {
            minCost = curCost;
            ans = prefixStr;
         }

         // Updating the answer if a lexicographically smaller string is found
         if (curCost == minCost) {
            if (ans > prefixStr) ans = prefixStr;
         }

      }
   }

   return ans;
}
