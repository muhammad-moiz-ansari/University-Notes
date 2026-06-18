#include <iostream>
using namespace std;

int main(){
cout<<"Ahmed Asim / 23i-0070 / BSCS-F"<<endl;
int r;
cout<<"\e[1mFigure 1\e[0m\n";
cout<<"Enter the number of rows for upside-down triangle : ";
cin>>r;
cout<<endl;
int st = (r*2)-1;
for(int i = 0; i<r; ++i){
	for(int j = 1; j<=i;++j) cout<<' ';
	for(int j = 1; j<=st;++j) cout<<'*';
	st -=  2;
	cout<<endl;
}
cout<<endl;
cout<<"\e[1mFigure 2\e[0m\n";
do{
cout<<"Enter the number of rows (odd number): ";
cin>>r;
st = 1;
} while(r%2==0);
cout<<endl;
for(int i = (r-1)/2; i>=-(r-1)/2; --i){
	for(int j = 1; j<=(i<0?-i:i);++j) cout<<' ';
	for(int j = 1; j<=st;++j) cout<<'*';
  if(i<=0) st-=2;
  else st+=2;
  cout<<endl;
}
return 0;
}
