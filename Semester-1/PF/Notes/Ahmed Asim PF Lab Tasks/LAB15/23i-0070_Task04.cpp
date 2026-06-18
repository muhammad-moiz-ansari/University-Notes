#include <iostream>
using namespace std;

int* reverseArray(int* arr, int size);

int main(){
cout<<"Ahmed Asim | 23i-0070 | BSCS-F\n";
int size;
cout<<"Enter size of array : ";
cin>>size;
int * arr = new int [size];
for (int i=0;i<size;i++) {
	cout<<"Enter element "<<i+1<<" : ";
	cin>>*(arr+i);
}
arr = reverseArray(arr,size);
cout<<"\nReverse Array is : \n";
for (int i=0;i<size;i++) cout<<"Element "<<i+1<<" : "<<*(arr+i)<<endl;
return 0;
}

int* reverseArray(int* arr, int size) {
	int* revarr = new int [size];
	// Reverse the order of array elements
	for (int i=0;i<size;i++){
	*(revarr+size-1-i)=*(arr+i);
	}
	delete [] arr;
	return revarr;
}




