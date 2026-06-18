#include <iostream>
using namespace std;
int computeMax(int num1, int num2, int num3);
int main(){
int n1,n2,n3;
cout<<"Ahmed Asim | 23i-0070 | BSCS(F)\n";
cout<<"Enter Your first number: ";
cin>>n1;
cout<<"Enter Your second number: ";
cin>>n2;
cout<<"Enter Your third number: ";
cin>>n3;
cout<<"The Max Number is "<<computeMax(n1,n2,n3)<<endl;
return 0;
}
int computeMax(int a, int b, int c) {
int max;
if(a>=b){
	if(a>=c) max=a;
	else max=c;
}
else{
	if(b>=c) max=b;
	else max=c;	
}
return max;
}
