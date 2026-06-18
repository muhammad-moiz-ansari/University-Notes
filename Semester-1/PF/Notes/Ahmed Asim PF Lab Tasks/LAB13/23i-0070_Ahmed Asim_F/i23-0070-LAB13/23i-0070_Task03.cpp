#include <iostream>
using namespace std;

void transpose(int (tarr)[2][3], int trow, int tcol, int (&arr)[3][2]);

int main(){
cout<<"Ahmed Asim | 23i-0070 | BSCS-F\n";
int row=3,col=2;
int arr[3][2];
cout<<"Enter the elements of Matrix\n";
for (int i=0;i<row;++i){
	cout<<"element of row "<<i+1<<" : \n";
	for (int j=0;j<col;++j){
		cout<<"column "<<j+1<<" : ";
		cin>>arr[i][j];
	}
}
cout<<"\nOriginal Matrix : \n";
for (int i=0;i<row;++i){
	for (int j=0;j<col;++j){
		cout<<arr[i][j]<<" ";
	}
	cout<<endl;
}
int const trow=2,tcol=3;
int tarr[2][3];
transpose(tarr,trow,tcol,arr);
cout<<"\nTranspose Matrix : \n";
for (int i=0;i<trow;++i){
	for (int j=0;j<tcol;++j){
		cout<<tarr[i][j]<<" ";
	}
	cout<<endl;
}
return 0;
}

void transpose(int (tarr)[2][3], int trow, int tcol, int (&arr)[3][2]){
for (int i=0;i<trow;i++){
	for (int j=0;j<tcol;j++){
		tarr[i][j]=arr[j][i];
	}
}
}
