/*
Evaluate Division
Send Feedback
You are given an array of pairs of strings 'EQUATIONS', and an array of real numbers 'VALUES'. Each element of the 'EQUATIONS' array denotes a fraction where the first string denotes the numerator variable and the second string denotes the denominator variable, and the corresponding element in 'VALUES' denotes the value this fraction is equal to.
You are given ‘Q’ queries, and each query consists of two strings representing the numerator and the denominator of a fraction. You have to return the value of the given fraction for each query. Return -1 if the value cannot be determined.
Example :
'EQUATIONS' = { {“a”, ”s”} , {“s”, “r”} }
'VALUES' = { 1.5, 2 }
queries = { {“a”, “r” } }

For the above example (a / s) = 1.5 and (s / r) = 2 therefore (a / r) = 1.5 * 2 = 3.
Input Format :
The first line contains a single integer ‘T’ denoting the number of test cases. The test cases are as follows.

The first line of each test case contains two integers, ‘N’ and ‘Q,’ separated by a single space denoting the number of the equations and the number of queries, respectively.

The second line of each test case contains ‘N’ strings denoting the numerator variable of the 'EQUATIONS'.

The third line of each test case contains ‘N’ strings denoting the denominator variable of the 'EQUATIONS'.

The fourth line of each test case contains ‘N’ real numbers denoting the 'VALUE' of each fraction.

The fifth line of each test case contains ‘Q’ strings denoting the numerator variable for each query.

The sixth line of each test case contains ‘Q’ strings denoting the denominator variable for each query. 
Output Format :
For each test case, return the value of the fraction up to 5 decimal places or -1 if the value of the fraction cannot be determined. All values are separated by a single space.

Your output will be considered correct if the relative error does not exceed 10^(-6).
Note :
You don’t need to print anything, It has already been taken care of. Just implement the given function.
Constraints :
1 <= T <= 50
1 <= N <= 100
1 <= Q <= 100
1 <= |S| <= 10
0.0 < values[i] <= 100.0

Where '|S|' denotes the length of the variables, and 'VALUES[i]' denotes the value of the i’th equation.

Time limit: 1 sec
Sample Input 1 :
2
2 1
a s
s r
1.5 2
a
r
3 2
a abc ab
x xyz xy
0.5 1 3.4
abc pqr
xyz rew    
Sample Output 1 :
3.00000
1.00000 -1.00000
Explanation of Sample Output 1 :
In test case 1, (a / s) = 1.5 and (s / r) = 2 therefore (a / r) = 1.5 * 2 = 3.

In test case 2, for the first query, the value of (abc / xyz) is given as 1, and the value of (pqr / rew) cannot be determined.
Sample Input 2 :
2
4 2
a r w p
r w p e
1.2 2.6 1 0.5
e a
p p
2 1
a x
b y
0.5 0.4
a
y
Sample Output 2 :
2.00000 3.12000
-1.00000 
Explanation of Sample Output 2 :
In test case 1, for the first query we have p / e = 0.5 ,therefore e / p = 1 / 0.5 = 2, for the second query (a / r) * (r / w) * (w / p) = a / p which is equal to 1.2 * 2.6 * 1 = 3.12.

In test case 2, we can not determine the value of the a / y, by the given set of equations. Thus return -1.
*/



#include<bits/stdc++.h>
class DSU{
private:
    
    vector<int> root;
    vector<int> rank;
    vector<double> mult;
    
public:
    
    DSU(int _size){
        for(int i = 0; i < _size; i++){
            root.push_back(i);
            rank.push_back(1);
            mult.push_back(1);
        }
    }
    
    // customized find to update mult[x] when we update root[x]
    pair<int, double> find(int x){
        if(x == root[x]) return {x , 1};
        int rootX;
        double multX;
        tie(rootX, multX) = find(root[x]);
        
        return {root[x] = rootX, mult[x] *= multX};
    }
    
    //customized union
    void unionSet(int x, int y, double div){
        int rootX = find(x).first;
        int rootY = find(y).first;
        
        if(rootX == rootY) return;
        
        if(rank[rootX] < rank[rootY]){
            root[rootX] = rootY;
            mult[rootX] = (mult[y] / mult[x]) * div;
        }
        else if(rank[rootX] > rank[rootY]){
            root[rootY] = rootX;
            mult[rootY] = mult[x] / (mult[y] * div);
        }
        else{
            root[rootX] = rootY;
            mult[rootX] = (mult[y] / mult[x]) * div;
            rank[rootY]++;
        }
    }
    
    bool isConnected(int x, int y){
        return find(x).first == find(y).first;   
    }
};

vector<double> evaluateEquations(vector<pair<string, string>> &equations, vector<pair<string, string>> &queries, vector<double> &values) {
    // Write your code here.
    int id = 0;
        vector<double> answers;
        // creating an id for each variable:
        unordered_map<string, int> ids;
        for(auto& equation : equations){
            if(ids.find(equation.first) == ids.end()) ids[equation.first] = id++;
            if(ids.find(equation.second) == ids.end()) ids[equation.second] = id++;
        }
        
        DSU dsu = *new DSU(id);
        
        // connecting components
        for(int i = 0; i < equations.size(); i++){
            dsu.unionSet(ids[equations[i].first], ids[equations[i].second], values[i]);
        }
        
        // inserting  -1 when some variable does not exist in our DSU or when both variables are not connected
        // Otherwise we insert the result of the division of the multipliers.
        for(auto& query : queries){
            if(ids.find(query.first) == ids.end() || ids.find(query.second) == ids.end()){
                answers.push_back(-1);
            }
            else{
                int x = ids[query.first];
                int y = ids[query.second];
                if(!dsu.isConnected(x, y)) answers.push_back(-1);
                else answers.push_back(dsu.find(x).second / dsu.find(y).second);
            }
        }
        
        return answers;
        
}
