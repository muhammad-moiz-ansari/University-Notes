#include <iostream>
using namespace std;

int main(){
cout<<"Ahmed Asim | 23i-0070 | BSCS-F\n";
int size,p=0,n=0,o=0,e=0;
cout<<"Enter size of array : ";
cin>>size;
int * arr = new int [size];
for (int i=0;i<size;i++) {
	cout<<"Enter element "<<i+1<<" : ";
	cin>>*(arr+i);
}
for (int i=0;i<size;i++){
	if (*(arr+i)<0) n++; else p++;
	if (*(arr+i)%2==0) e++; else o++;
}

cout<<"\nNumber of Negative numbers are "<<n;
cout<<"\nNumber of Positive numbers are "<<p;
cout<<"\nNumber of Even numbers are "<<e;
cout<<"\nNumber of odd numbers are "<<o;
cout<<endl;
return 0;
}
