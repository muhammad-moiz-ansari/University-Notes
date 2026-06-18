#include <iostream>
using namespace std;

void decreaseSort(int (arr)[], int size);

int main(){
cout<<"Ahmed Asim | 23i-0070 | BSCS-F\n";
int size;
cout<<"Enter the size of array : ";
cin>>size;
int arr[size];
cout<<"Enter the elements of array\n";
for (int i=0;i<size;++i){
	cout<<i+1<<" : ";
	cin>>arr[i];
}
cout<<"\nOriginal Array : ";
for (int i=0;i<size;++i){
	cout<<arr[i]<<" ";
}
cout<<"\n";
decreaseSort(arr,size);
cout<<"Sorted Array : ";
for (int i=0;i<size;++i){
	cout<<arr[i]<<" ";
}
cout<<"\n";
return 0;
}

void decreaseSort(int (arr)[], int size){
int j=size-1,temp;
bool flag;
for (int i=0;i<size;++i){
	flag = true;
	for (int k=0;k<j;++k){
		if(arr[k]<arr[k+1]){
			temp = arr[k];
			arr[k] = arr[k+1];
			arr[k+1] = temp;
			flag = false;
		}
	}
	if (flag==true) break;
	j--;
}
}
