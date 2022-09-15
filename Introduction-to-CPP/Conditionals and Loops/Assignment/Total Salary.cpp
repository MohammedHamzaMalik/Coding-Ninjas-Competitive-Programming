#include<iostream>
using namespace std;

int main() {
	// Write your code here
	double s;
    char g;
    cin>>s>>g;
    double hra =s*20/100;   
	double da=s*50/100;
    int allow=0;
    if(g=='A')
		allow=1700;
    else if(g=='B')
        allow=1500;
    else if(g>='C' && g<='Z')
        allow=1300;
    double pf=s*11/100;
    double Salary= (double)s+hra+da+allow-pf;
    double totalSalary=Salary-(int)Salary;
    if(totalSalary<0.5)
       // System.out.println((int)Salary);
        cout<<(int)Salary<<endl;
    else 
       // System.out.println((int)Salary+1);
        cout<<(int)Salary+1<<endl;
}
