/*
Justify Text
Send Feedback
Given a sentence(in the form of an array of words), and an integer ‘L’, return an array of strings i.e a paragraph such that each line has exactly ‘L’ characters, and is left and right justified.
Justification of text means that space is added between words so that both edges of each line are aligned with both margins. The last line in the paragraph is aligned left.
One needs to add the maximum number of words in a line such that the number of lines is minimised.
We can add whitespaces in a line so that each line has exactly the same number of characters i.e L.
If the number of spaces on a line does not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.
For the last line of text, it should be left justified and no extra space is inserted between words.
For example:
Let the given sentence be: [ “what”, “must”, “be”, “shall”, “be.”]
And L=12.

The justified output will be :

[ “what must be”
“Shall be.”       ]

Note that the last line is only left justified.
Input Format:
The first line of input contains an integer ‘T’ representing the number of test cases. Then the test cases follow.
The first line of each test case contains a single integer ‘n’ denoting the number of words in the sentence.
The second line of each test case contains space separated strings denoting the word in the sentence. Note that no word has space in between it.
The third line of each test case contains the integer ‘L’ denoting the number of characters in each line in the justified output
Output Format:
For each test case, return an array of strings denoting the justified output of the given sentence.
The output for each test case is in a separate line.
Note:
1. You do not need to print anything; it has already been taken care of.
2. The words do not contain whitespaces.
3. It is guaranteed that L is always greater than the number of characters in any of the given words in the given array ‘words’
Constraints:
1 <= T <= 100
1 <= words.length <= 300
1 <= words[i].length <= 20
words[i] consists of only English letters and symbols.
1 <=L <= 100
words[i].length <= L


Where ‘T’ is the number of test cases, words.length denotes the number of words in the array and words[i].length denotes the number of alphabets in each word
L denotes the number of character in each line of the result.

Time Limit: 1 sec
Sample Input 1:
2
7
This is an example of text justification.
16
3
I like apple
6
Sample Output 1:
This    is    an
example  of text
justification. 
I like
apple 
Explanation of Sample Input 1:
For the first test case, 
We have 7 words in the sentence and we can have 16 characters in each line. So we will have the output as given above.
In each line we need 16 characters, we see that the first 3 words have 4+2+2 =8 characters and add 2 gaps. I.e 10 characters. now if we take one more word i.e example, we exceed the total number of characters in the line so we can take only 3 characters. We have 8 characters and 8 spaces. Which need to be distributed between 2 gaps. So each gap will have 4 spaces.

For the second test case, 
We have 3 words in the sentence and 6 characters in each line. So we will have output as given above
Sample Input 2:
2
9
When there is a will there is a way
10
4
Coding ninjas is great
10
Sample Output 2:
 When there
 is  a will
 there is a
 way
 Coding    
 ninjas  is
 great
 */



vector<string> fullJustify(vector<string> &words, int maxWidth) {
   // Write your code here
   int n = words.size();
vector<string> ans;  // ans vector
   
   int count = 0;   // keeps current count (characters + min in-b/w spaces)
   int spaces = 0;   // keeps count of in-between spaces  
   int extraSpaces = 0; // extra right-side spaces
   
   int j = 0;    // initialise outside
   for(int i=0;i<n;i++){ // iterate each word
       if(count+words[i].size()<=maxWidth){ // add till possible
           count += words[i].size() + 1; // +1 for in-b/w space
           spaces++;      // simple
       }
       else{   // here its not possible anymore to add in same line
           spaces--;   // ex -> 3 words == 2 spaces
           extraSpaces = maxWidth - count + 1;   // +1 for extra min-space counted for last word      
           string line = "";
           
           int eachSpace = 0;  // no of spaces each in-b/w space will get
           int extraLeft = 0;  // if no of extraspaces doesnt divide evenly between words
           string oneWord = ""; // for case where there is only 1 word, all extraspaces towards right
           if(spaces>0){
               eachSpace = extraSpaces/spaces; // simple logic
               extraLeft = extraSpaces%spaces;
           }
           else{ // one word only case
               while(extraSpaces!=0){
                   oneWord += " ";
                   extraSpaces--;
               }
           }
           // create space-string
           string sp = " "; // as there is already min-space present
           while(eachSpace!=0){
               sp += " ";   //simple
               eachSpace--;
           }

           while(spaces!=0){
               line += words[j] + sp; //simple
               if(extraLeft>0){ // extra towards left case
                   line += " ";
                   extraLeft--;
               }
               j++;   //simple
               spaces--;
           }
           line += words[j] + oneWord; // add last word and also oneWord case (right side spaces)
           
           j = i;   // beginning word of next line
           i--;  // as we arent adding current word yet
           count = 0;
           spaces = 0;  //reset
           ans.push_back(line);
       }
   }
   
//***********for last line**************    
   spaces--;
   extraSpaces = maxWidth - count + 1;
   string line = "";    
   while(spaces!=0){
       line += words[j] + " "; //only one space for last line
       j++;
       spaces--;
   }
   line += words[n-1];    
   while(extraSpaces!=0){ // as lastLine is left aligned
       line += " ";
       extraSpaces--;
   }
   ans.push_back(line);
//***************************************
   
   return ans;
}
