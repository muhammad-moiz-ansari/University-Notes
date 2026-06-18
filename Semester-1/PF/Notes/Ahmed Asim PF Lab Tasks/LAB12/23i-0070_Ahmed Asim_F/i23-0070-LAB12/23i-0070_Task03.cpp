#include <iostream>
#include <ctime>
using namespace std;

int main(){
cout<<"Ahmed Asim | 23i-0070 | BSCS-F\n";
const int size = 5;
bool done=0;
int temp,high=-1,sec_high=-2,index_of_high;
int arr[size]={0};
cout<<"Enter 5 numbers in array : \n";
for (int i=0;i<size;++i) {
	do{	
		cin>>temp;
		if (temp<0) cout<<"Values should not be negative, Enter THIS value again : ";
		for(int j=0;j<i;++j) if(arr[j]==temp) {cout<<"Values should be unique, Enter THIS value again : ";temp=-1;}
	}while (temp<0);
	arr[i]=temp;
	if(temp>high) {sec_high=high;high=temp;index_of_high=i;}
	if(temp>sec_high&&temp<high) sec_high=temp;
}
int arr2[size+1];
for (int i=0;i<size+1;++i){
	if (i!=index_of_high) {
		if(done==0) arr2[i]=arr[i];
		else {arr2[i]=arr[i-1];}
	}
	else{
		done=1;
		arr2[i]=high-sec_high;
		++i;
		arr2[i]=sec_high;
	}
}
cout<<"\nBefore split : ";
for (int i=0;i<size;++i) cout<<arr[i]<<" ";
cout<<"\nAfter split : ";
for (int i=0;i<size+1;++i) cout<<arr2[i]<<" ";
cout<<"\n";
return 0;
}
