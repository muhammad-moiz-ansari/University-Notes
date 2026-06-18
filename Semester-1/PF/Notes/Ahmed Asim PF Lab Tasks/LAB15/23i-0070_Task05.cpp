#include <iostream>
using namespace std;

void countvow(char *arr,int size,int* ptrv,int* ptrc);

int main(){
cout<<"Ahmed Asim | 23i-0070 | BSCS-F\n";
int size,v=0,c=0;
cout<<"Enter size of string : ";
cin>>size;
char * arr = new char [size];
cout<<"Enter String : ";
for (int i=0;i<size;i++) cin>>*(arr+i);
int* ptrv=&v;
int* ptrc=&c;
countvow(arr,size,ptrv,ptrc);
cout<<"\nNumber of vowels: "<<v;
cout<<"\nNumber of consonants: "<<c<<endl;
return 0;
}

void countvow(char *arr,int size,int* ptrv,int* ptrc){
	for (int i=0;i<size;i++){
		if (*(arr+i)=='a'||*(arr+i)=='e'||*(arr+i)=='i'||*(arr+i)=='o'||*(arr+i)=='u') (*ptrv)+=1;	
		else (*ptrc)+=1;
	}
}
