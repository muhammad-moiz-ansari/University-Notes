#include <iostream>
using namespace std;

int main(){
cout<<"Ahmed Asim / 23i-0070 / BSCS-F"<<endl;
int n=-1,n2;
float sum=0;
bool flag = 1;
for(int z=-1000; z != n; --z){
	cout<<"Enter a positive number (or a negative number to exit) : ";
	cin>>n;
	if (n<0){
		cout<<"Program Ended.\n";
		z = n + 1;
		}
	else if (n==0) cout<<"Not Possible.\n";
	else if (n>0){
		sum = 0;
		n2=n;
		cout<<"series : ";
		for(int i = 1; i<=n; ++i){
			cout<<i<<" / "<<n2<<" ";
			if (i!=n) cout<<"+ ";
			sum += static_cast<float>(i)/n2;
			n2-=1;
		}
		cout<<endl<<"sum = "<<sum<<endl;
	}
}
return 0;
}
