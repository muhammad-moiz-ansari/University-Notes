#include <iostream>
using namespace std;
int main(){
cout<<"Ahmed Asim | 23i-0070 | BSCS(F)\n";
int n,i=0;
bool stop=false;
cout<<"Enter the size : ";
cin>>n;
while(i>=0){
	for(int j = (n-1); j>-n; --j){
		if ((j>=0?j:-j)==i) cout<<"*";
		else cout<<" ";}
	if(i<(n-1)&&!stop) i+=1;
	else {stop=true;i-=1; }
	cout<<endl; }
return 0; }
