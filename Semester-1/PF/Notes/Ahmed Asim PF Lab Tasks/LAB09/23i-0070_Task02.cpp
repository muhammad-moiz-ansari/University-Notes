#include <iostream>
using namespace std;

int main(){
cout<<"Ahmed Asim / 23i-0070 / BSCS-F"<<endl;
int r;
cout<<"Enter the number of rows : ";
cin>>r;
int st=1;
cout<<"\e[1mButterfly pattern of "<<r<<" rows\e[0m\n";
for(int i = r; i>=-r; --i){
	for(int j = 1; j<=st;++j) cout<<'*';
	for(int j = 1; j<=(i<0?-i:i);++j) cout<<' ';
	for(int j = 1; j<=(i<0?-i:i);++j) cout<<' ';
	for(int j = 1; j<=st;++j) cout<<'*';
  if(i<=0) st-=1;
  else st+=1;
  cout<<endl;
}
return 0;
}
