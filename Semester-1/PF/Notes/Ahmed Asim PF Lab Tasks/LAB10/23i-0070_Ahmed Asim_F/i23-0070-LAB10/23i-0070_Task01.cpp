#include <iostream>
using namespace std;

int main(){
cout<<"Ahmed Asim | 23i-0070 | BSCS(F)\n";

int aN,a,b,i,c;
do {
	cout<<"Enter the limit : ";
	cin>>aN;
	if (aN<=0) cout<<"Invalid Number Entered"<<endl;
} while (aN<=0);
for(int k=1; k<=aN; ++k){
	i=2;a=1;b=1;
		cout<<a<<"\t";
		if (aN==1){
			break;
		}
		else {
			if (k!=1) cout<<b<<"\t";
			while (i<k){
			c = a + b;
			a = b;
			b = c;
			cout<<c<<"\t";
			i++;
			}
		}
	
	cout<<"\n";
}
return 0;
}
