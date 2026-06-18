#include <iostream>
#include <ctime>
using namespace std;

int main(){
cout<<"Ahmed Asim | 23i-0070 | BSCS-F\n";
int m1,n1,m2,n2;
cout<<"Enter the number of rows (m) and columns (n) for the first matrix : \nm1 = ";
cin>>m1;
cout<<"n1 = ";
cin>>n1;
cout<<"Enter the number of rows (m) and columns (n) for the second matrix : \nm2 = ";
cin>>m2;
cout<<"n2 = ";
cin>>n2;
if (n1!=m2) cout<<"\nMultiplication not possible\n";
else{
	int mat1[m1][n1],mat2[m2][n2];
	cout<<"\nEnter the elements of first matrix ("<<m1<<','<<n1<<") :\n";
	for(int i=0;i<m1;++i) {
		for(int j=0;j<n1;++j){
			cout<<"Enter element at position ("<<i+1<<','<<j+1<<") : ";
			cin>>mat1[i][j];	
		}
	}	
	cout<<"\nEnter the elements of second matrix ("<<m2<<','<<n2<<") :\n";
	for(int i=0;i<m2;++i) {
		for(int j=0;j<n2;++j){
			cout<<"Enter element at position ("<<i+1<<','<<j+1<<") : ";
			cin>>mat1[i][j];	
		}
	}
	int arr[m1][n2];
	for(int i=0;i<m1;++i) {
		for(int j=0;j<n2;++j){
			arr[i][j]=mat1[i][j]*mat1[i][j]+mat1[i][j]*mat1[i][j+1]
		}
	}
}
return 0;
}
