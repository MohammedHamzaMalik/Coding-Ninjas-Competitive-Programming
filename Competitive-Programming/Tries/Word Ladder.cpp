/*
Word Ladder
Send Feedback
You are given two strings BEGIN and END and an array of strings DICT. Your task is to find the length of the shortest transformation sequence from BEGIN to END such that in every transformation you can change exactly one alphabet and the word formed after each transformation must exist in DICT.
Note:
1. If there is no possible path to change BEGIN to END then just return -1.
2. All the words have the same length and contain only lowercase english alphabets.
3. The beginning word i.e. BEGIN will always be different from the end word i.e. END (BEGIN != END).
Input format :
The first line of input contains an integer ‘T’ denoting the number of test cases.

The first line of each test case contains a string BEGIN.

The second line of each test case contains a string END.

The third line of each test case contains a single integer N denoting the length of the DICT i.e. the array of strings.

The fourth line of each test case contains N space-separated strings denoting the strings present in the DICT array.
Output format :
For each test case, print a single integer representing the length of the shortest transformation sequence from BEGIN to END. 

The output of each test case will be printed in a separate line.
Note:
You don’t have to print anything; it has already been taken care of. Just implement the given function.
Constraints:
1 <= T <= 5
1 <= N<= 10^2
1 <= |S| <= 10^2

Where ‘T’ is the total number of test cases, ‘N’ denotes the length of the DICT array and |S| represents the length of each string.
Sample Input 1 :
1
goa
pro
5
poa pro bro say pra
Sample Output 1 :
4
Explanation of The Sample Input 1:
For the first test case:
The given BEGIN word is ‘goa’ and the target word is ‘pro’ and the array we have  is [poa, pro, bro, say, pra ].o firstly we can move from ‘goa’ to ‘poa’ after that we can move from ‘poa’ to ‘pra’ and finally we can move from ‘pra’ to ‘pro’.
Like the series "goa" -> "poa" -> "pra" -> "pro" therefore the length of the shortest transformation sequence from ‘goa’ to ‘pro’ will be 4. 
Sample Input 2 :
3
feed
prrq
8
pbvd tvgj perd peed prwq feeq prrd prrq 
abc
efg
5
abg afg efg acd bgk 
bcm
lpq
6
dfg acx teg qwq xcv ujy 
Sample Output 2 :
5
4
-1
*/



/*
    Time Complexity: O(N * |S| * 26)
    Space complexity: O(N)

    Where 'N' denotes the length of the DICT and |S| is the length of each string.
*/

#include<bits/stdc++.h>

int wordLadder(string & begin, string & end, vector < string > & dict) {

    int depth = 1;
    unordered_set < string > set(dict.begin(), dict.end());

    // If the end word is not present then just return form here.
    if (set.count(end) == 0) return -1;

    unordered_set < string > beginSet, endSet;
    int len = beginSet.size();
    unordered_set < string > visited;
    beginSet.insert(begin);
    endSet.insert(end);

    // Start the BSF from both sides.
    while (!beginSet.empty() && !endSet.empty()) {
        if (beginSet.size() > endSet.size()) {
            unordered_set < string > temp = beginSet;
            beginSet = endSet;
            endSet = temp;
        }
        unordered_set < string > temp;

        // Check for each word in the begin set.
        for (string word: beginSet) {
            // For finding the adjacent words.
            for (int i = 0; i < word.size(); i++) {
                /* 
                	Make a new word by adding chararcters and
                    check if it is present in dict.
                */
                for (char c = 'a'; c <= 'z'; c++) {
                    char old = word[i];
                    word[i] = c;
                    if (endSet.count(word) != 0) {
                        return depth + 1;
                    }
                    if (visited.count(word) == 0 && set.count(word) != 0) {
                        temp.insert(word);
                        visited.insert(word);
                    }
                    word[i] = old;
                }
            }
        }
        beginSet = temp;
        depth++;
    }
    return -1;
}
