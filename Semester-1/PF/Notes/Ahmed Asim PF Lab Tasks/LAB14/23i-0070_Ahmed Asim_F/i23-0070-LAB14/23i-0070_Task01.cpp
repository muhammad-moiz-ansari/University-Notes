#include <iostream>
using namespace std;

int const COLS = 4;
bool IsMatrixUpperTriangular( int [][COLS] , int );


int main(){
cout<<"Ahmed Asim | 23i-0070 | BSCS-F\n";
int rows=4,col=4;
int arr[rows][COLS];
cout<<"Enter data in matrix : \n";
for (int i=0;i<COLS;i++){
	for (int j=0;j<rows;j++){
		cout<<"("<<i+1<<','<<j+1<<") : ";
		cin>>arr[j][i];
	}	
}
bool ut_matrix;
ut_matrix = IsMatrixUpperTriangular( arr ,rows );
if (ut_matrix) cout<<"Matrix is upper triangular\n";
else cout<<"Matrix is not upper triangular\n";
return 0;
}

bool IsMatrixUpperTriangular( int arr [][COLS] , int rows){
for (int i=0;i<COLS;i++){
	for (int j=0;j<rows;j++){
		if (j<i) {if(arr[j][i]!=0) return false;}
	}
}
return true;
}
