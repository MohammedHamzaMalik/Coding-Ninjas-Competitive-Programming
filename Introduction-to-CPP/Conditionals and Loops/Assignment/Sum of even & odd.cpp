#include<iostream>
using namespace std;

int main() {
	// Write your code here
	int num;
    cin>>num;
        int temp=num;
        int sum1=0;
        int sum2=0;
        while(temp!=0)
        {
            int rem=temp%10;
            if(rem%2==0)
            {
                sum1=sum1+rem;
                
            }
          
            if(rem%2!=0)
            {
                sum2=sum2+rem;
               
                
            } 
            // System.out.println(sum2);
            temp=temp/10;
                
                    
        }
        //   System.out.println(sum1+" "+sum2);
    cout<<sum1<<" "<<sum2<<endl;

}
