#include <iostream>
using namespace std;

void swap(int& a,int& b);

int main(){
cout<<"Ahmed Asim | 23i-0070 | BSCS-F\n";
int a, b;
cout<<"Enter a : ";cin>>a;
cout<<"Enter b : ";cin>>b;
swap(a,b);
cout<<"\nNew value of a is : "<<a<<endl;
cout<<"New value of b is : "<<b<<endl;
return 0;
}

void swap(int& a,int& b){
a = a^b;
b = a^b;
a = a^b;
}
