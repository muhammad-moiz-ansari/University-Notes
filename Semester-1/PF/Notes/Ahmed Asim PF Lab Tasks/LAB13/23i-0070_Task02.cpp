#include <iostream>
using namespace std;

void removeDuplicates(int (arr)[], int size);

int main(){
cout<<"Ahmed Asim | 23i-0070 | BSCS-F\n";
int size;
cout<<"Enter the size of array : ";
cin>>size;
int arr[size];
cout<<"Enter the 'SORTED' elements of array\n";
for (int i=0;i<size;++i){
	cout<<i+1<<" : ";
	cin>>arr[i];
}
cout<<"\nOriginal Array : ";
for (int i=0;i<size;++i){
	cout<<arr[i]<<" ";
}
removeDuplicates(arr,size);
cout<<"\nUpdated Array : ";
int nul = arr[0]-2, i=0;
while (arr[i]!=nul&&i<size){
cout<<arr[i]<<" ";
i++;
}
cout<<endl;
return 0;
}

void removeDuplicates(int (arr)[], int size){
int nul = arr[0]-1,temp;
for (int i=0;i<size;++i){
	temp = arr[i];
	for (int j=i+1;j<size;++j){
		if (temp==arr[j]) arr[j]=nul;
	}
}
for (int i=0;i<size;++i){
	if (arr[i]==nul) {
		for (int j=i+1;j<size;j++){
			arr[j-1]=arr[j];
		}
		arr[size-1]=nul-1;
		i--;
	}
}
}
