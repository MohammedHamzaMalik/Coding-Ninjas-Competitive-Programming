/*
NINJA ATTACK
Send Feedback
Ninja has built his team of ninjas to fight with the enemies in his city. Ninja made a plan of attacking all his enemies. In his team, every ninja has his own range of hitting and they had secretly got the hitting range of their enemies as well. So Ninja allowed some swaps between his ninjas so that they can minimize the hamming distance that is the number of positions where the hitting range of enemies and ninjas are different.
Your task is to write a code that can minimize the hamming distance. You are being provided with two arrays ‘ninja’ and ‘enemies’ both of the same size and an array ‘allowedSwaps’ where each allowedSwaps[i] = [ ai, bi ] indicates that you are allowed to swap the elements at index ai and index bi.
The Hamming distance of two arrays of the same length, ninja, and enemies, is the number of positions where the elements are different.
Example :
Consider the case ‘ninja’array is [ 1, 2, 3, 4 ], ‘enemies’array is [ 2, 1, 4, 5 ] and ‘allowedSwaps’ are  = [ [ 0, 1 ], [ 2, 3 ] ] so after swapping in best manner according to ‘allowedSwaps’ our ‘ninja’ array becomes [ 2, 1, 4, 3 ]. So minimum Hamming distance is ‘1’ as now there is only one different element as compared to ‘ninja’ and ‘enemies’ array index.
Note :
1. You are allowed to do as many swap operations on the ‘ninja’ array as you want but according to the ‘allowedSwap’ array.
2. You are not required to print anything explicitly. It has already been taken care of. Just implement the function.
Input Format :
The first line of input contains a ‘T’ number of test cases.

The first line of each test case contains an integer ‘n’, which represents the size of the array ‘ninja’ and ‘enemies’.

The second line of each test case contains the ‘n’ space-separated integer of array ‘ninja’.

The third line of each test case contains the ‘n’ space-separated integer of array ‘enemies’.

The fourth line of each test case contains an integer ‘m’ denoting the number of rows in array ‘allowedSwap’. Then, ‘m’ lines follow.

Each line contains two space-separated integers denoting the array values.
Output Format :
For each test case, return the minimum hamming distance of the ‘ninja’ and ‘enemies’ array.
Constraints :
1 <= T <= 100
1 <= N <=  10^3
1 <= ninja[i], enemies[i] < 10^5
0 <= allowedSwaps[i] <=10^5      

Where ‘T’ represents the number of test cases, ‘N’ represents the size of the ‘ninja’ and ‘enemies’ array and ninja[i], enemies[i], and allowedSwaps[i] represents the element in the array.

Time Limit: 1 second    
Sample Input 1 :
2
4
1 2 3 4
2 1 4 5
2
0 1
2 3
4
1 2 3 4
1 3 2 4
1
2 3
Sample Output 1 :
1
2
Explanation of Sample Input 1 :
Test Case 1:

Before the swapping hamming distance is ‘2’ because in these arrays ‘2’ index has different elements.
So according to this test case, ‘ninja’ = [ 1, 2, 3, 4 ], ‘enemies’ = [ 2, 1, 4, 5 ] and ‘allowedSwaps’ = [ [ 0, 1 ], [ 2, 3 ] ] so after swapping in best manner according to ‘allowedSwaps’ our ‘ninja’ array becomes [ 2, 1, 4, 3 ] so minimum Hamming distance is ‘1’ as now there is only one different element as compared to ‘ninja’ and ‘enemies’ array index.

Test Case 2:

So according to this test case, ‘ninja’ = [ 1, 2, 3, 4 ], ‘enemies’ = [ 1, 3, 2, 4 ], and even after swapping the minimum Hamming distance is ‘2’ as there are ‘2’  different element as compared to ‘ninja’ and ‘enemies’ array index.
Sample Input 2 :
2
5
5 1 2 4 3
1 5 4 2 3
4
0 4
4 2
1 3
1 4  
3
1 2 3
3 1 2
0
Sample Output 2 :
0
3
*/



/*
    Time complexity: O(N * Log(N) )
    Space complexity: O(N) 

    Where N represents the size of given array.
*/

vector<int> parent;

void makeSet()
{
    for (int i = 0; i < parent.size(); i++)
    {
        parent[i] = i;
    }
}

int findSet(int a)
{
    return (a == parent[a]) ? a : (parent[a] = findSet(parent[a]));
}

void unionSet(int a, int b)
{
    a = findSet(a), b = findSet(b);

    if (a != b)
    {
        parent[a] = b;
    }
}

int calc(vector<int> &a, vector<int> &b)
{
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int dis = 0, i = 0, j = 0, sz = a.size();

    while (i < sz && j < sz)
    {
        if (a[i] == b[j])
        {
            dis += 1;
            i++, j++;
        }
        else if (a[i] > b[j])
        {
            j++;
        }
        else
        {
            i++;
        }
    }

    return dis;
}

int ninjaAttack(vector<int> ninja, vector<int> enemies, vector<vector<int>> allowedSwaps)
{
    int n = ninja.size(), dis = 0;
    vector<vector<int>> setWiseNinja(n, vector<int>()), setWiseEnemies(n, vector<int>());
    parent.assign(n, 0);
    makeSet();

    for (auto s : allowedSwaps)
    {
        unionSet(s[0], s[1]);
    }

    // arrange the elements set wise
    for (int i = 0; i < n; i++)
    {
        int j = findSet(i);
        setWiseNinja[j].push_back(ninja[i]);
        setWiseEnemies[j].push_back(enemies[i]);
    }

    // go over to each set and compare
    for (int i = 0; i < n; i++)
    {
        dis += calc(setWiseNinja[i], setWiseEnemies[i]);
    }

    return n - dis;
}
