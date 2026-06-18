#include <iostream>
using namespace std;

int* mergeArrays(const int* arr1, int size1, const int* arr2, int size2);

int main(){
cout<<"Ahmed Asim | 23i-0070 | BSCS-F\n";
int size1, size2;
cout<<"Enter size of array 1 : ";
cin>>size1;
int * arr1 = new int [size1];
for (int i=0;i<size1;i++) {
	cout<<"Enter element "<<i+1<<" : ";
	cin>>*(arr1+i);
}
cout<<"Enter size of array 2 : ";
cin>>size2;
int * arr2 = new int [size2];
for (int i=0;i<size2;i++) {
	cout<<"Enter element "<<i+1<<" : ";
	cin>>*(arr2+i);
}

int * arr = mergeArrays(arr1,size1,arr2,size2);
cout<<"\nMerged Array is : \n";
for (int i=0;i<size1+size2;i++) cout<<"Element "<<i+1<<" : "<<*(arr+i)<<endl;
}

int* mergeArrays(const int* arr1, int size1, const int* arr2, int size2){
	int * mergearray = new int [size1+size2];
	for (int i=0;i<size1;i++){
		*(mergearray+i)=*(arr1+i);
	}
	for (int i=0;i<size2;i++){
		*(mergearray+i+size1)=*(arr2+i);
	}
	return mergearray;
}



