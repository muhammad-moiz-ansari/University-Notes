#include <iostream>
using namespace std;

int main(){
cout<<"Ahmed Asim | 23i-0070 | BSCS(F)\n";

int aN,a=0,b=1,i=2,c;
cout<<"Enter the Number of elements : "<<endl;
cin>>aN;
if (aN<=0){
	cout<<"Invalid Number Entered"<<endl;
	return 0;
}
else{
	cout<<a<<" ";
	if (aN==1){
		cout<<endl;
		return 0;
	}
	else {
		cout<<b<<" ";
		while (i<aN){
		c = a + b;
		a = b;
		b = c;
		cout<<c<<" ";
		i++;
		}
	}
}
cout<<"\n";
return 0;
}
