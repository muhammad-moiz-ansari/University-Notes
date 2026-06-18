#include <iostream>
using namespace std;

int const COLS = 5;
void csort( int arr[][COLS] , int rows);


int main(){
cout<<"Ahmed Asim | 23i-0070 | BSCS-F\n";
int rows=5;
int arr[rows][COLS];
cout<<"Enter data in 2D Array : \n";
for (int i=0;i<COLS;i++){
	for (int j=0;j<rows;j++){
		cout<<"("<<i+1<<','<<j+1<<") : ";
		cin>>arr[j][i];
	}	
}
cout<<"\nOrignal 2D Array :- \n";
for (int i=0;i<COLS;i++){
	for (int j=0;j<rows;j++){
		cout<<arr[j][i]<<" ";
	}
	cout<<endl;
}
csort(arr,rows);
cout<<"2D Array after sorting :- \n";
for (int i=0;i<COLS;i++){
	for (int j=0;j<rows;j++){
		cout<<arr[j][i]<<" ";
	}
	cout<<endl;
}
return 0;
}

void csort( int arr[][COLS] , int rows){
bool array_sorted=0;
for (int i=0;i<rows;i++){
	for (int j=0;j<COLS;j++){
		array_sorted=0;
		for (int k=0;k<COLS-1;k++){
			if (arr[i][k]>=arr[i][k+1]){
				arr[i][k]=arr[i][k]^arr[i][k+1];
				arr[i][k+1]=arr[i][k]^arr[i][k+1];
				arr[i][k]=arr[i][k]^arr[i][k+1];
				array_sorted=1;
			}
		}
	}
}}



