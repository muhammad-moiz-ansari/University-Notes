#include <iostream>
using namespace std;

void Spiral(int (arr)[4][4], int row, int col, int op_arr[]);

int main(){
cout<<"Ahmed Asim | 23i-0070 | BSCS-F\n";
int const row=4,col=4;
int arr[4][4];
cout<<"Enter the elements of Matrix\n";
for (int i=0;i<row;++i){
	cout<<"Element of row "<<i+1<<" : \n";
	for (int j=0;j<col;++j){
		cout<<"column "<<j+1<<" : ";
		cin>>arr[i][j];
	}
	cout<<endl;
}
cout<<"\nMatrix : \n";
for (int i=0;i<row;++i){
	for (int j=0;j<col;++j){
		cout<<arr[i][j]<<" ";
	}
	cout<<endl;
}
int op_arr[row*col];//op = output
Spiral(arr,row,col,op_arr);
cout<<"Output : ";
for (int i=0;i<row*col;i++) cout<<op_arr[i]<<" ";
cout<<endl;
return 0;
}

void Spiral(int (arr)[4][4], int row, int col, int op_arr[]){
int i=0,j=0,box_left=row/2, index=0;
//while (index<7){
//if(i<=col&&j==0){i++;op_arr[index]=arr[j][i];index++;}
//else if(i==col&&j<=row) {j++;op_arr[index]=arr[j][i];index++;}
//else if(i==col&&j==row)
//}

for (;i<col;i++) {op_arr[index]=arr[j][i];index++;} i--;
for (;j<row;j++) {op_arr[index]=arr[j][i];index++;} j--;
for (;i>=0;i--) {op_arr[index]=arr[j][i];index++;} i--;
for (;j>=1;j--) {op_arr[index]=arr[j][i];index++;} j--;
for (;i<col-1;i++) {op_arr[index]=arr[j][i];index++;} i--;
for (;j<row-1;j++) {op_arr[index]=arr[j][i];index++;} j--;
for (;i>=1;i--) {op_arr[index]=arr[j][i];index++;} i--;
}
