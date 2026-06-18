#include <iostream>
using namespace std;

int main(){
cout<<"Ahmed Asim | 23i-0070 | BSCS-F\n";
int size1, size2;
cout<<"Enter size of string 1 : ";
cin>>size1;
char * arr1 = new char [size1];
cout<<"Enter String 1 : ";
cin.ignore();
cin.getline(arr1,size1+1);
cout<<"Enter size of string 2 : ";
cin>>size2;
char * arr2 = new char [size2];
cout<<"Enter String 2 : ";
for (int i=0;i<size2;i++) cin>>*(arr2+i);

cout<<"\nstring 1 is : ";
for (int i=0;i<size1;i++) cout<<*(arr1+i);
cout<<"\nstring 2 is : ";
for (int i=0;i<size2;i++) cout<<*(arr2+i);

char * resultarr = new char [size1+size2];
for (int i=0;i<size1;i++) *(resultarr+i)=*(arr1+i);
for (int i=0;i<size2;i++) *(resultarr+i+size1)=*(arr2+i);

cout<<"\nResultant array is : ";
for (int i=0;i<size1+size2;i++) cout<<*(resultarr+i);
cout<<endl;
return 0;
}
