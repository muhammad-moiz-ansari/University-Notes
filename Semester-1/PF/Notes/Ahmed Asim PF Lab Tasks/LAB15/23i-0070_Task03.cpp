#include <iostream>
using namespace std;

void combinations(char *arr, int size);

int main(){
cout<<"Ahmed Asim | 23i-0070 | BSCS-F\n";
int size;
cout<<"Enter size of string : ";
cin>>size;
char * arr = new char [size];
cout<<"Enter String : ";
for (int i=0;i<size;i++) cin>>*(arr+i);
combinations(arr,size);
cout<<endl;
return 0;
}

void combinations(char *arr, int size){
cout<<"\nString is : ";
	for (int i=0;i<size;i++) cout<<*(arr+i);
	char *ptr = arr;
	//Combination 1 ---------------------------
	*ptr = *ptr ^ *(ptr+1);
	*(ptr+1) = *ptr ^ *(ptr+1);
	*ptr = *ptr ^ *(ptr+1);
	cout<<"\n1st Combination : ";
	for (int i=0;i<size;i++) cout<<*(arr+i);
	//Combination 1 ---------------------------
	ptr += 2; 
	*ptr = *ptr ^ *(ptr+1);
	*(ptr+1) = *ptr ^ *(ptr+1);
	*ptr = *ptr ^ *(ptr+1);
	cout<<"\n2nd Combination : ";
	for (int i=0;i<size;i++) cout<<*(arr+i);
}



