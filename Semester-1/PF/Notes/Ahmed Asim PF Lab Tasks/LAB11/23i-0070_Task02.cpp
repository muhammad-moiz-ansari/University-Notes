#include <iostream>
using namespace std;

bool perfect(int n);

int main(){
cout<<"Ahmed Asim | 23i-0070 | BSCS(F)\n";
cout<<"Perfect number between 1 and 1000 :-\n";
bool temp;
for (int i=1; i<=1000; ++i){
	temp = perfect(i);
	if (temp==1) cout<<i<<" is a perfect number\n";
}
return 0;
}

bool perfect(int n){
	int sum=0;
	if (n==1) sum=1; else
	for (int i = 1; i<=(n/2); ++i) if(n%i==0) sum+=i;
	return (sum==n);
}
