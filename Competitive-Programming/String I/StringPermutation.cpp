/*
Permutations of a string
Send Feedback
Given a string str consisting of lowercase english letters, return all permutations of a string in lexographically increasung order.
Input format :
The first line of input contains a single interger T representing test cases.
Next and only line of each test case contains a string str consisting of only lowercase english letters.
Output format :
For each test case, the permutations of the given string are printed in lexicographically increasing order separated by space. The output of each test case is printed in a separate line.
Constraints :
1<= T <= 5
1 <= |str| <= 9
Time Limit: 1 sec
Sample Input 1 :
3
abc
bc
c
Sample Output 1 :
abc acb bac bca cab cba
bc cb
c
Sample Input 2 :
1
xyz
Sample Output 2 :
xyz xzy yxz yzx zxy zyx
Explanation to Sample Input 1:
In the 1st test case, there are 6 permutations of the given string.
In the 2nd test case, there are 2 permutations of the given string.
In the 3rd test case, there is only 1 permutation of the given string.
*/

#include<bits/stdc++.h>
using namespace std;

vector<string> Permutations(string &str)
{
    vector<string> ans;
    sort(str.begin(), str.end());
    while (1)
    {
        ans.push_back(str);

        int first = -1;
        for (int i = str.size() - 2; i >= 0; i--)
        {
            if (str[i] < str[i + 1])
            {
                first = i;
                break;
            }
        }

        if (first == -1) break;

        int second = first + 1;
        for (int i = first + 2; i < str.size(); i++)
        {
            if (str[i] > str[first] && str[i] < str[second])
            {
                second = i;
            }
        }

        swap(str[first], str[second]);
        reverse(str.begin() + first + 1, str.end());
    }

    return ans;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        vector<string>v=Permutations(str);
        for(auto it:v){
            cout<<it<<" ";
        }
        cout<<endl;
    }
}