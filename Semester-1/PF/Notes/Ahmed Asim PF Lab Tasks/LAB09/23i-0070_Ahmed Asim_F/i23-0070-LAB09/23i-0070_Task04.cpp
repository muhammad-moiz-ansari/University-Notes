#include <iostream>
using namespace std;

int main(){
cout<<"Ahmed Asim / 23i-0070 / BSCS-F"<<endl;
cout<<"Palindromic prime numbers between 100 and 999 are : \n";
int n=100,i=2;
bool pprime = 1;
while(n<1000){
	while(i<n){
		if (n%i==0) pprime = 0;
		if (n/100!=n%10) pprime = 0;
		i++;
	}
	if (pprime==1) cout<<n<<" ";
	i = 2;
	pprime = true;
	n +=1;
}
cout<<endl;
return 0;
}
