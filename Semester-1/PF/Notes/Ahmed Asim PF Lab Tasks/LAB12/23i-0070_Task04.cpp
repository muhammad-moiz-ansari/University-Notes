#include <iostream>
#include <ctime>
using namespace std;

int main(){
cout<<"Ahmed Asim | 23i-0070 | BSCS-F\n";
int row,col,val;
bool done=false;
cout<<"Enter the number of rows : ";
cin>>row;
cout<<"Enter the number of columns : ";
cin>>col;
int arr[row][col];
cout<<"\n\e[2mEnter the matrix elements :- \e[0m";
for(int i=0;i<row;++i) {
	cout<<"\nEnter elements of row "<<i+1<<" : \n";
	for(int j=0;j<col;++j) cin>>arr[i][j];
}
cout<<"\nEnter value you want to find : ";
cin>>val;
cout<<"\n";
for(int i=0;i<row;++i) {
	for(int j=0;j<col;++j){
		if(val==arr[i][j]) {
		cout<<"The value "<<val<<" is found at position ("<<i+1<<","<<j+1<<") \n";
		done = true;}
	}
}
if(done==false) cout<<"The value "<<val<<" is not present in Matrix\n";
return 0;
}
