#include <iostream>
using namespace std;

int main(){
	unsigned int n, fac=1;
while (1){
	cout<<"Enter a positive integer : ";
	cin>>n;
	if (n==0){
		cout<<"Factorial of 0 = 1"<<endl;
	break;
	}
	else if (n>0){
	    int n2 = n;
		while (n>0){
		fac *= n;
		n -= 1;
		}
		if (fac==0) cout<<"Over flow\n";
		else cout<<"Factorial of "<<n2<<" = "<<fac<<endl;	
	break;
	}
}
return 0;
}
