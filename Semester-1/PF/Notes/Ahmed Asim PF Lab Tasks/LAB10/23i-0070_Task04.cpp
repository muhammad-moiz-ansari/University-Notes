#include <iostream>
#include <ctime>
using namespace std;
int add(int n1,int n2);
int sub(int n1,int n2);
int mul(int n1,int n2);
float divi(int n1,int n2);
int main(){
int n1,n2,ch;
cout<<"Ahmed Asim | 23i-0070 | BSCS(F)\n";
cout<<"\e[1mWelcome To My Calculator\e[0m\n\n";
cout<<"Enter Your First Number: ";
cin>>n1;
cout<<"Enter Your Second Number: ";
cin>>n2;
cout<<"\n\n\e[1m\e[2mSelect an operation:\n1.Addtion \n2.Subtraction\n3.Mutiplication\n4.Division\n\n\e[0m\e[3mEnter the Number corresponding to your choise : ";
cin>>ch;
if (ch==1) cout<<"Result: "<<add(n1,n2);
else if (ch==2) cout<<"Result: "<<sub(n1,n2);
else if (ch==3) cout<<"Result: "<<mul(n1,n2);
else if (ch==4) {
	if (n2==0) cout<<"Number can't be divided by 0";
	else cout<<"Result: "<<divi(float(n1),float(n2));
	}
else cout<<"Invalid Input";
cout<<endl;
return 0;
}
int add(int n1,int n2) {return(n1+n2);}
int sub(int n1,int n2) {return(n1-n2);}
int mul(int n1,int n2) {return(n1*n2);}
float divi(int n1,int n2) {return(float(n1)/n2);}
