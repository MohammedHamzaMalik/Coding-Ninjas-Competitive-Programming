/*
Convex Hull
Send Feedback
You are given N points in a 2-D plane and you have to find the convex hull using the most optimized approach.
Input Format:
First line of input will contain T(number of test cases), each test case follows as.
Line 1: contain an integer N denoting the number of points in the 2-D plane.
Next N lines denoting the N points in the 2-D Plane
Constraints:
1 <= T <= 10
1 <= N <= 10^5
-10^5 <= x, y <= 10^5
Output Format:
For each test case print the convex hull points (order of points doesn't matter)
Sample Input 1:
1
5
4 6
2 6
3 0
1 2
2 3
Sample Output 1:
1 2
2 6
4 6
3 0
*/



#include<bits/stdc++.h>
using namespace std;
pair<int, int> mid;

// Function to find the quadrant where the point p lies
int quad(pair<int, int> p)
{
    if (p.first >= 0 && p.second >= 0){
        return 1;
    }
    if (p.first <= 0 && p.second >= 0){
        return 2;
    }
    if (p.first <= 0 && p.second <= 0){
        return 3;
    }
    else{
        return 4;
    }
}

// Function to check whether the line is crossing the polygon or not
int orient(pair<int, int> a, pair<int, int> b, pair<int, int> c)
{
    int r = (b.second-a.second)*(c.first-b.first) - (c.second-b.second)*(b.first-a.first);
    if (r == 0){
        return 0;
    }
    if (r > 0){
        return 1;
    }
    else{
        return -1;
    }
}

// Sorting of the points in Brute Force solution is dont using this function
bool mycompare(pair<int, int> point1, pair<int, int> point2)
{
    pair<int, int> p = make_pair(point1.first - mid.first, point1.second - mid.second);
    pair<int, int> q = make_pair(point2.first - mid.first, point2.second - mid.second);
    
    int o = quad(p);
    int t = quad(q);
    
    if (o != t){
        return (o < t);
    }
    
    return (p.second*q.first < q.second*p.first);
}

// Finds upper tangent of two polygons 'c1' and 'c2' represented as two vectors.
vector<pair<int, int>> merger(vector<pair<int, int> > c1, vector<pair<int, int> > c2)
{
    
    int n1 = c1.size(), n2 = c2.size();
    int ia = 0, ib = 0;
    for (int i=1; i<n1; i++){
        if (c1[i].first > c1[ia].first){
            ia = i;
        }
    }
    
    // ib -> leftmost point of b
    for (int i=1; i<n2; i++){
        if (c2[i].first < c2[ib].first){
            ib=i;
        }
    }
    // finding the upper tangent
    int inda = ia, indb = ib;
    bool done = 0;
    while (!done)
    {
        done = 1;
        while (orient(c2[indb], c1[inda], c1[(inda+1)%n1]) >=0)
            inda = (inda + 1) % n1;
        while (orient(c1[inda], c2[indb], c2[(n2+indb-1)%n2]) <=0)
        {
            indb = (n2+indb-1)%n2;
            done = 0;
        }
    }
    int uppera = inda, upperb = indb;
    
    //finding the lower tangent
    inda = ia, indb=ib;
    done = 0;
    int g = 0;
    while (!done)
    {
        done = 1;
        while (orient(c1[inda], c2[indb], c2[(indb+1)%n2])>=0)
            indb=(indb+1)%n2;
        while (orient(c2[indb], c1[inda], c1[(n1+inda-1)%n1])<=0)
        {
            inda=(n1+inda-1)%n1;
            done=0;
        }
    }
    int lowera = inda, lowerb = indb;
    vector<pair<int, int>> ret;
    int ind = uppera;
    ret.push_back(c1[uppera]);
    while (ind != lowera)
    {
        ind = (ind+1)%n1;
        ret.push_back(c1[ind]);
    }
    ind = lowerb;
    ret.push_back(c2[lowerb]);
    while (ind != upperb)
    {
        ind = (ind+1)%n2;
        ret.push_back(c2[ind]);
    }
    return ret;
}

// Brute force algorithm to find convex hull for a set of less than 6 points
vector<pair<int, int>> bruteHull(vector<pair<int, int>> c)
{
    set<pair<int, int> >s;
    for (int i=0; i<c.size(); i++)
    {
        for (int j=i+1; j<c.size(); j++)
        {
            int x1 = c[i].first, x2 = c[j].first;
            int y1 = c[i].second, y2 = c[j].second;
            int a1 = y1-y2;
            int b1 = x2-x1;
            int c1 = x1*y2-y1*x2;
            int pos = 0, neg = 0;
            for (int k=0; k<c.size(); k++)
            {
                if (a1*c[k].first+b1*c[k].second+c1 <= 0){
                    neg++;
                }
                if (a1*c[k].first+b1*c[k].second+c1 >= 0){
                    pos++;
                }
            }
            if (pos == c.size() || neg == c.size())
            {
                s.insert(c[i]);
                s.insert(c[j]);
            }
        }
    }
    vector<pair<int, int>>ret;
    for (auto e:s){
        ret.push_back(e);
    }
    
    mid = {0, 0};
    int n = ret.size();
    for (int i=0; i<n; i++)
    {
        mid.first += ret[i].first;
        mid.second += ret[i].second;
        ret[i].first *= n;
        ret[i].second *= n;
    }
    sort(ret.begin(), ret.end(), mycompare);
    for (int i=0; i<n; i++){
        ret[i] = make_pair(ret[i].first/n, ret[i].second/n);
    }
    
    return ret;
}

// Function to find the convex hull for a set of points
vector<pair<int, int>> divide(vector<pair<int, int>> a)
{
    
    if (a.size() <= 5){
        return bruteHull(a);
    }
        
    vector<pair<int, int>> left, right;
    
    for (int i=0; i<a.size()/2; i++){
        left.push_back(a[i]);
    }
    for (int i=a.size()/2; i<a.size(); i++){
        right.push_back(a[i]);
    }
    
    // Finding convex hull for the left and right sets
    vector<pair<int, int>> left_convex_hull = divide(left);
    vector<pair<int, int>> right_convex_hull = divide(right);
    
    // Merging the convex hulls to get the final result
    return merger(left_convex_hull, right_convex_hull);
}

int main()
{
    int t;cin>>t;while(t--){
        vector<pair<int, int> > a;
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        int x, y; 
        cin>>x;
        cin>>y;
        a.push_back(make_pair(x, y));
    }
    
    // sorting the set of points according to the x-coordinate  
    sort(a.begin(), a.end());
    vector<pair<int, int>> ans = divide(a);
    // cout << "The points in the convex hull are:\n";
    for (auto e:ans)
      cout << e.first << " "
            << e.second << endl;
    }
    return 0;
}
