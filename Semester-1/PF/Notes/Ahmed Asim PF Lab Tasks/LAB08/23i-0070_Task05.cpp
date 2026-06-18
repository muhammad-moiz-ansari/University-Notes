#include <iostream>
using namespace std;

int main(){
cout<<"Ahmed Asim | 23i-0070 | BSCS(F)\n";
int n,i=2;
bool prime = true;
cout<<"Enter the Number : ";
cin>>n;
while (n>=0){
	while(i<n){
		if (n%i==0) prime = false;
		i++;
	}
	if (prime==false) cout<<"The number you entered is not prime.\n";
	else cout<<"the number you entered is prime.\n";
	i = 2;
	prime = true;
	cout<<"Enter the Number : ";
	cin>>n;	
}
return 0;
}
