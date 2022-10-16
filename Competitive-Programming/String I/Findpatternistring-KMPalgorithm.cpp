/*
Finding pattern in string using KMP Algorithm
Send Feedback
Given two strings P ans S consisting of lowercase english letters, find whether P is preent in S as a substring or not.
Input format :
The first line of input contains a single interger T representing test cases.
Next and only line of each test case contains two space separated strings P and S consisting of only lowercase english letters.
Output format :
For each test case print YES if string P is present in string S ,otherwise NO.
Constraints :
1<= T <= 100
1 <= |S| <= 10000
1 <= |P| < |S|
Time Limit: 1 sec
Sample Input 1 :
3
xxy yxxyxxy
a baac
cfg cgfgfc
Sample Output 1 :
YES
YES
NO
Sample Input 2 :
3
bbb abba
iqw hdhhdqoa
car caribbean
Sample Output 2 :
NO
NO
YES
Explanation to Sample Input 1:
In the first test case, there are two substrings equal to P on index 1 and 4 in S.

In the second test case, there are two substrings equal to P on indexes 1 and 2 in S.
In the third test case, P does not exist in S.
*/

#include<bits/stdc++.h>
using namespace std;

void getLps(string p, vector<int> &lps) 
{
    int len = 0;
    int index = 1;
    int m = p.size();

    while (index < m)
    {
        if (p[index] == p[len])
        {
            len += 1;
            lps[index] = len;
            index += 1;
        }

        else
        {
            if (len == 0)
            {
                lps[index] = 0;
                index += 1;
            }

            else
            {
                
                len = lps[len - 1]; 
            }
        }
    }
}

void solve()
{
    string p,s;
    cin>>p>>s;
    int m = p.size();
    int n = s.size();
    vector<int> lps(m, 0);

    getLps(p, lps);
    int index1 = 0;
    int index2 = 0;

    while (index1 < n)
    {
        if (s[index1] == p[index2])
        {
            index2++;
            index1++;
            if (index2 == m)
            {
                cout<<"YES"<<endl;
                return;
            }

            if (index1 == n)
            {
                cout<<"NO"<<endl;
                return;
            }
        }
        else
        {
            if (index2 == 0)
            {
                index1 += 1;
            }
            else
            {
                index2 = lps[index2 - 1];
            }
        }
    }

    cout<<"NO"<<endl;
    return;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}