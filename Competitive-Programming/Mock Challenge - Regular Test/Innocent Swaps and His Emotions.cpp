/*
Innocent Swaps and His Emotions
Send Feedback
There are only three phases in Swaps life: Sleep, Play and Study. Also, there are two types of emotions Swaps experiences: Happy and Sad. Each phase of his life brings either kind of emotions.
The sleep and the play phase makes Swaps happy whereas the study phase makes him sad. Quite obvious, isn't it? But we know that life isn't that great, one cannot be happy all the time.
Swaps, being a very sensitive guy, doesn't like to mix his emotions on a particular day. So each day, he is in exactly one of the three phases.
Given N which denotes the number of days and K which denotes the exact number of days Swaps needs to be happy out of these N days, can you tell him in how many ways can he achieve this? Since the output value can be very large, take modulo with 1000000007(10^9+7)
Input Format:
The first line of the input contains T, denoting the number of test cases.

The next T lines contain two space-separated integers N and K.
Constraints:
1 <=T <= 10^5
1<= K <= N <= 10^6
Output Format:
For each test-case, output a single integer, the number of ways modulo 1000000007(10^9+7).
Sample Input 1:
3
1 1
2 1
3 2
Sample Output 2:
2
4
12
Explanation
In the first test case, he needs to feel joyful on Day 1. Hence, answer is 2 (He can either play video games or sleep).

In the second test case, he can be joyful either on Day 1 or Day 2. So number of ways = 4.
*/



#include <bits/stdc++.h>

using namespace std;


 

#define int long long

#define pb push_back

// #define tc     \

//   long long t; \

//   cin >> t;    \

//   while (t--)

#define f(i, x) for (int i = 0; i < x; i++)

#define f1(i, x) for (int i = 1; i <= x; i++)

#define fast std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

#define ff first

#define ss second

#define vi vector<int>

#define vvi vector<vector<int>>

#define mod 1000000007

#define nl cout << "\n"

const int N=1e6+10;


 

int fact[N];


 

int binExp(int a, int b, int m)

{

  a%=m;

  int ans = 1;

  while (b)

  {

    if (b & 1)

    {

      ans = (ans * 1LL * a) % m;

    }

    a = (a * 1LL * a) % m;

    b >>= 1;

  }

  return ans;

}


 

void solve(){

  int n,k;

  cin>>n>>k;

  int a=binExp(2,k,mod);

  int num=fact[n];

  int den=(fact[n-k]*fact[k])%mod;

  num=(num*binExp(den,mod-2,mod))%mod;


 

  cout<<(num*a)%mod;

  nl;


 

}


 

signed main()

{

  fast;

  fact[0]=fact[1]=1;

  for(int i=2; i<N; i++){

    fact[i]=(fact[i-1]*i)%mod;

  }

   long long t; 

  cin >> t;    

  while (t--){

    solve();

  }

}
