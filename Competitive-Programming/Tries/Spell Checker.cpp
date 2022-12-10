/*
Spell Checker
Send Feedback
You are given a list of strings, ‘DICTIONARY[]’ that represents the correct spelling of words and a query string ‘QUERY’ that may have incorrect spelling. You have to check whether the spelling of the string ‘QUERY’ is correct or not. If not, then return the list of suggestions from the list ‘DICTIONARY’. Otherwise, return an empty list which will be internally interpreted as the correct string.
Note:
1) The suggested correct strings for the string  ‘QUERY’ will be all those strings present in the ‘DICTIONARY[]’ that have the prefix same as the longest prefix of string ‘QUERY’.

2) The ‘DICTIONARY[]’ contains only distinct strings.
For example:
Given 'DICTIONARY[]' = {“ninja”, “ninjas”, “nineteen”, “ninny”} and query = “ninjk”. Since “ninjk” is not present in the ‘DICTIONARY[]’, it is an incorrect string. The suggested current spellings for “ninjk” are “ninja” and “ninjas”. It is because “ninj” is the longest prefix of “ninjk” which is present as the prefix in ‘DICTIONARY’.
Input Format
The first line of input contains an integer 'T' representing the number of test cases.

The first line of each test case contains an integer ‘N’ representing the number of strings in the list, ‘DICTIONARY[].’

The second line of each test case contains ‘N’ space separated strings present in the list, ‘DICTIONARY[]’.

The last line of each test case contains the ‘QUERY’ string.
Output Format:
For each test case, return a list of strings containing all suggested correct spellings from the list, ‘DICTIONARY[]’, if the spelling of the ‘query’ string is incorrect. Otherwise, return an empty list that will be internally interpreted as the correct string and will print “CORRECT”.

The output of each test case will be printed in a separate line.
Note:
You do not need to print anything, it has already been taken care of. Just implement the given function.
Constraints:
1 <= T <= 5
1 <= N <= 100
1 <= |DICTIONARY[i]| <= 100
1 <= |QUERY| <= 100
‘DICTIONARY[i]’ and ‘QUERY’ contains only lowercase english letters.

Where ‘|DICTIONARY[i]|’ is the length of the string in the list ‘DICTIONARY' and ‘|QUERY|’ is the length of the ‘QUERY’ string.

Time limit: 1 sec
Sample Input 1:
2
5
class coder coding college ninjas
spell
4
code with coding ninjas
ninjas
Sample Output 1:
class coder coding college ninjas 
CORRECT
Explanation for Sample Output 1:
In test case 1, Given 'DICTIONARY[]' = {"class", "coder", "coding", "college", "ninjas"} and 'QUERY' = “spell”. ‘QUERY’ string is incorrect as it is not present in the ‘DICTIONARY[]’. The longest prefix which is also present as the prefix in ‘DICTIONARY’ is “”, i.e., empty string.

So, all the strings of ‘DICTIONARY’ will be considered as the correct suggested spellings. 

Therefore, the output is "class", "coder", "coding", "college" and "ninjas".

In test case 2, Given 'DICTIONARY[]' = {“code”, “with”, “coding”, “ninjas”} and 'QUERY' = “ninjas”. Since the ‘QUERY’ string is present in the dictionary, its spelling is correct. Thus, at the output, ‘CORRECT’ is printed.
Sample Input 2:
2
6
abcde abfd abcxyp mnbs aaaa pkl
abc
5
abc def ghi jkl mnop
pqr
Sample Output 2:
abcde abcxyp
abc def ghi jkl mnop
Explanation for Sample Output 2:
In test case 1, Given 'DICTIONARY[]' = {"abcde ", "abfd", "abcxyp", "mnbs", "aaaa", "pkl"} and 'QUERY' = “abc”. ‘QUERY’ string is matched with "abcde" and "abcxyp" present in the ‘DICTIONARY[]’. 

So, "abcde" and "abcxyp" strings of ‘DICTIONARY’ will be considered as the correct suggested spellings. 

Therefore, the output is  "abcde" and "abcxyp".

In test case 2, Given 'DICTIONARY[]' = {"abc", "def", "ghi", "jkl", "mnop"} and 'QUERY' = “pqr”. ‘QUERY’ string is incorrect as it is not present in the ‘DICTIONARY[]’. The longest prefix which is also present as the prefix in ‘DICTIONARY’ is “”, i.e., empty string.

So, all the strings of ‘DICTIONARY’ will be considered as the correct suggested spellings. 

Therefore, the output is "abc", "def", "ghi", "jkl", "mnop".
*/



/*
    Time Complexity : O(N * M)
    Space Complexity : O(26 * N)

    Where 'N' is the number of strings in the 'DICTIONARY'.
    Where 'M' is the maximum length of the string present in the 'DICTIONARY'.
*/

// Trie Node.
struct Trie {
	Trie* child[26];
	bool isEnd;

	Trie(){
		for (int i = 0; i < 26; i++){
			child[i] = NULL;
		}
		isEnd = false;
	}
};

// Function to insert string, 'STR' in the 'Trie'.
void insert(Trie* root, string &str){
    int i = 0;

	while(i < str.length()){
        // Index of current character in 'Trie'.
        int index = str[i] - 'a';

        // Current character is not present.
		if (root->child[index] == NULL){
            // Create a new node for the current character.
			root->child[index] = new Trie();
		}
		root = root->child[index];
        i++;
	}

    // Mark the end of the string.
	root->isEnd = true;
}

// Function to find suggested correct spellings.
void findSuggestions(Trie* root, string possibleAnswer, vector<string> &res){
    // String 'possibleAnswer' is present as a complete string.
	if (root->isEnd == true){
		res.push_back(possibleAnswer);
        return;
	}

	for (int i = 0; i < 26; i++){
        // Character is present in the 'Trie'.
    	if (root->child[i] != NULL){  
            // Append the character to the 'possibleAnswer'.
        	possibleAnswer.push_back(i + 'a');

			findSuggestions(root->child[i], possibleAnswer, res);

            // Pop the last appended character.
			possibleAnswer.pop_back();
		}
	}
}

vector<string> spellChecker(vector<string> &dictionary, string &query){
    // Creating root node of 'Trie'.
    Trie* root = new Trie();

	for (int i = 0; i < dictionary.size(); i++){
		insert(root, dictionary[i]);
	}

    vector<string> result;

    for (int i = 0; i < query.length(); i++){
        // Index of current character in 'Trie'.
        int index = query[i] - 'a';

        // Current character is not present in the 'Trie'.
    	if (root->child[index] == NULL){
            // The substring of string 'query' before the current character is the longest prefix to be searched in 'dictionary'.
            string prefixQuery = query.substr(0, i);

			findSuggestions(root, prefixQuery, result);
            return result;
		}
		root = root->child[index];
	}
	
    // The string 'query' is present in the 'Trie'.
    if (root->isEnd == true){
		return result;
	}
	
    // Find suggested correct spellings for 'query' with prefix as whole string.
    findSuggestions(root, query, result);
    return result;
}
